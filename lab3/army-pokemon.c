#include <stdlib.h>
#include "army.h"

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
        for (int i = 0; i < a->top; i++) {
            new_monsters[i] = a->monsters[i];
        }
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

main.c: add #include "army.h". Create the army, add each Pikachu to it in the first loop, and replace the display loop with display_army:

c
#include <stdio.h>
#include "monster.h"
#include "army.h"

int main() {
    struct monster* monsters[10];
    struct army* army = create_army();
    char buf[NAME_SIZE];
    for (int i = 0; i < 10; i++) {
        snprintf(buf, NAME_SIZE, "Pikachu-%d", i);
        struct monster* m = create_monster(buf, 25);
        monsters[i] = m;
        add_monster_to_army(army, m);
    }
    display_army(army);
    delete_army(army);
    for (int i = 0; i < 10; i++) {
        delete_monster(monsters[i]);
    }
    return 0;
}