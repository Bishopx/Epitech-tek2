/*
** cmd_connected.c for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/srcs
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Thu May	12 20:14:17 2016 Christophe Ploujoux
** Last update	Thu May	12 20:14:17 2016 Christophe Ploujoux
*/

#include <string.h>
#include <unistd.h>
#include "server.h"

void	cmd_pwd(t_client *client)
{
  char	*tmp;

  if (!(tmp = malloc(sizeof(char) * (strlen("257 \"")
				     + strlen(client->path) + 1))))
    return;
  tmp = strcat(tmp, "257 \"");
  tmp = strcat(tmp, client->path);
  tmp = strcat(tmp, "\"");
  my_putstr(client->sock, tmp);
  free(tmp);
}

void	cmd_help(t_client *client)
{
  my_putstr(client->sock, "The following commands are recognized.");
  my_putstr(client->sock, "PWD HELP PASV PORT RETR STOR LIST NOOP CWD CDUP");
  my_putstr(client->sock, "214 Help OK.");
}

void	cmd_noop(t_client *client)
{
  my_putstr(client->sock, "200 NOOP ok.");
}

void	cmd_cwd(t_client *client)
{
  char	*tmp;

  if (client->cmd[1])
    {
      if (strcmp(client->cmd[1], "..") == 0)
	cmd_cdup(client);
      else {
	if (chdir(client->cmd[1]) == -1) {
	  my_putstr(client->sock, "550 failed to change directory");
	  return;
	}
	tmp = my_strcat(client->path, client->cmd[1]);
	client->path = strdup(tmp);
	my_putstr(client->sock, "250 Directory successfully changed");
      }
    }
  else
    my_putstr(client->sock, "501 Failed to change directory.");
}

void	cmd_cdup(t_client *client)
{
  if (strcmp(client->path, "/") != 0)
    chdir("..");
  change_path(client);
  my_putstr(client->sock, "200 Directory successfully changed");
}
