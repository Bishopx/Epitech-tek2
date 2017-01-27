/*
** cmd_names.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/server
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Mon May	30 13:09:37 2016 Christophe Ploujoux
** Last update	Mon May	30 13:09:37 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include "server.h"

void		write_end(t_user *user, char *channel)
{
  write(user->fd, "366 ", strlen("366 "));
  write(user->fd, user->nick, strlen(user->nick));
  write(user->fd, " ", 1);
  write(user->fd, channel, strlen(channel));
  write(user->fd, " :End of /NAMES list\r\n",
  	strlen(" :End of /NAMES list\r\n"));
}

void		write_begin(t_user *user, char *channel)
{
  write(user->fd, "353 ", strlen("353 "));
  write(user->fd, user->nick, strlen(user->nick));
  write(user->fd, " @ ", strlen(" @ "));
  write(user->fd, channel, strlen(channel));
  write(user->fd, " :", strlen(" :"));
}

void		print_names(t_user *user, t_server *server, int i, int *count)
{
  if (*count != 0)
    write(user->fd, " ", 1);
  write(user->fd, server->users[i].nick,
    	strlen(server->users[i].nick));
  (*count)++;
}

void		names_channel(t_user *user, t_server *server, char *channel, int type)
{
  int		i;
  int		count;
  t_channel	tmp_client;

  i = 0;
  count = 0;
  write_begin(user, channel);
  while (i < MAX_USER)
    {
      if (server->users[i].fd > 0 && server->users[i].channel)
	{
	  tmp_client = server->users[i].channel;
	  while (tmp_client) {
	    if (tmp_client->name)
	      if (strcmp(tmp_client->name, channel) == 0)
		print_names(user, server, i, &count);
	    tmp_client = tmp_client->next;
	  }
	}
      i++;
    }
  write(user->fd, "\r\n", 2);
  if (type == 0)
    write_end(user, channel);
}

void		cmd_names(t_user *user, t_server *server)
{
  t_channel	serv;

  if (user->cmd[1])
    names_channel(user, server, user->cmd[1], 0);
  else
    {
      serv = server->channel;
      while (serv)
	{
	  names_channel(user, server, serv->name, 1);
	  serv = serv->next;
	}
      write_end(user, "*");
    }
}
