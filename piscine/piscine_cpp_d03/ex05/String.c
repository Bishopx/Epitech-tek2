/*
** String.c for String in /home/ploujo_c/tek2/piscine/piscine_cpp_d03/ex00
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Fri Jan  8 09:36:11 2016 Christophe Ploujoux
** Last update Sat Jan  9 00:21:44 2016 Christophe Ploujoux
*/

#include <string.h>
#include <stdio.h>
#include "String.h"

static void	assign_s(struct String *this, struct String const *str);
static void	assign_c(struct String *this, char const *s);
static void	append_c(struct String *this, char const *s);
static void	append_s(struct String *this, struct String const *str);
static char	at(struct String *this, size_t pos);
static void	clear(struct String *this);
static int	size(struct String *this);
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
  this->append_c = &append_c;
  this->append_s = &append_s;
  this->at = &at;
  this->clear = &clear;
  this->size = &size;
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

static void	append_s(String *this, String const *ap)
{
  strcat(this->str, ap->str);
}

static void	append_c(String *this, char const *ap)
{
  strcat(this->str, ap);
}

static char	at(String *this, size_t pos)
{
  if (pos > strlen(this->str))
    return (-1);
  else
    return (this->str[pos]);
}

static void	clear(String *this)
{
  memset(this->str, 0, strlen(this->str));
}

static int	size(String *this)
{
  if (this->str == NULL)
    return (-1);
  else
    return (strlen(this->str));
}
