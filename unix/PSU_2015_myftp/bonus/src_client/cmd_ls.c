/*
** cmd_ls.c for cmd_ls in /home/ploujo_c/tek2/unix/PSU_2015_myftp/bonus
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@ploujo-HP-EliteBook-840-G1>
** 
** Started on  Sat May 14 19:50:24 2016 Christophe Ploujoux
** Last update Sun May 15 00:13:07 2016 Christophe Ploujoux
*/

#include <unistd.h>
#include "client.h"

void	cmd_ls(t_server *server)
{
  char	str[10];
  int	buffer;

  connect_data(server);
  my_putstr(server->sock, "LIST\r\n");
  printf("%s\n", get_next_line(server->sock));
  while ((buffer = read(server->transfert.socket, str, 10)) > 0)
    write(1, str, buffer);
  printf("%s\n", get_next_line(server->sock));
}
