/*
** tab_to_2dtab.c for tab_to_2dtab in /home/ploujo_c/tek2/Piscine/piscine_cpp_d02m/ex02
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Thu Jan  7 10:55:50 2016 Christophe Ploujoux
** Last update Thu Jan  7 18:14:29 2016 Christophe Ploujoux
*/

#include <stdlib.h>
#include <stdio.h>

void	tab_to_2dtab(int *tab, int length, int width, int ***res)
{
  int	i;
  int	k;

  i = 0;
  k = 0;
  *res = malloc(sizeof(int *) * length);
  while (i < length)
    {
      (*res)[i] = malloc(sizeof(int) * width);
      (*res)[i] = &tab[k];
 
      k += width;
      i++;
    }
}
