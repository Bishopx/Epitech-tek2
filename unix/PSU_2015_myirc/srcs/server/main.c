/*
** main.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/server
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on Tue May 17 10:31:27 2016 Christophe Ploujoux
** Last update  Tue May 17 10:31:27 2016 Christophe Ploujoux
*/

#include <unistd.h>
#include <string.h>
#include "server.h"

int		main(int argc, char **argv)
{
  int		i;
  t_server	server;

  if (check_arg(argc, argv) == -1)
    return (1);
  i = 0;
  while (i < MAX_USER)
    server.users[i++].fd = -1;
  server.port = atoi(argv[1]);
  server.max_fd = 0;
  server.cmd_list = fill_list();
  server.channel = NULL;
  add_server(&server);
  handle_server(&server);
  return (0);
}
