#include <iostream>
#include "node.h"
#include "integer.h"
#include "list.h"
#include "keyword.h"
#include "symbol.h"

/*
 * Answers to the written questions (Abstract syntax tree interpreter):
 *
 * Q1. Before list_t had its own eval(), it used node_t::eval(), which just
 *     returns this. So the whole tree was returned unchanged, and printing it
 *     gave (<+> (<+> 1 2) 3) => (<+> (<+> 1 2) 3).
 *
 * Q2. Once list_t::eval() applies the head, the head is add_t, which did not
 *     override apply() yet. node_t::apply() is called and reports an error.
 */

int main() {
    frame_t* frame = new frame_t;

    // Nodes and integers: 3 => 3
    {
        node_t* ast = new integer_t { 3 };
        std::cout << ast->to_string() << " => " << ast->eval(frame)->to_string() << std::endl;
    }

    // List: (1 2 3)
    {
        list_t* ast = new list_t;
        ast->append(new integer_t { 1 });
        ast->append(new integer_t { 2 });
        ast->append(new integer_t { 3 });
        std::cout << ast->to_string() << std::endl;
    }

    // Interpreter: (<+> (<+> 1 2) 3) => 6
    {
        node_t* add = new add_t;
        list_t* ast = new list_t;
        ast->append(add);
        ast->append(new list_t);
        ast->at(1)->as_list()->append(add);
        ast->at(1)->as_list()->append(new integer_t { 1 });
        ast->at(1)->as_list()->append(new integer_t { 2 });
        ast->append(new integer_t { 3 });
        std::cout << ast->to_string() << " => " << ast->eval(frame)->to_string() << std::endl;
    }

    // Frames: ((a 42) (b 21)): a=42
    {
        frame_t* f = new frame_t;
        f->set(new symbol_t { "a" }, new integer_t { 666 });
        f->set(new symbol_t { "b" }, new integer_t { 21 });
        f->set(new symbol_t { "a" }, new integer_t { 42 });
        std::cout << f->to_string() << ": a=" << f->get(new symbol_t { "a" })->to_string() << std::endl;
    }

    // Symbols: (<+> (<+> a 2) 3) => 42
    {
        node_t* add = new add_t;
        symbol_t* a = new symbol_t { "a" };
        frame_t* f = new frame_t;
        f->set(a, new integer_t { 37 });

        list_t* ast = new list_t;
        ast->append(add);
        ast->append(new list_t);
        ast->at(1)->as_list()->append(add);
        ast->at(1)->as_list()->append(a);
        ast->at(1)->as_list()->append(new integer_t { 2 });
        ast->append(new integer_t { 3 });
        std::cout << ast->to_string() << " => " << ast->eval(f)->to_string() << std::endl;
    }

    // set!: (<set!> a (<+> 1 2)) => 3, then a => 3
    {
        list_t* sum = new list_t;
        sum->append(new add_t);
        sum->append(new integer_t { 1 });
        sum->append(new integer_t { 2 });

        list_t* ast = new list_t;
        ast->append(new set_t);
        ast->append(new symbol_t { "a" });
        ast->append(sum);

        std::cout << ast->to_string() << " => " << ast->eval(frame)->to_string() << std::endl;
        std::cout << "a => " << frame->get(new symbol_t { "a" })->to_string() << std::endl;
    }

    return 0;
}
