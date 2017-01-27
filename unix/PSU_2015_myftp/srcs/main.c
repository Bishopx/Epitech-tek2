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
#include "server.h"

void 	init_transfert(t_client *client)
{
  client->transfert.socket = -1;
  client->transfert.port = -1;
  client->transfert.transfert = -1;
}

int			init_server(char **av)
{
  struct sockaddr_in	s_in;
  struct protoent	*pe;
  int			port;
  int			socket;

  port = atoi(av[1]);
  if (!(pe = getprotobyname("TCP")))
    {
      printf(PROTO_ERROR);
      return (-1);
    }
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  socket = xsocket(AF_INET, SOCK_STREAM, pe->p_proto);
  xbind(socket, (const struct sockaddr *) &s_in, sizeof(s_in));
  xlisten(socket, 42);
  return (socket);
}

int			main(int ac, char **av)
{
  t_client		client;
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;
  int			socket;

  if (check_arg(ac, av) ==  -1)
    return (1);
  if ((socket = init_server(av)) == -1)
    return (1);
  s_in_size = sizeof(s_in_client);
  while (1) {
    client.sock = xaccept(socket,
			  (struct sockaddr *)&s_in_client, &s_in_size);
    getsockname(client.sock, (struct sockaddr *)&s_in_client, &s_in_size);
    client.server_ip = inet_ntoa(s_in_client.sin_addr);
    client.path = av[2];
    init_transfert(&client);
    handle_client(&client);
  }
  close(socket);
  return 0;
}
