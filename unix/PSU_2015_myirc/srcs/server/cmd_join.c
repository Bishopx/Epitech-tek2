/*
** cmd_join.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/server
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Sat May	28 13:59:37 2016 Christophe Ploujoux
** Last update	Sat May	28 13:59:37 2016 Christophe Ploujoux
*/

#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "server.h"

int			check_chan_user(t_user *user, char *chan)
{
  t_channel		tmp_user;

  tmp_user = user->channel;
  while (tmp_user)
    {
      if (strcmp(tmp_user->name, chan) == 0)
	return (1);
      tmp_user = tmp_user->next;
    }
  return (0);
}

void			add_channel(t_user *user, t_server *server, char *chan)
{
  t_channel		tmp_serv;
  int			check;

  check = 0;
  tmp_serv = server->channel;
  while (tmp_serv)
    {
      if (strcmp(tmp_serv->name, chan) == 0)
	check = 1;
      tmp_serv = tmp_serv->next;
    }
  if (check == 0)
    list_add_elem_at_back(&server->channel, chan);
  if (check_chan_user(user, chan) == 0)
    list_add_elem_at_back(&user->channel, chan);
  names_channel(user, server, chan, 0);
}

void			cmd_join(t_user *user, t_server *server)
{
  char			**chan;
  int			i;
  char			str[500];

  if (!user->cmd[1])
    {
      my_putstr(user->fd, ERR_NEEDMOREPARAMS);
      return;
    }
  chan = split_cmd(user->cmd[1], ",");
  i = 0;
  while (chan[i])
    {
      if (chan[i][0] != '#' && chan[i][0] != '&')
	my_putstr(user->fd, "403 No such channel");
      else
	{
	  add_channel(user, server, chan[i]);
	  sprintf(str, ":%s!~%s@127.0.0.1 JOIN %s", user->nick, user->nick, chan[i]);
	  msg_to_all(server, chan[i], str);
	}
      i++;
    }
}
