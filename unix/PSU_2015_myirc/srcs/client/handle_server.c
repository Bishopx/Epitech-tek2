/*
** handle_server.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/client
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on Tue May 17 16:14:00 2016 Christophe Ploujoux
** Last update Fri Jun  3 23:01:24 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include "client.h"

void		prompt(t_server *server)
{
  write(1, "<irc des Bo", strlen("<irc des Bo"));
  if (server->status == 1 && server->ip)
    {
      write(1, " ", 1);
      write(1, server->ip, strlen(server->ip));
    }
  write(1, "> ", 1);
}

void		execute(t_server *server)
{
  int		i;
  void		(*command[10])(t_server *);

  init_cmd(command);
  server->cmd = split_cmd(get_next_line(1), " \r\n");
  if (!server->cmd)
    return;
  i = 0;
  while (server->cmd_list[i])
    {
      if (strcmp(server->cmd_list[i], server->cmd[0]) == 0)
	{
	  command[i](server);
	  return;
	}
      i++;
    }
  printf("Command not found\n");
}

void		init_fd(t_server *server)
{
  FD_ZERO(&server->fd_read);
  if (server->sock != -1)
    FD_SET(server->sock, &server->fd_read);
  FD_SET(0, &server->fd_read);
}

void		read_server(t_server *server)
{
  char		*tmp;
  char		**msg;
  int		i;

  if ((tmp = get_next_line(server->sock)) != NULL)
    {
      if (!strstr(tmp, "PRIVMSG"))
	printf("Server : %s\n", tmp);
      else
	{
	  msg = split_cmd(tmp, " ");
	  if (!msg[0] || !msg[1] || !msg[2] || !msg[3])
	    printf("Probleme with server\n");
	  else
	    {
	      printf("%s<%s %s> ", KBLU, msg[0] + 1, msg[2]);
	      i = 3;
	      while (msg[i])
		printf("%s ", msg[i++]);
	      printf("%s\n", KNRM);
	    }
	}
    }
}

void		handle_server(t_server *server)
{
  server->status = 0;
  server->sock = -1;
  while (1)
    {
      init_fd(server);
      if (select((server->sock != -1 ? server->sock + 1 : 1),
		 &server->fd_read, NULL, NULL, NULL) == -1)
	perror("select");
      if (FD_ISSET(server->sock, &server->fd_read))
	read_server(server);
      if (FD_ISSET(0, &server->fd_read))
	{
	  if (server->status == 0)
	    cmd_server(server);
	  else
	    execute(server);
	}
    }
}
