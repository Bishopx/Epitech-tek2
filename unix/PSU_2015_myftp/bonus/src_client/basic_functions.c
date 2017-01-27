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
#include "client.h"

void	my_putstr(int fd, char *str)
{
  write(fd, str, strlen(str));
}

int   read_code(char *str)
{
  char buffer[3];

  buffer[0] = str[0];
  buffer[1] = str[1];
  buffer[2] = str[2];
  return (atoi(buffer));
}

char  *my_strcat(char *dest, char *src)
{
  int i;
  int j;
  char  *str;

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

void  change_path(t_server *server)
{
  int i;
  char  *tmp;
  int save;
  int count;

  i = 0;
  save = 0;
  count = 0;
  tmp = server->path;
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
  server->path = strdup(tmp);
}

char	**split_cmd(char *str)
{
  char	**tab;
  char	*save;
  int	i;

  tab = NULL;
  if (strlen(str) == 0)
    return (NULL);
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
