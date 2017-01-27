/*
** cmd_quit.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/server
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Fri Jun	3 02:09:55 2016 Christophe Ploujoux
** Last update	Fri Jun	3 02:09:55 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include "server.h"

void		write_cmd(t_user *user, t_server *server,
			  t_channel chan, char *str)
{
  int		i;
  t_channel	tmp_users;

  i = 0;
  while (i < MAX_USER)
    {
      if (server->users[i].fd > 0 && server->users[i].channel
	  && user->fd != server->users[i].fd)
	{
	  tmp_users = server->users[i].channel;
	  while (tmp_users)
	    {
	      if (strcmp(chan->name, tmp_users->name) == 0) {
	      write(server->users[i].fd, "QUIT ", strlen("QUIT "));
	      my_putstr(server->users[i].fd, str);
	      }
	      tmp_users = tmp_users->next;
	    }
	}
      i++;
    }
}

void		msg_to_channels(t_user *user, t_server *server, char *str)
{
  t_channel	tmp_client;

  tmp_client = user->channel;
  while (tmp_client)
    {
      write_cmd(user, server, tmp_client, str);
      tmp_client = tmp_client->next;
    }
}

char	*get_msg(t_user *user)
{
  int	i;
  char	*tmp;

  i = 1;
  tmp = strcat(strdup("<"), user->nick);
  tmp = strcat(tmp, "> ");
  while (user->cmd[i])
    {
      tmp = strcat(tmp, user->cmd[i]);
      tmp = strcat(tmp, " ");
      i++;
    }
  return (tmp);
}

void	cmd_quit(t_user *user, t_server *server)
{
  if (user->cmd[1])
    msg_to_channels(user, server, get_msg(user));
  else
    msg_to_channels(user, server, ":Client quit");
  close(user->fd);
  user->channel = NULL;
  user->ip = NULL;
  user->status = NOTHING;
  user->fd = -1;
  user->nick = NULL;
  user->name = NULL;
}
