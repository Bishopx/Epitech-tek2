/*
** rest.c for philo in /home/ploujo_c/tek2/unix/PSU_2015_philo
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Thu Mar	3 20:41:38 2016 Christophe Ploujoux
** Last update	Thu Mar	3 20:41:38 2016 Christophe Ploujoux
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "extern.h"
#include "philosophe.h"

void 	rest(t_philo *philo)
{
  lphilo_sleep();
  philo->state = REST;
}
