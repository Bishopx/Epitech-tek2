/*
** msg_channel.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/server
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Tue May	31 13:46:16 2016 Christophe Ploujoux
** Last update	Tue May	31 13:46:16 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include "server.h"

int		check_channel(t_server *server, char *channel)
{
  t_channel	tmp_serv;

  tmp_serv = server->channel;
  while (tmp_serv)
    {
      if (strcmp(tmp_serv->name, channel) == 0)
	return (0);
      tmp_serv = tmp_serv->next;
    }
  return (1);
}

void		write_to_channel(t_user *user, t_channel tmp_client,
		int fd, char *channel)
{
  int		j;

  j = 2;
  if (strcmp(tmp_client->name, channel) == 0)
    {
      write(fd, ":", 1);
      write(fd, user->nick, strlen(user->nick));
      write(fd, "! PRIVMSG ", strlen("! PRIVMSG "));
      write(fd, channel, strlen(channel));
      write(fd, " ", 1);
      while (user->cmd[j])
	{
	  write(fd, user->cmd[j], strlen(user->cmd[j]));
	  write(fd, " ", 1);
	  j++;
	}
      write(fd, "\r\n", 2);
    }
}

void		msg_to_user(t_user *user, t_server *server, char *channel)
{
  int		i;
  t_channel	tmp_client;

  i = 0;
  while (i < MAX_USER)
    {
      if (server->users[i].fd > 0 && server->users[i].channel)
	{
	  if (strcmp(server->users[i].nick, user->nick) != 0)
	    {
	      tmp_client = server->users[i].channel;
	      while (tmp_client)
		{
		  if (tmp_client->name)
		    write_to_channel(user, tmp_client,
				     server->users[i].fd, channel);
		  tmp_client = tmp_client->next;
		}
	    }
	}
      i++;
    }
}

void		msg_channel(t_user *user, t_server *server)
{
  char		**chan;
  int		i;

  chan = split_cmd(user->cmd[1], ",");
  i = 0;
  while (chan[i])
    {
      if (check_channel(server, chan[i]) == 0)
	msg_to_user(user, server, chan[i]);
      else
	{
	  write(user->fd, "401 ", strlen("401 "));
	  write(user->fd, chan[i], strlen(chan[i]));
	  my_putstr(user->fd, " :No such channel");
	}
      i++;
    }
}

void		msg_to_all(t_server *server, char *chan, char *str)
{
  t_channel	tmp_client;
  int		i;

  i = 0;
  while (i < MAX_USER)
    {
      if (server->users[i].fd != -1 && server->users[i].channel)
	{
	  tmp_client = server->users[i].channel;
	  while (tmp_client)
	    {
	      if (strcmp(tmp_client->name, chan) == 0)
		my_putstr(server->users[i].fd, str);
	      tmp_client = tmp_client->next;
	    }
	}
    i++;
    }
}
