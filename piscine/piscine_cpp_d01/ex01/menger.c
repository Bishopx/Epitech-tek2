/*
** menger.c for menger in /home/ploujo_c/tek2/Piscine/piscine_cpp_d01/ex01
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Wed Jan  6 14:07:30 2016 Christophe Ploujoux
** Last update Wed Jan  6 22:22:57 2016 Christophe Ploujoux
*/

#include <stdio.h>

int	menger(int size, int level, int x, int y) 
{
  int	s3;

  s3 = size / 3;
  if (level > 0 && level < size) 
    {
      level--;
      printf("%03i %03i %03i\n", s3, s3 + x, s3 + y);
      menger(s3, level, x, y);
      menger(s3, level, x, y + s3);
      menger(s3, level, x, y + 2 * s3);
      menger(s3, level, x + s3, y);
      menger(s3, level, x + s3, y + 2 * s3);
      menger(s3, level, x + 2 * s3, y);
      menger(s3, level, x + 2 * s3, y + s3);
      menger(s3, level, x + 2 * s3, y + 2 * s3);
    }
  return (0);
}
