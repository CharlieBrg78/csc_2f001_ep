#ifndef KEYWORD_H
#define KEYWORD_H

#include "node.h"

struct keyword_t : node_t {
    std::string id;

    keyword_t(std::string id);

    std::string to_string();
};

// (+ a b c ...)
struct add_t : keyword_t {
    add_t();
    node_t* apply(list_t* list, frame_t* frame);
};

// (set! var expr)
struct set_t : keyword_t {
    set_t();
    node_t* apply(list_t* list, frame_t* frame);
};

#endif // KEYWORD_H
