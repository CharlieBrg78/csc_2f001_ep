#include <stdio.h>
#include "monster.h"
#include "macro.h"


int main() {
    struct monster* monsters[10];
    char buf[NAME_SIZE];
    for (int i = 0; i < 10; i++) {
        snprintf(buf, NAME_SIZE, "Pikachu-%d", i);
        struct monster* m = create_monster(buf, 25);
        monsters[i] = m;
    }
    for (int i = 0; i < 10; i++) {
        display_monster(monsters[i]);
    }
    for (int i = 0; i < 10; i++) {
        delete_monster(monsters[i]);
    }
    return 0;
}