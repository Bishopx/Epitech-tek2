/*
** mem_ptr.c for mem_ptr in /home/ploujo_c/tek2/Piscine/piscine_cpp_d02m/ex01
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Thu Jan  7 10:28:43 2016 Christophe Ploujoux
** Last update Thu Jan  7 10:57:50 2016 Christophe Ploujoux
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem_ptr.h"

void	add_str(char *str1, char *str2, char **res)
{
  *res = malloc(strlen(str1) + strlen(str2) + 1);
  strcpy(*res, str1);
  strcat(*res, str2);
}

void	add_str_struct(t_str_op *str_op)
{
  str_op->res = malloc(strlen(str_op->str1) + strlen(str_op->str2) + 1);
  strcpy(str_op->res, str_op->str1);
  strcat(str_op->res, str_op->str2);
}
