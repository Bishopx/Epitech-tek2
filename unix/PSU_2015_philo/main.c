/*
** main.c for philo in /home/ploujo_c/tek2/unix/PSU_2015_philo
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Thu Mar	3 13:46:22 2016 Christophe Ploujoux
** Last update	Thu Mar	3 13:46:22 2016 Christophe Ploujoux
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "extern.h"
#include "philosophe.h"

unsigned int 	philo_finished = 1;
unsigned int 	nb_philo;
unsigned int 	max_turn;

int			stop(t_philo *philo)
{
  unsigned int		i;

  i = 0;
  while (i < nb_philo)
    {
      if (philo[i].turn == max_turn)
	return (1);
      i++;
    }
  return (0);
}

void			*diner(void *arg)
{
  t_philo		*philo;

  philo = (t_philo *) arg;
  philo = philo;
  while (stop(philo) != 1)
    {
      if (philo->state != THINK && philo->state != REST)
	rest(philo);
      if (philo->state != THINK)
	think(philo);
      if (philo->state != EAT)
	eat(philo);
    }
  return arg;
}

t_philo			*init_philo(pthread_mutex_t *chipsticks)
{
  t_philo		*philo;
  unsigned int		i;

  if ((philo = (t_philo *) malloc(nb_philo * sizeof(t_philo))) == NULL)
    exit(82);
  i = 0;
  while (i < nb_philo)
    {
      philo[i].turn = 0;
      philo[i].state = REST;
      philo[i].index = i;
      philo[i].lft = &chipsticks[i];
      philo[i].rht = &chipsticks[(i + 1) % nb_philo];
      pthread_create(&philo[i].thread, NULL, diner, &philo[i]);
      i++;
    }
  return (philo);
}

void			begin()
{
  t_philo		*philo;
  unsigned int		i;
  pthread_mutex_t	chipsticks[nb_philo];

  i = 0;
  while (i < nb_philo)
    pthread_mutex_init(&chipsticks[i++], NULL);
  philo = init_philo(chipsticks);
  i = 0;
  while (i < nb_philo)
    {
      pthread_join(philo[i].thread, NULL);
      i++;
    }
}

int			 main(int ac, char **av)
{
  RCFStartup(ac, av);
  if (ac != 5)
    {
      printf("Usage ./philo -p [nb_philo] -e [nb_turn]\n");
      return (-1);
    }
  nb_philo = pars_philo(av);
  max_turn = pars_turn(av);
  begin();
  RCFCleanup();
  return (0);
}
