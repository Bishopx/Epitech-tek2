/*
** cmd_basic.c for cmd_basic in /home/ploujo_c/tek2/unix/PSU_2015_myftp/bonus
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@ploujo-HP-EliteBook-840-G1>
** 
** Started on  Sat May 14 19:50:35 2016 Christophe Ploujoux
** Last update Sun May 15 01:23:23 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include "client.h"

void	cmd_lls(t_server *server)
{
  int	size;
  FILE	*in;
  char	tmp[256];
  int	i;

  server = server;
  in = popen("ls -l -a | wc -l", "r");
  fgets(tmp, 255, in);
  size = atoi(tmp);
  in = popen("ls -l -a", "r");
  i = 0;
  while (i < size) {
    fgets(tmp, 255, in);
    printf("%s", tmp);
    i++;
  }
}

void	cmd_lpwd(t_server *server)
{
  printf("%s\n", server->path);
}

void	cmd_lcd(t_server *server)
{
  if (!server->cmd[1])
    printf("Please indicate a directory");
  else
    {
      if (chdir(server->cmd[1]) == -1)
	printf("Directory doesn't exist\n");
      if (strcmp(server->cmd[1], "..") == 0)
	change_path(server);
      else
	server->path = my_strcat(server->path, server->cmd[1]);
    }
}
