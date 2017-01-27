/*
** String.c for String in /home/ploujo_c/tek2/piscine/piscine_cpp_d03/ex00
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Fri Jan  8 09:36:11 2016 Christophe Ploujoux
** Last update Sat Jan  9 01:00:15 2016 Christophe Ploujoux
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
static size_t	copy(struct String *this, char *s, size_t n, size_t pos);
static char const *c_str(struct String *this);
static int	empty(struct String *list);
static int	find_s(struct String *list, struct String const *str, size_t pos);
static int	find_c(struct String *list, const char *str, size_t pos);
static void	insert_c(struct String *list, size_t pos, char const *str);
static void	insert_s(struct String *list, size_t pos, struct String const *str);
static int	to_int(struct String *list);
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
  this->compare_c = &compare_c;
  this->compare_s = &compare_s;
  this->copy = &copy;
  this->c_str = c_str;
  this->empty = &empty;
  this->find_s = &find_s;
  this->find_c = &find_c;
  this->insert_s = &insert_s;
  this->insert_c = &insert_c;
  this->to_int = &to_int;
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

static const char *c_str(String *this)
{
  return this->str;
}

static int	empty(String *this)
{
  if (strlen(this->str) == 0)
    return (1);
  else
    return (-1);
}

static int	find_s(String *this, String const *str, size_t pos)
{
  char		*test;

  if (pos + strlen(str->str) > strlen(this->str))
    return (-1);
  test = strstr(this->str + pos, str->str);
  if (strlen(test) == 0 || strlen(this->str + pos) <= strlen(str->str))
    return (-1);
  return (strlen(this->str + pos) - strlen(test));
}

static int	find_c(String *this, const char *str, size_t pos)
{
  char		*test;

  if (pos + strlen(str) > strlen(this->str))
    return (-1);
  printf("après verif\n");
  test = strstr(this->str + pos, str);
  if (test == NULL)
    return (-1);
  return (strlen(this->str + pos) - strlen(test));
}

static void	insert_s(String *this, size_t pos, String const *str)
{
  char		*test;
  char		*tmp;
  char		*tmp2;
  int		i = 0;

  if (strlen(this->str) <= pos)
    {
      test = malloc(strlen(this->str) + strlen(str->str));
      test = strcat(this->str, str->str);
      this->str = test;
    }
  else
    {
      tmp = malloc(strlen(this->str + pos));
      tmp = this->str + pos;
      tmp2 = malloc(pos);
      while (i < (int)pos) {
	tmp2[i] = this->str[i];
	i++;
      }
      test = strcat(tmp2, str->str);
      test = strcat(test, tmp);
      this->str = test;
    }
}

static void	insert_c(String *this, size_t pos, const char *str)
{
  char		*test;
  char		*tmp;
  char		*tmp2;
  int		i = 0;

  test = malloc(strlen(this->str) + strlen(str));
  if (strlen(this->str) <= pos)
    {
      test = strcat(this->str, str);
      this->str = test;
    }
  else
    {
      tmp = malloc(strlen(this->str + pos));
      tmp = this->str + pos;
      tmp2 = malloc(pos);
      while (i < (int)pos) {
	tmp2[i] = this->str[i];
	i++;
      }
      test = strcat(tmp2, str);
      test = strcat(test, tmp);
      this->str = test;
    }
}

static int	to_int(String *list)
{
  return atoi(list->str);
}
