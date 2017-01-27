/*
** mul_div.c for Add Mul in /home/ploujo_c/tek2/Piscine/piscine_cpp_d02m
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Thu Jan  7 10:14:30 2016 Christophe Ploujoux
** Last update Thu Jan  7 10:25:42 2016 Christophe Ploujoux
*/

#include <stdio.h>

void	add_mul_4param(int first, int second, int *add, int *mul)
{
  *add = first + second;
  *mul = first * second;
}

void	add_mul_2param(int *first, int *second)
{
  int	save;

  save = *first;
  *first = save + *second;
  *second = save * *second;
}
