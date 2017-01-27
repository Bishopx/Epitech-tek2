/*
** free.c for free in /home/ploujo_c/tek2/unix/PSU_2015_malloc
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@ploujo-HP-EliteBook-840-G1>
** 
** Started on  Thu Feb  4 14:21:20 2016 Christophe Ploujoux
** Last update Mon Feb  8 19:25:29 2016 Christophe Ploujoux
*/

#include "my.h"

void		free(void *ptr)
{
  t_block	*block;

  if (!ptr)
    return;
  block = (t_block *) ptr - 1;
  block->free = TRUE;
}
