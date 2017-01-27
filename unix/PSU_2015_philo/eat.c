/*
** eat.c for philo in /home/ploujo_c/tek2/unix/PSU_2015_philo
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Thu Mar	3 20:40:36 2016 Christophe Ploujoux
** Last update	Thu Mar	3 20:40:36 2016 Christophe Ploujoux
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "extern.h"
#include "philosophe.h"

void 	eat(t_philo *philo)
{
  pthread_mutex_lock(philo->lft);
  pthread_mutex_lock(philo->rht);
  philo->turn++;
  philo->state = EAT;
  lphilo_take_chopstick(philo->rht);
  lphilo_take_chopstick(philo->lft);
  lphilo_eat();
  usleep(TIME_EAT);
  lphilo_release_chopstick(philo->rht);
  lphilo_release_chopstick(philo->lft);
  pthread_mutex_unlock( philo->rht);
  pthread_mutex_unlock( philo->lft);

}
