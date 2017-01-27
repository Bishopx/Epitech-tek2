/*
** think.c for philo in /home/ploujo_c/tek2/unix/PSU_2015_philo
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Fri Mar	4 10:52:19 2016 Christophe Ploujoux
** Last update	Fri Mar	4 10:52:19 2016 Christophe Ploujoux
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "extern.h"
#include "philosophe.h"

void 		think(t_philo *philo)
{
  philo->state = THINK;
  pthread_mutex_lock(philo->rht);
  lphilo_take_chopstick(philo->rht);
  lphilo_think();
  usleep(TIME_THINK);
  lphilo_release_chopstick(philo->rht);
  pthread_mutex_unlock(philo->rht);
}
