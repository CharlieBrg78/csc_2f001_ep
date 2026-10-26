#ifndef _MONSTER_H_
#define _MONSTER_H_

struct monster {
    char* name;
    int hp;
};

struct monster* create_monster(char* name,int hp);

void display_monster(struct monster*);

void delete_monster(struct monster*);

#endif