#ifndef INTEGER_H
#define INTEGER_H

#include "node.h"

struct integer_t : node_t {
    uintptr_t value;

    integer_t(uintptr_t value);

    std::string to_string();
    uintptr_t int_value();
};

#endif // INTEGER_H
