/*
** main.c for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/srcs
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Wed May	11 15:05:14 2016 Christophe Ploujoux
** Last update	Wed May	11 15:05:14 2016 Christophe Ploujoux
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "client.h"

void 	init_transfert(t_server *server)
{
  server->transfert.socket = -1;
  server->transfert.port = -1;
}

int			init_server(char **av)
{
  struct sockaddr_in	s_in;
  struct protoent	*pe;
  int			port;
  int			socket;

  port = atoi(av[2]);
  if (!(pe = getprotobyname("TCP")))
    {
      printf(PROTO_ERROR);
      return (-1);
    }
  socket = xsocket(AF_INET, SOCK_STREAM, pe->p_proto);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr(av[1]);
  xconnect(socket, (struct sockaddr *)&s_in, sizeof(s_in));
  return (socket);
}

int		main(int ac, char **av)
{
  t_server	server;

  if (check_arg(ac, av) ==  -1)
    return (1);
  if ((server.sock = init_server(av)) == -1)
    return (1);
  server.path = getenv("PWD");
  fill_list(&server);
  handle_server(&server);
  return 0;
}
