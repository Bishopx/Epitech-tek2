/*
** cmd_pasv.c for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/srcs
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Fri May	13 11:38:24 2016 Christophe Ploujoux
** Last update	Fri May	13 11:38:24 2016 Christophe Ploujoux
*/

#include <unistd.h>
#include <string.h>
#include "server.h"

void  print_ip(t_client *client)
{
  int i;

  i = 0;
  while (client->server_ip[i])
  {
    if (client->server_ip[i] == '.')
      write(client->sock, ",", 1);
    else
      write(client->sock, &client->server_ip[i], 1);
    i++;
  }
  write(client->sock, ",", 1);
}

void	print_pasv(t_client *client)
{
  char	*str;

  write(client->sock,
	"227 Entering Passive Mode (",
	strlen("227 Entering Passive Mode ("));
  print_ip(client);
  if ((str = malloc(4)) == NULL)
    return;
  sprintf(str, "%d", client->transfert.port / 256);
  write(client->sock, str, strlen(str));
  write(client->sock, ",", 1);
  sprintf(str, "%d", client->transfert.port % 256);
  write(client->sock, str, strlen(str));
  write(client->sock, ")\r\n", 3);
  free(str);
}

void			cmd_pasv(t_client *client)
{
  int			sock;
  struct sockaddr_in	saddr;
  struct sockaddr_in	caddr;
  socklen_t		caddrlen;
  int			check;

  sock = xsocket(AF_INET, SOCK_STREAM, 0);
  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = INADDR_ANY;
  client->transfert.port = 10000;
  while (client->transfert.port < 65536) {
    saddr.sin_port = htons(client->transfert.port);
    check = bind(sock, (struct sockaddr *) &saddr, (socklen_t) sizeof(saddr));
    if (!check)
      break;
    client->transfert.port++;
  }
  if (check)
    return;
  xlisten(sock, 1);
  caddrlen = (socklen_t) sizeof(caddr);
  print_pasv(client);
  client->transfert.socket = xaccept(sock, (struct sockaddr *) &caddr,
				     &caddrlen);
  client->transfert.transfert = 1;
}
