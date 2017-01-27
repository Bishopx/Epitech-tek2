/*
** simple_list.c for simple_list in /home/ploujo_c/tek2/Piscine/piscine_cpp_d02a/ex00
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Thu Jan  7 18:52:36 2016 Christophe Ploujoux
** Last update Thu Jan  7 21:24:03 2016 Christophe Ploujoux
*/

#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"

unsigned int list_get_size(t_list list)
{
  unsigned int	i;

  i = 0;
  while (list != NULL)
    {
      list = list->next;
      i++;
    }
  return (i);
}

t_bool	list_is_empty(t_list list)
{
  if (list == NULL)
    return TRUE;
  else
    return FALSE;
}

void	list_dump(t_list list)
{
  t_list	tmp;

  tmp = list;
  while (tmp != NULL)
    {
      printf("%f\n", tmp->value);
      tmp = tmp->next;
    }
}

t_bool		list_add_elem_at_front(t_list *front_ptr, double elem)
{
  t_list	list;

  list = malloc(sizeof(front_ptr));
  if (list == NULL)
    return FALSE;
  list->value = elem;
  list->next = *front_ptr;
  *front_ptr = list;
  return TRUE;
}

t_bool		list_add_elem_at_back(t_list *front_ptr, double elem)
{
  t_list	list;
  t_list	tmp;

  list = malloc(sizeof(list));
  list->value = elem;
  list->next = NULL;
  if (*front_ptr == NULL) {
    *front_ptr = list;
    return FALSE;
  }
  else {
    tmp = *front_ptr;
    while (tmp->next != NULL)
      tmp = tmp->next;
    tmp->next = list;
    return TRUE;
  }
}

t_bool	list_add_elem_at_position(t_list *front_ptr, double elem, unsigned int position)
{

}

t_bool list_del_elem_at_front(t_list *front_ptr)
{
  t_list	elem;

  if (*front_ptr != NULL)
    {
      elem = (*front_ptr)->next;
      free(*front_ptr);
      *front_ptr = elem;
      return TRUE;
    }
  return FALSE;
}

t_bool list_del_elem_at_back(t_list *front_ptr)
{
  t_list	tmp;
  t_list	elem;

  tmp = *front_ptr;
  elem = *front_ptr;
  if (*front_ptr == NULL)
    return FALSE;
  while (tmp->next != NULL)
    {
      elem = tmp;
      tmp = tmp->next;
    }
  elem->next = NULL;
  free(tmp);
  return TRUE;
}

t_bool list_del_elem_at_position(t_list *front_ptr, unsigned int position)
{

}

double list_get_elem_at_front(t_list list)
{
  t_list	tmp;

  if (list == NULL)
    return (0);
  return list->value;
}

double list_get_elem_at_back(t_list list)
{
  while (list->next)
    list = list->next;
  printf("%d\n", list->value);
}

double list_get_elem_at_postion(t_list list, unsigned int position)
{

}

t_node *list_get_first_node_with_value(t_list list, double value)
{

}

int main()
{
  t_list list_head = NULL;
  unsigned int size;
  double i = 5.2;
  double j = 42.5;
  double k = 3.3;

  list_add_elem_at_front(&list_head, i);
  list_add_elem_at_front(&list_head, j);
  list_add_elem_at_front(&list_head, k);

  size = list_get_size(list_head);
  printf("Il y a %u elements dans la liste\n", size);
  list_del_elem_at_back(&list_head);
  list_dump(list_head);
  printf("elem front : %d\n", list_get_elem_at_back(list_head));
  list_del_elem_at_front(&list_head);
  size = list_get_size(list_head);
  printf("Il y a %u elements dans la liste\n", size);
  list_dump(list_head);

 return (0);
}
