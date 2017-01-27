/*
** connect_data.c for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/bonus/srcs
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Sat May	14 22:00:11 2016 Christophe Ploujoux
** Last update	Sat May	14 22:00:11 2016 Christophe Ploujoux
*/

#include <string.h>
#include "client.h"

void	get_ip_port(t_server *server)
{
  int	i;
  char	*save;
  char	*tmp;
  int	p1;
  int	p2;

  i = 0;
  tmp = server->response;
  save = strtok(tmp, "(,)");
  while (save)
    {
      if (i == 1)
	server->transfert.ip = strdup(save);
      else if (i > 1 && i < 5)
	server->transfert.ip = strcat(server->transfert.ip, save);
      if (i > 0 && i < 4)
	server->transfert.ip = strcat(server->transfert.ip, ".");
      if (i == 5)
	p1 = atoi(save);
      if (i == 6)
	p2 = atoi(save);
      save = strtok(NULL, "(,)");
      i++;
    }
  server->transfert.port = p1 * 256 + p2;
}

void			connect_data(t_server *server)
{
  int			sock;
  struct sockaddr_in	addr;
  int			on;

  my_putstr(server->sock, "PASV\r\n");
  server->response = get_next_line(server->sock);
  printf("%s\n", server->response);
  get_ip_port(server);
  sock = xsocket(AF_INET, SOCK_STREAM, 0);
  if ((on = setsockopt(sock, SOL_SOCKET,
		       SO_REUSEADDR, (const char*)&on, sizeof(on))) == -1)
    return;
  addr.sin_family = AF_INET;
  inet_pton(AF_INET, server->transfert.ip, &(addr.sin_addr));
  addr.sin_port = htons(server->transfert.port);
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    return;
  }
  server->transfert.socket = sock;
}
