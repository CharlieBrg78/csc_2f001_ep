#ifndef _ARMY_H_
#define _ARMY_H_
#include "monster.h"

struct army {
  struct monster** monsters; // a pointer to an array, where each element of the array is a pointer to a monster
  int top;                   // where you have the last monster in the array
  int capacity;              // the capacity of the array
};

struct army* create_army();

void add_monster_to_army(struct army* a, struct monster* m);

void display_army(struct army* a);

void delete_army(struct army* a);

#endif