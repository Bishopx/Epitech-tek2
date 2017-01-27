#ifndef _EXO_1_H_
# define _EXO_1_H_

# include <stdlib.h>

typedef struct		s_cthulhu
{
  int				m_power;
  char				*name;

  void				(*CthulhuInitializer)(struct s_cthulhu* this);
}					t_cthulhu;

typedef struct 		s_koala
{
  t_cthulhu 		m_parent;
  char				m_isALegend;

  void				(*KoalaInitializer)(struct s_koala* this, char *, char);
}					t_koala;

  t_cthulhu	*NewCthulhu();
  t_koala		*NewKoala(char *name, char _isALegend);

  void        PrintPower(struct s_cthulhu *this);
  void        Attack(struct s_cthulhu *this);
  void        Sleeping(struct s_cthulhu *this);
  void        Eat(struct s_koala *this); 

// void	StringInit(String *this, char const *s);
// void	StringDestroy(String *this);

#endif /* !_EXO_1_H_ */
