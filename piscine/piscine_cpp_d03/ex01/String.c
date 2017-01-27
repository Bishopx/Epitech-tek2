/*
** String.c for String in /home/ploujo_c/tek2/piscine/piscine_cpp_d03/ex00
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Fri Jan  8 09:36:11 2016 Christophe Ploujoux
** Last update Fri Jan  8 12:41:02 2016 Christophe Ploujoux
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "String.h"

static void	assign_s(struct String *this, struct String const *str);
static void	assign_c(struct String *this, char const *s);
static void	FuncPtr(struct String *this);

void	StringInit(String *this, char const *s)
{
  this->str = strdup(s);
  FuncPtr(this);
}

static void FuncPtr(String *this)
{
  this->assign_c = &assign_c;
  this->assign_s = &assign_s;
}

void	StringDestroy(String *this)
{
  free(this->str);
}

static void	assign_s(String *this, String const *str)
{
  this->str = strdup(str->str);
}

static void	assign_c(String *this, char const *s)
{
  this->str = strdup(s);
}
