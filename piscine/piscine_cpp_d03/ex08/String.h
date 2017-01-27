/*
** String.h for String in /home/ploujo_c/tek2/piscine/piscine_cpp_d03/ex00
** 
** Made by Christophe Ploujoux
** Login   <ploujo_c@epitech.net>
** 
** Started on  Fri Jan  8 09:36:21 2016 Christophe Ploujoux
** Last update Sat Jan  9 01:00:18 2016 Christophe Ploujoux
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
  int	(*compare_c)(struct String *a, const char *str);
  int	(*compare_s)(struct String *a, struct String const *b);
  size_t (*copy)(struct String *a, char *s, size_t n, size_t pos);
  const char *(*c_str)(struct String *a); 
}		String;

void	StringInit(String *this, char const *s);
void	StringDestroy(String *this);

#endif /* !_STRING_H */
