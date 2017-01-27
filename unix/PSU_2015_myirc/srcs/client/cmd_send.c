/*
** cmd_send.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/client
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Tue May	17 17:18:56 2016 Christophe Ploujoux
** Last update	Tue May	17 17:18:56 2016 Christophe Ploujoux
*/

#include <unistd.h>
#include <string.h>
#include "client.h"

void		cmd_msg(t_server *server)
{
  int		i;

  if (!server->cmd[1] || !server->cmd[2])
    {
      printf("Usage: /msg channel|nickname message\n");
      return;
    }
  write(server->sock, "PRIVMSG ", strlen("PRIVMSG "));
  write(server->sock, server->cmd[1], strlen(server->cmd[1]));
  write(server->sock, " :", 1);
  i = 2;
  while (server->cmd[i])
    {
      write(server->sock, server->cmd[i], strlen(server->cmd[i]));
      write(server->sock, " ", 1);
      i++;
    }
  write(server->sock, "\r\n", 2);
  printf("%s<you %s>", KGRN, server->channel->name);
  i = 2;
  while (server->cmd[i])
    printf("%s ", server->cmd[i++]);
  printf("%s\n", KNRM);
}

void		cmd_send_file(t_server *server)
{
  server = server;
  printf("/send_file\n");
}

void		cmd_accept_file(t_server *server)
{
  server = server;
  printf("/accept_file\n");
}
