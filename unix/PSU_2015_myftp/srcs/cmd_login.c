/*
** cmd.c for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/srcs
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Thu May	12 11:10:39 2016 Christophe Ploujoux
** Last update	Thu May	12 11:10:39 2016 Christophe Ploujoux
*/

#include <string.h>
#include <sys/stat.h>
#include "server.h"

void	cmd_user(t_client *client)
{
  if (client->cmd[1])
    {
      if (client->status != 2)
	{
	  client->name = client->cmd[1];
	  client->status = 1;
	  my_putstr(client->sock, "331 Please specify the password");
	}
      else
	my_putstr(client->sock, "530 Can't change from guest user");
    }
  else
    my_putstr(client->sock, "530 Permission denied");
}

void	cmd_pass(t_client *client)
{
  if (client->status == 1)
    {
      if (!client->cmd[1] && strcmp(client->name, "Anonymous") == 0)
	{
	  client->status = 2;
	  my_putstr(client->sock, "230 Login successful");
	}
      else
	{
	  client->status = 0;
	  my_putstr(client->sock, "530 Login incorrect");
	}
    }
  else if (client->status == 2)
    my_putstr(client->sock, "230 Already logged in");
  else
    my_putstr(client->sock, "503 Login with USER first");
}

void	cmd_quit(t_client *client)
{
  my_putstr(client->sock, "221 Thanks for comming bye, see you next time");
  exit(0);
}

void	cmd_dele(t_client *client)
{
  if (client->cmd[1])
    {
      if (remove(client->cmd[1]) == -1)
	my_putstr(client->sock, "550 Failed to remove file");
      else
	my_putstr(client->sock, "250 File as been removed");
    }
  else
  my_putstr(client->sock, "501 Failed to remove file");
}
