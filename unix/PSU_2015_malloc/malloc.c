/*
** malloc.c for malloc in /home/ploujo_c/tek2/unix/PSU_2015_malloc
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Mon Feb	1 15:19:17 2016 Christophe Ploujoux
** Last update	Mon Feb	1 15:19:17 2016 Christophe Ploujoux
*/

#include "my.h"

void *base = NULL;

t_block		*find(t_block **last, size_t size) 
{
  t_block	*block;

  block = (t_block *) base;
  while (block && (block->free == FALSE || block->size < size))
    {
      *last = block;
      block = block->next;
    }
  return (block);
}

t_block		*extend(t_block *last, size_t size)
{
  t_block	*block;

  block = (t_block *)sbrk(0);
  if (sbrk(size + BLOCK_SIZE) == (void *) -1)
    return (NULL);
  if (last)
    last->next = block;
  block->size = size;
  block->next = NULL;
  block->free = FALSE;
  return (block);
}

void		*malloc(size_t size)
{
  t_block	*block;
  t_block	*last;

  if (size <= 0)
    return NULL;
  size = (((size - 1) / 4) * 4) + 4;
  if (!base)
    {
      if (!(block = extend(NULL, size)))
	return NULL;
      base = block;
    }
  else
    {
      last = (t_block *) base;
      if (!(block = find(&last, size)))
	{
	  if (!(block = extend(last, size)))
	    return NULL;
	}
      else
	block->free = FALSE;
    }
  return (block + 1);
}

