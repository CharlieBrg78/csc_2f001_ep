#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monster.h"
#include "macro.h"


struct monster* create_monster(char* name,int hp) {
    struct monster* m = malloc(sizeof(*m));
    strncpy(m->name, name, NAME_SIZE);
    m -> hp = hp;
    return m;
}

void display_monster(struct monster* m) {
    char* pname = m -> name;
    int php = m -> hp;
    printf("The monster %s has %d hp. \n", pname, php);
}

void delete_monster(struct monster* m) {
    free(m);
}