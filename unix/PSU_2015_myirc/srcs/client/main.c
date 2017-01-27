/*
** main.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs/client
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Tue May	17 15:14:28 2016 Christophe Ploujoux
** Last update	Tue May	17 15:14:28 2016 Christophe Ploujoux
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "client.h"

int		main()
{
  t_server	server;

  server.channel = NULL;
  fill_list(&server);
  handle_server(&server);
  return 0;
}
