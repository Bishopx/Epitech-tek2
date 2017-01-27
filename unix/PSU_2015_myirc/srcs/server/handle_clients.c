/*
** handle_clients.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/server
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on Tue May 17 10:31:54 2016 Christophe Ploujoux
** Last update  Tue May 17 10:31:54 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include "server.h"

void			execute_command(t_user *user, t_server *server)
{
  int			i;
  void			(*command[9])(t_user *user, t_server *server);

  init_cmd_connected(command);
  while (server->cmd_list[i])
    {
      if (i > 2 && (user->status != REGISTERED || !user->nick))
	{
	  my_putstr(user->fd, "451 Register first");
	  return;
	}
      if (strcmp(server->cmd_list[i], user->cmd[0]) == 0)
	{
	  command[i](user, server);
	  return;
	}
      i++;
    }
  my_putstr(user->fd, "500 Command not found");
}

void			handle_clients(t_user *user, t_server *server)
{
  char			*buff;

  if ((buff = get_next_line(user->fd)) == NULL)
    return;
  user->cmd = split_cmd(buff, " \r\n");
  if (!user->cmd)
    return;
  execute_command(user, server);
  my_cmd(user->cmd);
}

void			add_client(t_server *server)
{
  int			cs;
  struct sockaddr_in	client_sin;
  socklen_t		client_sin_len;

  client_sin_len = sizeof(client_sin);
  cs = xaccept(server->sock, (struct sockaddr *)&client_sin, &client_sin_len);
  server->users[cs].fd = cs;
  server->users[cs].channel = NULL;
  my_putstr(cs, "220 Connection established");
}
