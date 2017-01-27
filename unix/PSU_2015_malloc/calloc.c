/*
** calloc.c for calloc in /home/ploujo_c/tek2/unix/PSU_2015_malloc
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@ploujo-HP-EliteBook-840-G1>
** 
** Started on  Thu Feb  4 14:21:33 2016 Christophe Ploujoux
** Last update Thu Feb  4 14:52:29 2016 Christophe Ploujoux
*/

#include "my.h"

void	*calloc(size_t nmemb, size_t size)
{
  void	*ptr;

  if (size == 0 || nmemb == 0)
  	return (NULL);
  if ((ptr = malloc(size * nmemb)) == NULL)
    return (NULL);
  memset(ptr, 0, size * nmemb);
  return (ptr);
}
