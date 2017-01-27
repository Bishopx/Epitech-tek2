/*
** cmd_port.c for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/srcs
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Fri May	13 11:39:29 2016 Christophe Ploujoux
** Last update	Fri May	13 11:39:29 2016 Christophe Ploujoux
*/

#include <unistd.h>
#include <string.h>
#include "server.h"

void	get_port(t_client *client)
{
  char	*save;
  char	*tmp;
  int	i;
  int	p1;
  int	p2;

  tmp = strdup(client->cmd[1]);
  save = strtok(tmp, ",");
  i = 0;
  while (save)
    {
      if (i == 4)
	p1 = atoi(save);
      if (i == 5)
	p2 = atoi(save);
      save = strtok(NULL, ",");
      i++;
    }
  if (i != 6)
    return;
  client->transfert.port = p1 * 256 + p2;
}

void	get_ip(t_client *client)
{
  char	*save;
  int	i;

  save = strtok(client->cmd[1], "(,)");
  i = 0;
  while (save)
    {
      if (i == 0)
	client->transfert.ip = strdup(save);
      else if (i < 4)
	client->transfert.ip = strcat(client->transfert.ip, save);
      if (i < 3)
	client->transfert.ip = strcat(client->transfert.ip, ".");
      save = strtok(NULL, "(,)");
      i++;
    }
  if (i != 6)
    return;
}

void			cmd_port(t_client *client)
{
  int			sock;
  struct sockaddr_in 	addr;
  int			on;

  if (!client->cmd[1]) {
    my_putstr(client->sock, "501 Error PORT command");
    return;
  }
  get_port(client);
  get_ip(client);
  if (client->transfert.port == -1)
    return;
  sock = xsocket(AF_INET, SOCK_STREAM, 0);
  if ((on = setsockopt(sock, SOL_SOCKET,
		       SO_REUSEADDR, (const char*)&on, sizeof(on))) == -1)
    return;
  addr.sin_family = AF_INET;
  inet_pton(AF_INET, client->transfert.ip, &(addr.sin_addr));
  addr.sin_port = htons(client->transfert.port);
  client->transfert.addr = addr;
  client->transfert.socket = sock;
  client->transfert.transfert = 2;
  my_putstr(client->sock, "200 PORT command successful. Consider using PASV.");
}
