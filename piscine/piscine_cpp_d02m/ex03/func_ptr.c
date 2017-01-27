/*
** func_ptr.c for func_ptr in /home/ploujo_c/tek2/Piscine/piscine_cpp_d02m/ex03
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Thu Jan  7 16:49:58 2016 Christophe Ploujoux
** Last update Thu Jan  7 17:56:27 2016 Christophe Ploujoux
*/

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "func_ptr.h"

void print_normal(char *str)
{
  printf("%s\n", str);
}

void print_reverse(char *str)
{
  int	i;

  i = strlen(str) - 1;
  while (i >= 0)
    printf("%c", str[i--]);
  printf("\n");
}

void	print_upper(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      printf("%c", toupper(str[i]));
      i++;
    }
  printf("\n");
}

void	print_42(char *str)
{
  if (str != NULL)
    str = NULL;
  printf("42\n");
}

void	do_action(t_action action, char *str)
{
  int	i;
  tab_func_ptr	tab_func[] =
    {
      { 0, &print_normal},
      { 1, &print_reverse},
      { 2, &print_upper },
      { 3, &print_42 },
      { 4, 0 },
    };
  for (i=0; tab_func[i].action != 4; i++)
    {
      if (action == tab_func[i].action)
	{
	  (*tab_func[i].func_ptr)(str);
	  return;
        }
    }
}
