/*
** basic_functions.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on Tue May 17 10:33:40 2016 Christophe Ploujoux
** Last update  Tue May 17 10:33:40 2016 Christophe Ploujoux
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

char	**split_cmd(char *str, const char *sep)
{
  char	**tab;
  char	*save;
  int	i;

  if (!str)
    return (NULL);
  tab = NULL;
  save = strtok(str, sep);
  i = 0;
  while (save)
    {
      tab = realloc(tab, sizeof(char *) * ++i);
      tab[i - 1] = save;
      save = strtok(NULL, sep);
    }
  if (i == 0)
    return (NULL);
  tab = realloc(tab, sizeof(char *) * (i + 1));
  tab[i] = NULL;
  return (tab);
}

void  my_cmd(char **cmd)
{
  int i;

  i = 0;
  while (cmd[i]) {
    printf("%s ", cmd[i]);
    i++;
  }
  printf("\n");
}
