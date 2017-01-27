/*
** cmd_data.c for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/srcs
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Thu May	12 19:37:37 2016 Christophe Ploujoux
** Last update	Thu May	12 19:37:37 2016 Christophe Ploujoux
*/

#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "server.h"

void	cmd_retr(t_client *client)
{
  int	fd;
  int	buffer;
  char	str[10];

  if (client->transfert.transfert == 2)
    xconnect(client->transfert.socket,
	     (struct sockaddr *)&client->transfert.addr,
	     sizeof(client->transfert.addr));
  if (client->cmd[1])
    {
      if ((fd = open(client->cmd[1], O_RDONLY)) == -1)
	{
	  my_putstr(client->sock, "550 Failed to open file");
	  return;
	}
      my_putstr(client->sock, "150 Opening ASCII mode data connection");
      while ((buffer = read(fd, str, 10)) > 0)
	write(client->transfert.socket, str, buffer);
      my_putstr(client->sock, "226 Transfer complete.");
      close(fd);
      close(client->transfert.socket);
      init_transfert(client);
    }
  else
    my_putstr(client->sock, "550 Failed to open file");
}

void	cmd_store(t_client *client)
{
  int	fd;
  char	str[10];
  int	buffer;

  if (client->transfert.transfert == 2)
    xconnect(client->transfert.socket,
	     (struct sockaddr *)&client->transfert.addr,
	     sizeof(client->transfert.addr));
  if (client->cmd[1])
    {
      if ((fd = creat(client->cmd[1],
		      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	return;
      my_putstr(client->sock, "150 Opening ASCII mode data connection");
      while ((buffer = read(client->transfert.socket, str, 10)) > 0)
	write(fd, str, buffer);
      my_putstr(client->sock, "226 Transfer complete.");
      close(fd);
      close(client->transfert.socket);
      init_transfert(client);
    }
}

void	cmd_list(t_client *client)
{
  int	size;
  FILE	*in;
  char	tmp[256];
  int	i;

  if (client->transfert.transfert == 2)
    xconnect(client->transfert.socket,
	     (struct sockaddr *)&client->transfert.addr,
	     sizeof(client->transfert.addr));
  my_putstr(client->sock, "150 Here comes the directory listing.");
  in = popen("ls -l -a | wc -l", "r");
  fgets(tmp, 255, in);
  size = atoi(tmp);
  in = popen("ls -l -a", "r");
  i = 0;
  while (i < size) {
    fgets(tmp, 255, in);
    if (i != 0)
      write(client->transfert.socket, tmp, strlen(tmp));
    i++;
  }
  my_putstr(client->sock, "226 Directory send OK.");
  client = client;
  close(client->transfert.socket);
  init_transfert(client);
}
