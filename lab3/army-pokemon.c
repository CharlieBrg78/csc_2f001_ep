#include <stdlib.h>
#include <string.h>
#include "army.h"

struct army {
  struct monster** monsters; // a pointer to an array, where each element of the array is a pointer to a monster
  int top;                   // where you have the last monster in the array
  int capacity;              // the capacity of the array
};

struct army* create_army() {
    struct army* a = malloc(sizeof(*a));
    a->monsters = NULL;
    a->top = 0;
    a->capacity = 0;
    return a;
}

void add_monster_to_army(struct army* a, struct monster* m) {
    if (a->top == a->capacity) {
        int new_capacity;
        if (a->capacity == 0) {
            new_capacity = 1;
        } else {
            new_capacity = 2 * a->capacity;
        }
        struct monster** new_monsters = malloc(new_capacity * sizeof(struct monster*));
        memcpy(new_monsters, a->monsters, sizeof(*new_monsters) * a->top);
        free(a->monsters);
        a->monsters = new_monsters;
        a->capacity = new_capacity;
    }
    a->monsters[a->top] = m;
    a->top++;
}

void display_army(struct army* a) {
    for (int i = 0; i < a->top; i++) {
        display_monster(a->monsters[i]);
    }
}

void delete_army(struct army* a) {
    free(a->monsters);
    free(a);
}
