/*
** channel.h for channel in /home/ploujo_c/tek2/unix/PSU_2015_myirc
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@ploujo-HP-EliteBook-840-G1>
** 
** Started on  Wed May 25 13:21:04 2016 Christophe Ploujoux
** Last update Wed May 25 13:22:23 2016 Christophe Ploujoux
*/

#ifndef CHANNEL_H_
# define CHANNEL_H_

typedef enum e_bool
{
    FALSE,
    TRUE
}            t_bool;

typedef struct  s_chan
{
    char          *name;
    struct s_chan   *next;
}               t_chan;

typedef t_chan   *t_channel;

t_bool  list_add_elem_at_back(t_channel *front_ptr, char  *elem);
t_bool  list_del_elem_at_front(t_channel *front_ptr);
t_bool  list_del_elem_at_back(t_channel *front_ptr);
t_chan  *list_get_node(t_channel list, char  *value);
t_bool  deleteNode(t_channel *list, char  *value);

#endif /* !CHANNEL_H_ */
