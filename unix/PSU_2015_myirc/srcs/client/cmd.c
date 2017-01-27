/*
** cmd.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/client
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Tue May	17 16:17:57 2016 Christophe Ploujoux
** Last update	Tue May	17 16:17:57 2016 Christophe Ploujoux
*/

#include <unistd.h>
#include <string.h>
#include "client.h"

void		cmd_nick(t_server *server)
{
  if (!server->cmd[1])
    {
      printf("Usage: /nick nickname");
      return;
    }
  write(server->sock, "NICK ", strlen("NICK "));
  my_putstr(server->sock, server->cmd[1]);
}

void		cmd_list(t_server *server)
{
  write(server->sock, "LIST", strlen("LIST"));
  if (server->cmd[1])
    {
      write(server->sock, " ", 1);
      my_putstr(server->sock, server->cmd[1]);
    }
  else
    write(server->sock, "\r\n", 2);
}

void		cmd_join(t_server *server)
{
  if (!server->cmd[1])
    {
      printf("Usage: /join channel\n");
      return;
    }
  write(server->sock, "JOIN #", strlen("JOIN #"));
  my_putstr(server->sock, server->cmd[1]);
  list_add_elem_at_back(&server->channel, server->cmd[1]);
}

void		cmd_part(t_server *server)
{
  if (!server->cmd[1])
    {
      printf("Usage: /part channel\n");
      return;
    }
  write(server->sock, "PART #", strlen("PART #"));
  my_putstr(server->sock, server->cmd[1]);
  deleteNode(&server->channel, server->cmd[1]);
}

void		cmd_quit(t_server *server)
{
  my_putstr(server->sock, "QUIT");
  exit(0);
}
