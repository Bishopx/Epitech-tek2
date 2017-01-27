/*
** cmd_nick.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/server
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Sat Jun	4 15:12:58 2016 Christophe Ploujoux
** Last update	Sat Jun	4 15:12:58 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include "server.h"

int	check_nickname(t_user *user, t_server *server)
{
  int	i;

  i = 0;
  while (i < MAX_USER)
    {
      if (server->users[i].fd != -1 && server->users[i].nick)
	if (strcmp(user->cmd[1], server->users[i].nick) == 0)
	  return (1);
      i++;
    }
  return (0);
}

void		msg_nick_to_channels(t_user *user, t_server *server)
{
  char		str[500];
  t_channel	tmp_client;

  tmp_client = user->channel;
  sprintf(str, ":%s!~%s@127.0.0.1 NICK :%s", user->nick,
	  user->nick, user->cmd[1]);
  while (tmp_client)
    {
      msg_to_all(server, tmp_client->name, str);
      tmp_client = tmp_client->next;
    }
}

void	return_nick(t_user *user, t_server *server)
{
  if (user->name && user->status != REGISTERED)
    {
      user->status = REGISTERED;
      write(user->fd, "001 ", strlen("001 "));
      write(user->fd, user->cmd[1], strlen(user->cmd[1]));
      my_putstr(user->fd, " Username registered");
    }
  else
    {
    	if (!user->channel) {
      write(user->fd, "NICK :", strlen("NICK :"));
      my_putstr(user->fd, user->cmd[1]);
    	}
    	else
    		msg_nick_to_channels(user, server);
    }
}

void		cmd_nick(t_user *user, t_server *server)
{
  if (!user->cmd[1])
    {
      my_putstr(user->fd, "413 Give a nickname please");
      return;
    }
  if (check_nickname(user, server) == 1)
    {
      my_putstr(user->fd, "433 Nickname is already in use");
      return;
    }
  server = server;
  if (user->nick)
    {
      write(user->fd, ":", 1);
      write(user->fd, user->nick, strlen(user->nick));
      write(user->fd, "! ", 2);
    }
  return_nick(user, server);
  user->nick = user->cmd[1];
}
