/*
** cmd_names.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/client
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Fri Jun	3 18:45:12 2016 Christophe Ploujoux
** Last update	Fri Jun	3 18:45:12 2016 Christophe Ploujoux
*/

#include <unistd.h>
#include <string.h>
#include "client.h"

void		cmd_users(t_server *server)
{
  my_putstr(server->sock, "NAMES");
}

void		cmd_names(t_server *server)
{
  if (!server->cmd[1])
    {
      printf("Usage: /names channel");
      return;
    }
  write(server->sock, "NAMES ", strlen("NAMES "));
  my_putstr(server->sock, server->cmd[1]);
}
