/*
** fonction_ptr.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/client
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on Tue May 17 16:45:39 2016 Christophe Ploujoux
** Last update  Tue May 17 16:45:39 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include "client.h"

void		fill_list(t_server *server)
{
  if ((server->cmd_list = malloc(sizeof(char *) * (10 + 1))) == NULL)
    return;
  server->cmd_list[0] = strdup("/nick");
  server->cmd_list[1] = strdup("/list");
  server->cmd_list[2] = strdup("/join");
  server->cmd_list[3] = strdup("/part");
  server->cmd_list[4] = strdup("/users");
  server->cmd_list[5] = strdup("/msg");
  server->cmd_list[6] = strdup("/send_file");
  server->cmd_list[7] = strdup("/accept_file");
  server->cmd_list[8] = strdup("/names");
  server->cmd_list[9] = strdup("/quit");
  server->cmd_list[10] = NULL;
}

void		init_cmd(void (*fct[10])(t_server *))
{
  fct[0] = &cmd_nick;
  fct[1] = &cmd_list;
  fct[2] = &cmd_join;
  fct[3] = &cmd_part;
  fct[4] = &cmd_users;
  fct[5] = &cmd_msg;
  fct[6] = &cmd_send_file;
  fct[7] = &cmd_accept_file;
  fct[8] = &cmd_names;
  fct[9] = &cmd_quit;
}
