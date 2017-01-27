/*
** cmd_server.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/client
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Tue May	17 16:44:01 2016 Christophe Ploujoux
** Last update	Tue May	17 16:44:01 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include "client.h"

int			get_port(t_server *server)
{
  int			i;

  i = 0;
  while (server->cmd[1][i] != ':')
    i++;
  i++;
  return (atoi(server->cmd[1] + i));
}

char			*get_ip(t_server *server)
{
  int			i;
  char			*tmp;

  i = 0;
  tmp = NULL;
  while (server->cmd[1][i] != ':')
    i++;
  if ((tmp = malloc(i)) == NULL)
    return (NULL);
  i = 0;
  while (server->cmd[1][i] != ':') {
    tmp[i] = server->cmd[1][i];
    i++;
  }
  tmp[i] = '\0';
  return (tmp);
}

void			connect_server(t_server *server)
{
  struct sockaddr_in	s_in;
  struct protoent	*pe;

  server->port = 6667;
  server->ip = server->cmd[1];
  if (strstr(server->cmd[1], ":") != NULL)
    {
      server->port = get_port(server);
      server->ip = get_ip(server);
    }
  if (!(pe = getprotobyname("TCP")))
    {
      printf(PROTO_ERROR);
      return;
    }
  server->sock = xsocket(AF_INET, SOCK_STREAM, pe->p_proto);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(server->port);
  s_in.sin_addr.s_addr = inet_addr(server->ip);
  if (connect(server->sock, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      printf("Failed to connect to the server\n");
      return;
    }
  server->status = 1;
}

void			cmd_server(t_server *server)
{
  if ((server->cmd = split_cmd(get_next_line(1), " \r\n")) == NULL)
    return;
  if (!server->cmd[1])
    return;
  if (strcmp(server->cmd[0], "/server") == 0)
    {
      connect_server(server);
    if (server->status == 1)
      {
	my_putstr(server->sock, "USER ploujo hello test foo");
	my_putstr(server->sock, "NICK ploujo");
      }
    }
  else
    printf("Connect to a server before doin anything\n");
}
