#include "list.h"
#include "integer.h"

list_t::list_t()
    : elements { nullptr },
      nb_elements { 0 },
      capacity { 0 } {}

list_t* list_t::as_list() {
    return this;
}

size_t list_t::size() {
    return nb_elements;
}

node_t* list_t::at(size_t i) {
    if (i >= nb_elements)
        error("list_t::at: index " + std::to_string(i) + " out of bounds");
    return elements[i];
}

void list_t::set_at(size_t i, node_t* value) {
    if (i >= nb_elements)
        error("list_t::set_at: index " + std::to_string(i) + " out of bounds");
    elements[i] = value;
}

void list_t::append(node_t* value) {
    if (nb_elements == capacity) {
        size_t bigger = (capacity == 0) ? 1 : 2 * capacity;
        node_t** grown = new node_t*[bigger];

        for (size_t i = 0; i < nb_elements; i++)
            grown[i] = elements[i];

        elements = grown;   // no delete[] : memory is not freed in this lab
        capacity = bigger;
    }
    elements[nb_elements++] = value;
}

std::string list_t::to_string() {
    std::string res = "(";
    for (size_t i = 0; i < nb_elements; i++) {
        if (i > 0)
            res += " ";
        res += (elements[i] == nullptr) ? "???" : elements[i]->to_string();
    }
    return res + ")";
}

// evaluate the head of the list, then apply it to the whole list
node_t* list_t::eval(frame_t* frame) {
    node_t* op = at(0)->eval(frame);
    return op->apply(this, frame);
}

void frame_t::set(node_t* sym, node_t* value) {
    for (size_t i = 0; i < size(); i++) {
        list_t* pair = at(i)->as_list();
        if (sym->is(pair->at(0)->to_string())) {
            pair->set_at(1, value);
            return;
        }
    }
    list_t* pair = new list_t;
    pair->append(sym);
    pair->append(value);
    append(pair);
}

node_t* frame_t::get(node_t* sym) {
    for (size_t i = 0; i < size(); i++) {
        list_t* pair = at(i)->as_list();
        if (sym->is(pair->at(0)->to_string()))
            return pair->at(1);
    }
    error("undefined symbol " + sym->to_string());
}
