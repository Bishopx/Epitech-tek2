/*
** new.c for new in /home/ploujo_c/tek2/piscine/cpp_SKL/ex_01
**
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
**
** Started on  Sat Jan  9 11:16:47 2016 Christophe Ploujoux
** Last update Sat Jan  9 12:54:45 2016 Christophe Ploujoux
*/

#include "raise.h"
#include "point.h"
#include <stdlib.h>
#include <string.h>

Object* new(Class *class, ...)
{
  if ((class = malloc(sizeof(class->__size__))) == NULL)
    raise("Out of memory");
  Point->__init__(class);
  return (class);
}

Object* va_new(Class* class, va_list* ap)
{

}

void	delete(Object *ptr)
{
  Point->__del__(ptr);
  free(ptr);
}
