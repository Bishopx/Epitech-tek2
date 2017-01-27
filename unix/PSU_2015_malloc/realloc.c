/*
** realloc.c for realloc in /home/ploujo_c/tek2/unix/PSU_2015_malloc
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@ploujo-HP-EliteBook-840-G1>
** 
** Started on  Thu Feb  4 14:21:27 2016 Christophe Ploujoux
** Last update Thu Feb  4 14:48:26 2016 Christophe Ploujoux
*/

#include "my.h"

void		*realloc(void *ptr, size_t size)
{
  t_block	*block;
  void		*new_ptr;

  if (!ptr)
    return (malloc(size));
  block = (t_block *)ptr - 1;
  if (block->size >= size)
    return ptr;
  if ((new_ptr = malloc(size)) == NULL)
    return NULL;
  memcpy(new_ptr, ptr, block->size);
  free(ptr);
  return new_ptr;
}
