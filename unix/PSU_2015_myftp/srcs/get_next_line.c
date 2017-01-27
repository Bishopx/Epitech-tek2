/*
** get_next_line.c for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp/srcs
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on Fri May 13 18:52:12 2016 Christophe Ploujoux
** Last update  Fri May 13 18:52:12 2016 Christophe Ploujoux
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*my_realloc(char *old, int size)
{
  int	i;
  char	*new;
  int	len;

  i = 0;
  len = strlen(old) + 1;
  if ((new = malloc(len + size + 1)) == NULL)
    return (NULL);
  while (old[i])
    {
      new[i] = old[i];
      i++;
    }
  new[i] = '\0';
  free(old);
  return (new);
}

char	*get_next_line(const int fd)
{
  char	buff;
  int	i;
  int	rd;
  char	*line;

  i = 0;
  if ((line = malloc(sizeof(line) + 1)) == NULL)
    return (NULL);
  if ((rd = read(fd, &buff, 1)) <= 0)
    return (NULL);
  while (buff != '\n')
    {
      line = my_realloc(line, 1);
      line[i] = buff;
      read(fd, &buff, 1);
      i++;
    }
  line[i] = '\0';
  return (line);
}
