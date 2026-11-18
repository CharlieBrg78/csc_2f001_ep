#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <cstddef>
#include <cstdint>

struct list_t;
struct frame_t;

void error(std::string msg) __attribute__((noreturn));

struct node_t {
    virtual node_t* eval(frame_t* frame);
    virtual node_t* apply(list_t* list, frame_t* frame);
    virtual std::string to_string();
    virtual list_t* as_list();
    virtual uintptr_t int_value();
    virtual bool is(std::string id);
};

#endif // NODE_H
