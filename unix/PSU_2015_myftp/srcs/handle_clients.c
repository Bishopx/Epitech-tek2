/*
** handle_clients.c for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/srcs
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Thu May	12 11:09:02 2016 Christophe Ploujoux
** Last update	Thu May	12 11:09:02 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include "server.h"

void	execute_transfert(t_client *client)
{
  if (client->transfert.transfert > 0)
    {
      if (strcmp(client->cmd[0], "RETR") == 0)
	cmd_retr(client);
      if (strcmp(client->cmd[0], "STOR") == 0)
	cmd_store(client);
      if (strcmp(client->cmd[0], "LIST") == 0)
	cmd_list(client);
    }
  else
    my_putstr(client->sock, "425 Use PORT or PASV first");
}

void	execute_loop(t_client *client)
{
  int	i;
  void	(*command[14])(t_client *client);

  init_cmd_connected(command);
  while (client->cmd_list[i])
    {
      if (i > 2 && client->status != 2)
	{
	  my_putstr(client->sock, "530 Login with USER and PASS first");
	  return;
	}
      if (strcmp(client->cmd_list[i], client->cmd[0]) == 0)
	{
	  command[i](client);
	  return;
	}
      i++;
    }
  my_putstr(client->sock, "500 Command not found");
}

void	execute(t_client *client)
{
  if (client->cmd == NULL)
    {
      if (client->status != 2)
	my_putstr(client->sock, "530 Login with USER and PASS first");
      else
	my_putstr(client->sock, "500 Command not found");
      return;
    }
  execute_loop(client);
}

void	handle_client(t_client *client)
{
  pid_t	pid;

  client->cmd_list = fill_list();
  if ((pid = fork()) == 0) {
    client->status = 0;
    client->path = strdup("/");
    my_putstr(client->sock, "220 Welcome to my FTP server");
    while (1) {
      client->cmd = split_cmd(get_next_line(client->sock));
      execute(client);
    }
  }
  else if (pid > 0)
    close(client->sock);
  else
    printf(SERVER_FAILED);
}
