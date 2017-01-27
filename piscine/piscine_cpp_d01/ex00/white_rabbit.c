/*
** white_rabbit.c for white_rabbit in /home/ploujo_c/tek2/Piscine/piscine_cpp_d01/ex00
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Wed Jan  6 10:14:18 2016 Christophe Ploujoux
** Last update Thu Jan  7 01:28:43 2016 Christophe Ploujoux
*/

#include <stdlib.h>
#include <stdio.h>

int	follow_the_white_rabbit() {
  int	i;
  int	rand;
  int	j;

  i = 0;
  j = 0;
  while (i <= 397 && j != 1) {
    rand = random() % 37 + 1;
    if (rand == 37 || rand == 1)
      j = 1;
    if (rand == 4 || rand == 5 || rand == 6 || rand == 17 || rand == 18 
	     || rand == 19 || rand == 20 || rand == 21 || rand == 28)
      printf("gauche\n");
    if (rand == 13 || rand == 34 || rand == 35 || rand == 36)
      printf("droite\n");
    if (rand == 8 || rand == 16 || rand == 24 || rand == 26 || rand == 32)
      printf("derriere\n");
    if (rand == 23 || rand == 10 || rand == 15)
      printf("devant\n");
    i = i + rand;
  }
  printf("LAPIN !!!\n");
  return (i);
}
