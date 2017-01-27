/*
** cmd_login.c for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/bonus/srcs
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Sat May	14 23:22:50 2016 Christophe Ploujoux
** Last update	Sat May	14 23:22:50 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include "client.h"

void	cmd_user(t_server *server)
{
  my_putstr(0, "Enter your username: ");
  server->cmd = split_cmd(get_next_line(1));
  if (!server->cmd)
    return;
  my_putstr(server->sock, "USER ");
  my_putstr(server->sock, server->cmd[0]);
  my_putstr(server->sock, CRLF);
  server->response = get_next_line(server->sock);
  server->status = 1;
}

void	cmd_password(t_server *server)
{
  my_putstr(0, "Enter your password: ");
  server->cmd = split_cmd(get_next_line(1));
  my_putstr(server->sock, "PASS ");
  if (server->cmd)
    my_putstr(server->sock, server->cmd[0]);
  my_putstr(server->sock, CRLF);
  server->response = get_next_line(server->sock);
  printf("%s\n", server->response);
  if (read_code(server->response) == 230)
    server->status = 2;
  else
    server->status = 0;
}
