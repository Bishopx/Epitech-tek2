/*
** cmd_basic.c for cmd_basic in /home/ploujo_c/tek2/unix/PSU_2015_myftp/bonus
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@ploujo-HP-EliteBook-840-G1>
** 
** Started on  Sat May 14 19:50:35 2016 Christophe Ploujoux
** Last update Sun May 15 00:11:44 2016 Christophe Ploujoux
*/

#include "client.h"

void	cmd_pwd(t_server *server)
{
  my_putstr(server->sock, "PWD\r\n");
  printf("%s\n", get_next_line(server->sock));
}

void	cmd_cd(t_server *server)
{
  if (server->cmd[1])
    {
      my_putstr(server->sock, "CWD ");
      my_putstr(server->sock, server->cmd[1]);
      my_putstr(server->sock, CRLF);
      printf("%s\n", get_next_line(server->sock));
    }
  else
    printf("Please indicate a path\n");
}

void	cmd_quit(t_server *server)
{
  my_putstr(server->sock, "QUIT\r\n");
  printf("%s\n", get_next_line(server->sock));
  exit(0);
}

void	cmd_delete(t_server *server)
{
  if (!server->cmd[1])
    printf("Please select a file to remove from the ftp server\n");
  else
    {
      my_putstr(server->sock, "DELE ");
      my_putstr(server->sock, server->cmd[1]);
      my_putstr(server->sock, CRLF);
      printf("%s\n", get_next_line(server->sock));
    }
}
