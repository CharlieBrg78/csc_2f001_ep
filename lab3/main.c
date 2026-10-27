#include <stdio.h>
#include "monster.h"



int main() {
    struct monster* monsters[10];
    for(int i= 0; i < 10; i++) {
    struct monster* m = create_monster("Pikachu", 25);
    monsters[i] = m;
    }
    for(int i= 0; i < 10; i++) {
    display_monster(monsters[i]);
    }
    for(int i= 0; i < 10; i++) {
    delete_monster(monsters[i]);
    }
    return 0;
}