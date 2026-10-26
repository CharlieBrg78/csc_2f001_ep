#include <stdio.h>
#include "monster.h"


int main() {
    struct monster* m = create_monster("Pikachu", 25);
    display_monster(m);
    delete_monster(m);
    return 0;
}