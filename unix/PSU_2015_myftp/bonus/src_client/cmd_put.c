/*
** cmd_put.c for cmd_put in /home/ploujo_c/tek2/unix/PSU_2015_myftp/bonus
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@ploujo-HP-EliteBook-840-G1>
** 
** Started on  Sat May 14 19:50:17 2016 Christophe Ploujoux
** Last update Sun May 15 01:50:40 2016 Christophe Ploujoux
*/

#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "client.h"

void	stor(t_server *server, int fd, int i)
{
  char	str[10];
  char	*check;
  int	buffer;

  my_putstr(server->sock, "STOR ");
  my_putstr(server->sock, server->cmd[i]);
  my_putstr(server->sock, CRLF);
  printf("%s\n",(check = get_next_line(server->sock)));
  if (read_code(check) == 550)
    return;
  while ((buffer = read(fd, str, 10)) > 0)
    write(server->transfert.socket, str, buffer);
  close(fd);
  close(server->transfert.socket);
  printf("%s\n", get_next_line(server->sock));
}

void	cmd_put(t_server *server)
{
  int	fd;

  if (!server->cmd[1])
    printf("Indicate a file to upload\n");
  else
    {
      if ((fd = open(server->cmd[1], O_RDONLY)) == -1)
     	{
	  printf("local: %s: No such file or directory\n", server->cmd[1]);
	  return;
     	}
      connect_data(server);
      stor(server, fd, 1);
    }
}

void	cmd_mput(t_server *server)
{
  int	fd;
  int	i;

  if (!server->cmd[1])
    printf("Indicate a file from the server\n");
  else {
    i = 1;
    while (server->cmd[i])
      {
	if (!server->cmd[1])
	  printf("Indicate a file to upload\n");
	else
	  {
	    if ((fd = open(server->cmd[i], O_RDONLY)) == -1)
	      {
		printf("local: %s: No such file or directory\n",
		       server->cmd[i]);
		return;
	      }
	    connect_data(server);
	    stor(server, fd, i);
	  }
	i++;
      }
  }
}
