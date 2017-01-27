/*
** cmd_message.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/server
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on Mon May 30 13:10:45 2016 Christophe Ploujoux
** Last update  Mon May 30 13:10:45 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include "server.h"

void		cmd_priv_msg(t_user *user, t_server *server)
{
  if (!user->cmd[1])
    {
      my_putstr(user->fd, "411 PRIVMSG no recipient");
      return;
    }
  if (!user->cmd[2] || user->cmd[2][1] == '\0')
    {
      my_putstr(user->fd, "412 PRIVMSG no text to send");
      return;
    }
  if (user->cmd[1][0] == '&' || user->cmd[1][0] == '#')
    msg_channel(user, server);
  else
    msg_nick(user, server);
}
