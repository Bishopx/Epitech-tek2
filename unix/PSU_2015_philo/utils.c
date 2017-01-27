/*
** utils.c for philo in /home/ploujo_c/tek2/unix/PSU_2015_philo
** 
** Made by Christophe Ploujoux
** Login	 <ploujo_c@epitech.net>
** 
** Started on	Thu Mar	3 14:19:05 2016 Christophe Ploujoux
** Last update	Thu Mar	3 14:19:05 2016 Christophe Ploujoux
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	pars_turn(char **av)
{
  int	i;
  int	save;

  i = 1;
  while (av[i])
    {
      if (strcmp("-e", av[i]) == 0)
	if ((save = atoi(av[i + 1])) <= 0)
	  {
	    printf("Number of occurence before a philosopher");
	    printf(" quits the program must be positive\n");
	    exit(82);
	  }
      i++;
    }
  return (save);
}

int 	pars_philo(char **av)
{
  int	i;
  int	save;

  i = 1;
  while (av[i])
    {
      if (strcmp("-p", av[i]) == 0) {
	if ((save = atoi(av[i + 1])) <= 1)
	  {
	    printf("Number of philosophe must be superior to 1\n");
	    exit (82);
	  }
      }
      i++;
    }
  return (save);
}
