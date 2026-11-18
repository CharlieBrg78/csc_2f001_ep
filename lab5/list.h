#ifndef LIST_H
#define LIST_H

#include "node.h"

struct list_t : node_t {
    node_t** elements;
    size_t nb_elements;
    size_t capacity;

    list_t();

    list_t* as_list();
    size_t size();
    node_t* at(size_t i);
    void set_at(size_t i, node_t* value);
    void append(node_t* value);
    std::string to_string();
    node_t* eval(frame_t* frame);
};

// a call frame is a list of (symbol value) pairs
struct frame_t : list_t {
    void set(node_t* sym, node_t* value);
    node_t* get(node_t* sym);
};

#endif // LIST_H
