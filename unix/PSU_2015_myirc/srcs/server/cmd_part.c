/*
** cmd_part.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/server
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Fri Jun	3 22:14:20 2016 Christophe Ploujoux
** Last update	Fri Jun	3 22:14:20 2016 Christophe Ploujoux
*/

#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "server.h"

int 			chan_exist(t_server *server, char *str)
{
  t_channel		tmp_serv;

  tmp_serv = server->channel;
  while (tmp_serv)
    {
      if (strcmp(tmp_serv->name, str) == 0)
	return (1);
      tmp_serv = tmp_serv->next;
    }
  return (0);
}

void	msg_part(t_user *user, t_server *server, char *chan)
{
  char	str[500];

  if (deleteNode(&user->channel, chan) == FALSE)
    {
      my_putstr(user->fd, "442 You're not on that channel");
      return;
    }
  else
    {
      sprintf(str, ":%s!~%s@127.0.0.1 PART %s",
	      user->nick, user->nick, chan);
      my_putstr(user->fd, str);
      msg_to_all(server, chan, str);
    }
}

void	loop_part(t_user *user, t_server *server, char **chan)
{
  int	i;

  i = 0;
  while (chan[i])
    {
      if (chan_exist(server, chan[i]) == 0)
	{
	  my_putstr(user->fd, "403 No such channel");
	  return;
	}
      msg_part(user, server, chan[i]);
      if (count_user(server, chan[i]) == 0)
	deleteNode(&server->channel, chan[i]);
      i++;
    }
}

void			cmd_part(t_user *user, t_server *server)
{
  char			**chan;

  if (!user->cmd[1])
    {
      my_putstr(user->fd, ERR_NEEDMOREPARAMS);
      return;
    }
  chan = split_cmd(user->cmd[1], ",");
  loop_part(user, server, chan);
}
