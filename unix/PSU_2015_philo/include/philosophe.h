/*
** philosophe.h for philo in /home/ploujo_c/tek2/unix/PSU_2015_philo/include
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Thu Mar	3 13:46:02 2016 Christophe Ploujoux
** Last update	Thu Mar	3 13:46:02 2016 Christophe Ploujoux
*/

#ifndef PHILOSOPHE_H_
# define PHILOSOPHE_H_

# include <pthread.h>

# define TIME_THINK	5
# define TIME_EAT	5
# define TIME_SLEEP	5

typedef enum	s_state
{
		EAT,
		THINK,
		REST
}		t_state;

typedef struct		s_philo
{
  pthread_mutex_t	*lft;
  pthread_mutex_t	*rht;
  pthread_t		thread;
  t_state		state;
  unsigned int		turn;
  unsigned int 		index;
}			t_philo;

int 		pars_turn(char **);
int 		pars_philo(char **);
void 		rest(t_philo *);
void 		eat(t_philo *);
void 		think(t_philo *);

#endif /* !PHILOSOPHE_H_ */

