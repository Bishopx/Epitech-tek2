/*
** cmd_get.c for cmd_get in /home/ploujo_c/tek2/unix/PSU_2015_myftp/bonus
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@ploujo-HP-EliteBook-840-G1>
** 
** Started on  Sat May 14 19:50:51 2016 Christophe Ploujoux
** Last update Sun May 15 01:49:09 2016 Christophe Ploujoux
*/

#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "client.h"

void	retr(t_server *server, int fd, int i)
{
  char	str[10];
  char	*check;
  int	buffer;

  my_putstr(server->sock, "RETR ");
  my_putstr(server->sock, server->cmd[i]);
  my_putstr(server->sock, CRLF);
  printf("%s\n",(check = get_next_line(server->sock)));
  if (read_code(check) == 550)
    return;
  while ((buffer = read(server->transfert.socket, str, 10)) > 0)
    write(fd, str, buffer);
  printf("%s\n", get_next_line(server->sock));
}

void	cmd_get(t_server *server)
{
  int	fd;

  if (!server->cmd[1])
    printf("Indicate a file from the server\n");
  else
    {
      if ((fd = creat((!server->cmd[2] ? server->cmd[1] : server->cmd[2]),
		      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
     	{
	  printf("local: %s: No such file or directory\n",
		 (!server->cmd[2] ? server->cmd[1] : server->cmd[2]));
	  return;
     	}
      connect_data(server);
      retr(server, fd, 1);
    }
}

void	cmd_mget(t_server *server)
{
  int	fd;
  int	i;

  if (!server->cmd[1])
    printf("Indicate a file from the server\n");
  else
    {
      i = 1;
      while (server->cmd[i])
	{
	  if ((fd = creat(server->cmd[i],
			  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	    {
	      printf("local: %s: No such file or directory\n", server->cmd[i]);
	      return;
	    }
	  connect_data(server);
	  retr(server, fd, i);
	  close(fd);
	  i++;
	}
    }
}
