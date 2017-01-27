/*
** check_arg.c for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/srcs
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Thu May	12 19:54:08 2016 Christophe Ploujoux
** Last update	Thu May	12 19:54:08 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include "client.h"

int	check_arg(int ac, char **av)
{
  if (ac != 3)
    {
      printf(USAGE_ERROR);
      return (-1);
    }
  av = av;
  return (0);
}

void	fill_list(t_server *server)
{
  if ((server->cmd_list = malloc(sizeof(char *) * (11 + 1))) == NULL)
    return;
  server->cmd_list[0] = strdup("pwd");
  server->cmd_list[1] = strdup("cd");
  server->cmd_list[2] = strdup("quit");
  server->cmd_list[3] = strdup("ls");
  server->cmd_list[4] = strdup("get");
  server->cmd_list[5] = strdup("put");
  server->cmd_list[6] = strdup("delete");
  server->cmd_list[7] = strdup("lls");
  server->cmd_list[8] = strdup("lcd");
  server->cmd_list[9] = strdup("lpwd");
  server->cmd_list[10] = strdup("mget");
  server->cmd_list[11] = strdup("mput");
  server->cmd_list[12] = NULL;
}

int	check_cmd(t_server *server)
{
  int	i;

  if (!server->cmd[0])
    return (-1);
  i = 0;
  while (server->cmd_list[i])
    {
      if (strcmp(server->cmd[0], server->cmd_list[i]) == 0)
	return (0);
      i++;
    }
  return (-1);
}
