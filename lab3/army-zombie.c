#include <stdio.h>
#include <stdlib.h>
#include "army.h"

struct node {
  struct monster* monster;   // the monster stored in this node
  struct node* next;         // the next node of the list (NULL for the last one)
};

struct army {
  struct node* first;        // the first node of the list (NULL if the army is empty)
  struct node* last;         // the last node of the list, to add at the end without traversing
  int stars;                 // the number of stars of the army
};

struct army* create_army() {
    struct army* a = malloc(sizeof(*a));
    a->first = NULL;
    a->last = NULL;
    a->stars = 0;
    return a;
}

void add_monster_to_army(struct army* a, struct monster* m) {
    struct node* n = malloc(sizeof(*n));
    n->monster = m;
    n->next = NULL;
    if (a->first == NULL) {
        a->first = n;
    } else {
        a->last->next = n;
    }
    a->last = n;
}

void display_army(struct army* a) {
    printf("This is a %d stars army\n", a->stars);
    for (struct node* n = a->first; n != NULL; n = n->next) {
        display_monster(n->monster);
    }
}

void delete_army(struct army* a) {
    struct node* n = a->first;
    while (n != NULL) {
        struct node* next = n->next;
        free(n);
        n = next;
    }
    free(a);
}
