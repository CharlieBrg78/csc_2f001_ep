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
