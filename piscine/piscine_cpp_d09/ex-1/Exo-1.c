#include <string.h>
#include <stdio.h>
#include "Exo-1.h"

static void   CthulhuInitializer(t_cthulhu *this);

static void   KoalaInitializer(t_koala* this, char* _name, char _isALegend);


/* Cthulhu */
t_cthulhu *NewCthulhu()
{
  t_cthulhu *this;

  printf("----\n");
  printf("Building Cthulhu\n");
  this = malloc(sizeof(*this));
  CthulhuInitializer(this);
  return this;
}


static void CthulhuInitializer(t_cthulhu *this) {
  this->name = strdup("Cthulhu");
  this->m_power = 42;
}
void Attack(t_cthulhu *this) {
  if (this->m_power >= 42)
  {
    printf("%s attacks and destroys the city\n", this->name);
    this->m_power -= 42;
  } else
    printf("%s can't attack, he doesn't have enough power\n", this->name);
}

void PrintPower(t_cthulhu *this) {
  printf("Power => %d\n", this->m_power);
}

void Sleeping(t_cthulhu *this) {
  this->m_power += 42000;
  printf("%s sleeps\n", this->name);
}

/* Koala */

t_koala *NewKoala(char *name, char _isALegend) {
  t_koala *this;

  printf("----\n");
  printf("Building Cthulhu\n");
  printf("Building %s\n", name);
  this = malloc(sizeof(*this));
  KoalaInitializer(this, name, _isALegend);
  return (this);
}

static void KoalaInitializer(t_koala *this, char *name, char legend) {
  this->m_isALegend = legend;
  this->m_parent.name = strdup(name);
  if (legend == 1)
    this->m_parent.m_power = 42;
  else
    this->m_parent.m_power = 0;
} 

void Eat(t_koala *this) {
  this->m_parent.m_power += 42;
  printf("%s eats\n", this->m_parent.name);
}
