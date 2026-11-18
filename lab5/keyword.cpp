#include "keyword.h"
#include "list.h"
#include "integer.h"

keyword_t::keyword_t(std::string id)
    : id { id } {}

std::string keyword_t::to_string() {
    return "<" + id + ">";
}

add_t::add_t()
    : keyword_t { "+" } {}

node_t* add_t::apply(list_t* list, frame_t* frame) {
    uintptr_t total = 0;
    for (size_t i = 1; i < list->size(); i++)
        total += list->at(i)->eval(frame)->int_value();
    return new integer_t { total };
}

set_t::set_t()
    : keyword_t { "set!" } {}

node_t* set_t::apply(list_t* list, frame_t* frame) {
    node_t* var = list->at(1);                  // the symbol is not evaluated
    node_t* value = list->at(2)->eval(frame);   // the expression is
    frame->set(var, value);
    return value;
}
