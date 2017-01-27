/*
** handle_server.c for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/srcs
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Thu May	12 11:09:02 2016 Christophe Ploujoux
** Last update	Thu May	12 11:09:02 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include "client.h"

void	init_function(void (*fct[12])(t_server *))
{
  fct[0] = &cmd_pwd;
  fct[1] = &cmd_cd;
  fct[2] = &cmd_quit;
  fct[3] = &cmd_ls;
  fct[4] = &cmd_get;
  fct[5] = &cmd_put;
  fct[6] = &cmd_delete;
  fct[7] = &cmd_lls;
  fct[8] = &cmd_lcd;
  fct[9] = &cmd_lpwd;
  fct[10] = &cmd_mget;
  fct[11] = &cmd_mput;
}

void	execute_connexion(t_server *server)
{
  if (server->status == 0)
    cmd_user(server);
  else if (server->status == 1)
    cmd_password(server);
}

void	execute(t_server *server)
{
  int	i;
  void	(*command[12])(t_server *);

  init_function(command);
  server->cmd = split_cmd(get_next_line(1));
  if (!server->cmd)
    return;
  i = 0;
  while (server->cmd_list[i])
    {
      if (strcmp(server->cmd_list[i], server->cmd[0]) == 0)
	{
	  command[i](server);
	  return;
	}
      i++;
    }
  printf("Command not found\n");
}

void	handle_server(t_server *server)
{
  server->status = -1;
  while (1) {
    if (server->status == -1) {
      printf("%s\n", get_next_line(server->sock));
      server->status = 0;
    }
    if (server->status == 0 || server->status == 1)
      execute_connexion(server);
    if (server->status == 2) {
      my_putstr(0, "<ftp_ploujo> ");
      execute(server);
    }
  }
}
