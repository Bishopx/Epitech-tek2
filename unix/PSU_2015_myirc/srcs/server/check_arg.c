/*
** check_arg.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/server
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on Tue May 17 10:32:11 2016 Christophe Ploujoux
** Last update  Tue May 17 10:32:11 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include "server.h"

int	check_arg(int ac, char **av)
{
  if (ac != 2)
    {
      printf(USAGE_ERROR);
      return (-1);
    }
  if (atoi(av[1]) < 1025)
    {
      printf("The port have to be superior to 1024\n");
      return (-1);
    }
  return (0);
}

char	**fill_list()
{
  char	**list;

  if ((list = malloc(sizeof(char *) * (9 + 1))) == NULL)
    return NULL;
  list[0] = strdup("USER");
  list[1] = strdup("PASS");
  list[2] = strdup("NICK");
  list[3] = strdup("JOIN");
  list[4] = strdup("PART");
  list[5] = strdup("QUIT");
  list[6] = strdup("LIST");
  list[7] = strdup("NAMES");
  list[8] = strdup("PRIVMSG");
  list[9] = NULL;
  return (list);
}

void  init_cmd_connected(void (*fct[9])(t_user *, t_server *))
{
  fct[0] = &cmd_user;
  fct[1] = &cmd_pass;
  fct[2] = &cmd_nick;
  fct[3] = &cmd_join;
  fct[4] = &cmd_part;
  fct[5] = &cmd_quit;
  fct[6] = &cmd_list;
  fct[7] = &cmd_names;
  fct[8] = &cmd_priv_msg;
}
