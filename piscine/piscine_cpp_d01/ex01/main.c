/*
** main.c for menger in /home/ploujo_c/tek2/Piscine/piscine_cpp_d01/ex01
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Wed Jan  6 14:07:19 2016 Christophe Ploujoux
** Last update Wed Jan  6 20:45:22 2016 Christophe Ploujoux
*/

#include <stdio.h>
#include <math.h>
#include "my.h"

int	my_getnbr(char *str)
{
  int	nb;
  int	signe;
  int	pos;

  nb = 0;
  pos = 0;
  signe = 1;
  while (str[pos] == '-')
    {
      signe = signe * -1;
      pos = pos + 1;
    }
  while (str[pos] != '\0')
    {
      if (str[pos] < '0' || str[pos] > '9')
	return (nb * signe);
      nb = nb * 10 + (str[pos] - '0');
      pos = pos + 1;
    }
  return (nb * signe);
}

int	main(int argc, char** argv) {
  int	size;
  int	level;

  if (argc != 3)
    printf("Le programme nécessite 2 arguments : [taille] [level]\n");
  else {
    size = my_getnbr(argv[1]);
    level = my_getnbr(argv[2]);
    if (size / 3 % 3 != 0 && size != 3)
      printf("La taille des carrées doit être une puissance de 3\n");
    else if (level > log((double) size) / log((double) 3))
      printf("Le level doit être inférieur ou égale à la puissance de 3 de la taille\n");
    else if (size == 0 || level == 0)
      printf("\n");
    else
      menger(size, level, 0, 0);
  }
  return (0);
}
