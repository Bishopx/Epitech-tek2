/*
**	 my.h for malloc in /home/ploujo_c/tek2/unix/PSU_2015_malloc
**	 
**	 Made by Christophe Ploujoux
**	 Login	 <ploujo_c@epitech.net>
**	 
**	 Started on	Thu Jan	28 14:36:45 2016 Christophe Ploujoux
**	 Last update	Thu Jan	28 14:36:45 2016 Christophe Ploujoux
*/

#ifndef MY_H_
# define MY_H_

# include <unistd.h>
# include <string.h>

# define BLOCK_SIZE sizeof(t_block)

typedef enum s_bool {
	FALSE,
	TRUE
} s_bool;

typedef struct		s_block {
  size_t		size;
  struct s_block	*next;
  s_bool			free;
}			t_block;

t_block		*find(t_block **, size_t);
t_block		*extend(t_block *, size_t);
void		*malloc(size_t);
void		free(void *);
void		*realloc(void *, size_t);
void		*calloc(size_t, size_t);

#endif /* !MY_H_ */
