/*
** String.c for String in /home/ploujo_c/tek2/piscine/piscine_cpp_d03/ex00
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Fri Jan  8 09:36:11 2016 Christophe Ploujoux
** Last update Fri Jan  8 16:15:53 2016 Christophe Ploujoux
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "String.h"

void	StringInit(String *this, char const *s)
{
  this->str = strdup(s);
}

void	StringDestroy(String *this)
{
  free(this->str);
}
