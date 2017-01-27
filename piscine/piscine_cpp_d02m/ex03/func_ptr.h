/*
** func_ptr.h for func_ptr in /home/ploujo_c/tek2/Piscine/piscine_cpp_d02m/ex03
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Thu Jan  7 16:48:38 2016 Christophe Ploujoux
** Last update Thu Jan  7 17:32:27 2016 Christophe Ploujoux
*/

#ifndef FUNC_PTR_H_
# define FUNC_PTR_H_

# include "func_ptr_enum.h"

typedef struct	tab_func_ptr
{
  t_action	action;
  void (*func_ptr)(char *);
}		tab_func_ptr;

#endif /* FUNC_PTR_H_ */
