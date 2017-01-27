/*
** String.h for String in /home/ploujo_c/tek2/piscine/piscine_cpp_d03/ex00
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Fri Jan  8 09:36:21 2016 Christophe Ploujoux
** Last update Fri Jan  8 12:17:53 2016 Christophe Ploujoux
*/

#ifndef _STRING_H_
# define _STRING_H_

# include <stdlib.h>

typedef struct	String
{
  char		*str;

  void	(*assign_s)(struct String *a, struct String const *b);
  void	(*assign_c)(struct String *a, const char *s);
  void	(*append_c)(struct String *a, const char *s);
  void	(*append_s)(struct String *a, struct String const *b);
  char	(*at)(struct String *a, size_t pos);
  void	(*clear)(struct String *a);
  int	(*size)(struct String *a);
}		String;

void	StringInit(String *this, char const *s);
void	StringDestroy(String *this);

#endif /* !_STRING_H */
