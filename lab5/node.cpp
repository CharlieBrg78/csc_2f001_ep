#include "node.h"

void error(std::string msg) {
    std::cout << "Error: " << msg << std::endl;
    exit(1);
}

// by default, evaluating a node gives the node itself (ok for integers and keywords)
node_t* node_t::eval(frame_t* /*frame*/) {
    return this;
}

// only keywords know how to apply themselves to a list
node_t* node_t::apply(list_t* /*list*/, frame_t* /*frame*/) {
    error("this node cannot be applied (not a keyword)");
}

std::string node_t::to_string() {
    return "???";
}

list_t* node_t::as_list() {
    error("this node is not a list");
}

uintptr_t node_t::int_value() {
    error("this node is not an integer");
}

bool node_t::is(std::string /*id*/) {
    return false;
}
