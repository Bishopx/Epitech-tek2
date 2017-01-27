/*
** channel.c for myirc in /home/ploujo_c/tek2/unix/PSU_2015_myirc/srcs
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on Wed May 25 13:16:09 2016 Christophe Ploujoux
** Last update  Wed May 25 13:16:09 2016 Christophe Ploujoux
*/

#include <stdlib.h>
#include <string.h>
#include "channel.h"

t_bool		list_add_elem_at_back(t_channel *front_ptr, char *elem)
{
  t_channel	list;
  t_channel	tmp;

  if ((list = malloc(sizeof(list))) == NULL)
    return FALSE;
  list->name = strdup(elem);
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

t_bool list_del_elem_at_front(t_channel *front_ptr)
{
  t_channel	elem;

  if (*front_ptr != NULL)
    {
      elem = (*front_ptr)->next;
      free(*front_ptr);
      *front_ptr = elem;
      return TRUE;
    }
  return FALSE;
}

t_bool		list_del_elem_at_back(t_channel *front_ptr)
{
  t_channel	tmp;
  t_channel	elem;

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

t_chan		*list_get_node(t_channel list, char *name)
{
  t_channel	tmp;

  tmp = list;
  while (tmp) {
    if (strcmp(tmp->name, name) == 0)
      return tmp;
    tmp = tmp->next;
  }
  return NULL;
}

t_bool		deleteNode(t_channel *list, char *name)
{
  t_channel	tmp;
  t_channel	save;

  tmp = *list;
  if (strcmp(tmp->name, name) == 0)
    {
    list_del_elem_at_front(list);
    return TRUE;
  }
  while (tmp) {
    if (strcmp(tmp->name, name) == 0 && tmp->next) {
      save->next = tmp->next;
      free(tmp->name);
      free(tmp);
      return TRUE;
    }
    if (strcmp(tmp->name, name) == 0 && !tmp->next) {
      list_del_elem_at_back(list);
      return TRUE;
    }
    save = tmp;
    tmp = tmp->next;
  }
  return FALSE;
}
