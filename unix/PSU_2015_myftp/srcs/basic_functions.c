/*
** basic_functions.c for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/srcs
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Wed May	11 16:19:03 2016 Christophe Ploujoux
** Last update	Wed May	11 16:19:03 2016 Christophe Ploujoux
*/

#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

void	my_putstr(int fd, char *str)
{
  write(fd, str, strlen(str));
  write(fd, "\r\n", strlen("\r\n"));
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*str;

  i = 0;
  j = 0;
  if (!(str = malloc(sizeof(str) * (strlen(dest) + strlen(src) + 1))))
    return (NULL);
  while (dest[i])
    {
      str[i] = dest[i];
      i++;
    }
  if (dest[strlen(dest) - 1] != '/')
    str[i++] = '/';
  while (src[j])
    {
      str[i] = src[j];
      i++;
      j++;
    }
  str[i] = '\0';
  return (str);
}

void	change_path(t_client *client)
{
  int	i;
  char	*tmp;
  int	save;
  int	count;

  i = 0;
  save = 0;
  count = 0;
  tmp = client->path;
  while (tmp[i]) {
    if (tmp[i] == '/') {
      count++;
      save = i;
    }
    i++;
  }
  if (count == 1)
    tmp[save + 1] = '\0';
  else
    tmp[save] = '\0';
  client->path = strdup(tmp);
}

char	**split_cmd(char *str)
{
  char	**tab;
  char	*save;
  int	i;

  tab = NULL;
  save = strtok(str, " \r\n");
  i = 0;
  while (save)
    {
      tab = realloc(tab, sizeof(char *) * ++i);
      tab[i - 1] = save;
      save = strtok(NULL, " \r\n");
    }
  if (i == 0)
    return (NULL);
  tab = realloc(tab, sizeof(char *) * (i + 1));
  tab[i] = NULL;
  return (tab);
}

void	init_cmd_connected(void (*fct[14])(t_client *))
{
  fct[0] = &cmd_user;
  fct[1] = &cmd_pass;
  fct[2] = &cmd_quit;
  fct[3] = &cmd_pwd;
  fct[4] = &cmd_help;
  fct[5] = &cmd_pasv;
  fct[6] = &cmd_port;
  fct[7] = &cmd_noop;
  fct[8] = &cmd_cwd;
  fct[9] = &cmd_cdup;
  fct[10] = &cmd_dele;
  fct[11] = &execute_transfert;
  fct[12] = &execute_transfert;
  fct[13] = &execute_transfert;
}
