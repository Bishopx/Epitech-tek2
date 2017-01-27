/*
** handle_sever.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/server
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Tue May	17 10:29:13 2016 Christophe Ploujoux
** Last update	Tue May	17 10:29:13 2016 Christophe Ploujoux
*/

#include <unistd.h>
#include <string.h>
#include "server.h"

void			server_read(t_server *server)
{
  add_client(server);
}

void			add_server(t_server *server)
{
  struct sockaddr_in	sin;

  server->sock = socket(PF_INET, SOCK_STREAM, 0);
  server->max_fd++;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(server->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  xbind(server->sock, (struct sockaddr*)&sin, sizeof(sin));
  xlisten(server->sock, 256);
}

void			init_fd(t_server *server)
{
  int			i;

  i = 0;
  FD_ZERO(&server->fd_read);
  server->max_fd = server->sock;
  FD_SET(server->sock, &server->fd_read);
  while (i < MAX_USER)
    {
      if (server->users[i].fd != -1)
	{
	  FD_SET(i, &server->fd_read);
	  server->max_fd = i;
	}
      i++;
    }
}

void			handle_server(t_server *server)
{
  int			i;

  while (1)
    {
      init_fd(server);
      if (select(server->max_fd + 1, &server->fd_read, NULL, NULL, NULL) == -1)
	perror("select");
      if (FD_ISSET(server->sock, &server->fd_read))
	{
	  server_read(server);
	}
      i = 0;
      while (i < MAX_USER)
	{
	  if (FD_ISSET(i, &server->fd_read))
	    handle_clients(&server->users[i], server);
	  i++;
	}
    }
}
