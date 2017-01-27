/*
** String.c for String in /home/ploujo_c/tek2/piscine/piscine_cpp_d03/ex00
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Fri Jan  8 09:36:11 2016 Christophe Ploujoux
** Last update Sat Jan  9 00:22:43 2016 Christophe Ploujoux
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
static int	compare_s(struct String *this, struct String const *str);
static int	compare_c(struct String *this, char const *s);
static void	FuncPtr(struct String *this);
static size_t	copy(struct String *this, char *s, size_t n, size_t pos);

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
  this->compare_c = &compare_c;
  this->compare_s = &compare_s;
  this->copy = &copy;
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
  char		*str;

  str = malloc(strlen(this->str) + strlen(ap->str));
  str = strcat(this->str, ap->str);
  free(this->str);
  this->str = str;
}

static void	append_c(String *this, char const *ap)
{
  char		*str;

  str = malloc(strlen(this->str) + strlen(ap));
  str = strcat(this->str, ap);
  this->str = str;
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

static int	compare_c(String *this, char const *ap)
{
  return strcmp(this->str, ap);
}

static int	compare_s(String *this, String const *ap)
{
  return strcmp(this->str, ap->str);
}

static size_t	copy(String *this, char *s, size_t n, size_t pos)
{
  s = malloc(n);
  strncpy(s, this->str + pos, n);
  printf("%s\n", s);
  if (strlen(this->str) > pos + n)
    return (n);
  else
    return (pos + n - strlen(this->str));
}
