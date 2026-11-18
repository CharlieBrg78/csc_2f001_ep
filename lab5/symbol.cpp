#include "symbol.h"
#include "list.h"

symbol_t::symbol_t(std::string id)
    : id { id } {}

bool symbol_t::is(std::string id) {
    return this->id == id;
}

std::string symbol_t::to_string() {
    return id;
}

// a symbol evaluates to the value stored in the frame
node_t* symbol_t::eval(frame_t* frame) {
    return frame->get(this);
}
