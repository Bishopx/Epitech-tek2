/*
** cmd_channel.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/server
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Sat May	28 12:57:42 2016 Christophe Ploujoux
** Last update	Sat May	28 12:57:42 2016 Christophe Ploujoux
*/

#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "server.h"

int     count_user(t_server *server, char *str)
{
  t_channel   tmp_client;
  int     count;
  int     i;

  i = 0;
  count = 0;
  while (i < MAX_USER)
    {
      if (server->users[i].fd > 0 && server->users[i].channel) {
  tmp_client = server->users[i].channel;
  while (tmp_client) {
  if (tmp_client->name) {
    if (strcmp(tmp_client->name, str) == 0)
      count++;
  }
  tmp_client = tmp_client->next;
  }
      }
      i++;
    }
  return (count);
}

void			cmd_list(t_user *user, t_server *server)
{
  t_channel		tmp;
  char			str[500];

  tmp = server->channel;
  my_putstr(user->fd, "321 List start");
  while (tmp)
    {
      if (user->cmd[1])
	{
	  if (strstr(tmp->name, user->cmd[1]))
	    {
	      sprintf(str, "322 %s %s %d :",
		      user->nick, tmp->name, count_user(server, tmp->name));
	      my_putstr(user->fd, str);
	    }
	}
      else
	{
	  sprintf(str, "322 %s %s %d :",
		  user->nick, tmp->name, count_user(server, tmp->name));
	  my_putstr(user->fd, str);
	}
      tmp = tmp->next;
    }
  my_putstr(user->fd, "323 List end");
}
