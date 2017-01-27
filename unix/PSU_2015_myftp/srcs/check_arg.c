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
#include "server.h"

int	check_arg(int ac, char **av)
{
  if (ac != 3)
    {
      printf(USAGE_ERROR);
      return (-1);
    }
  if (atoi(av[1]) < 1025)
    {
      printf("The port have to be superior to 1024\n");
      return (-1);
    }
  if (chdir(av[2]) == -1)
    {
      printf("The path does not exist\n");
      return (-1);
    }
  return (0);
}

char	**fill_list()
{
  char	**list;

  if ((list = malloc(sizeof(char *) * (14 + 1))) == NULL)
    return NULL;
  list[0] = strdup("USER");
  list[1] = strdup("PASS");
  list[2] = strdup("QUIT");
  list[3] = strdup("PWD");
  list[4] = strdup("HELP");
  list[5] = strdup("PASV");
  list[6] = strdup("PORT");
  list[7] = strdup("NOOP");
  list[8] = strdup("CWD");
  list[9] = strdup("CDUP");
  list[10] = strdup("DELE");
  list[11] = strdup("RETR");
  list[12] = strdup("STOR");
  list[13] = strdup("LIST");
  list[14] = NULL;
  return (list);
}
