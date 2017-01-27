/*
** msg_nick.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/server
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Tue May	31 13:42:34 2016 Christophe Ploujoux
** Last update	Tue May	31 13:42:34 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include "server.h"

t_user		*check_nick(char *nick, t_server *server)
{
  int		i;

  i = 0;
  while (i < MAX_USER)
    {
      if (server->users[i].fd > 0)
	if (strcmp(server->users[i].nick, nick) == 0)
	  return &server->users[i];
      i++;
    }
  return NULL;
}

void		error_nick(t_user *user, char *nick)
{
  write(user->fd, "401 ", strlen("401 "));
  write(user->fd, nick, strlen(nick));
  my_putstr(user->fd, " :No such nickname");
}

void	write_msg_nick(t_user *user, t_user *tmp, char **nick, int j)
{
  char	str[500];
  int	i;

  sprintf(str, ":%s!~%s@127.0.0.1 PRIVMSG %s ",
	  user->nick, user->nick, nick[j]);
  write(tmp->fd, str, strlen(str));
  i = 2;
  while (user->cmd[i])
    {
      write(tmp->fd, user->cmd[i], strlen(user->cmd[i]));
      write(tmp->fd, " ", 1);
      i++;
    }
  write(tmp->fd, "\r\n", 2);
}

void		msg_nick(t_user *user, t_server *server)
{
  t_user	*tmp;
  char		**nick;
  int		j;

  j = 0;
  nick = split_cmd(user->cmd[1], ",");
  while (nick[j])
    {
      if ((tmp = check_nick(nick[j], server)))
	{
	  write_msg_nick(user, tmp, nick, j);
	}
      else
	error_nick(user, nick[j]);
      j++;
    }
}
