/*
** cmd_login.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/server
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Tue May	17 10:33:29 2016 Christophe Ploujoux
** Last update	Tue May	17 10:33:29 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include "server.h"

void	cmd_user(t_user *user, t_server *server)
{
  if (!user->cmd[1] || !user->cmd[2] || !user->cmd[3] || !user->cmd[4])
    {
      my_putstr(user->fd, ERR_NEEDMOREPARAMS);
      return;
    }
  if (user->status == REGISTERED)
    {
      my_putstr(user->fd, "462 You are already registerd");
      return;
    }
  server = server;
  user->name = user->cmd[1];
  if (user->nick)
    {
      user->status = REGISTERED;
      write(user->fd, "001 ", strlen("001 "));
      write(user->fd, user->nick, strlen(user->nick));
      my_putstr(user->fd, " Username registered");
    }
}

void		cmd_pass(t_user *user, t_server *server)
{
  user->status = 1;
  server = server;
}
