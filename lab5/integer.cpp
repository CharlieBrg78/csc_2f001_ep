#include "integer.h"

integer_t::integer_t(uintptr_t value)
    : value { value } {}

std::string integer_t::to_string() {
    return std::to_string(value);
}

uintptr_t integer_t::int_value() {
    return value;
}
