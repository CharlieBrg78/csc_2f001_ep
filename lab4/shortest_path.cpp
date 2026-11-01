#include "shortest_path.h"

#include <iostream>

/*
 * node_t
 */
node_t::node_t(node_t* next, location_t* location, node_t* from, double from_origin, double total)
  : next { next },
    location { location },
    from { from },
    from_origin { from_origin },
    total { total },
    visited { false } {
}

// prints the path that leads to this node, starting from the origin
void node_t::print(location_t* origin) {
  if (from != nullptr) {
    from->print(origin);
  }
  std::cout << "  * " << location->name << " at " << from_origin
            << " km from " << origin->name << std::endl;
}

/*
 * helpers on the set of nodes
 */

// returns the node that represents loc, or nullptr if loc is not in the set
node_t* lookup(node_t* head, location_t* loc) {
  for (node_t* cur = head; cur != nullptr; cur = cur->next) {
    if (cur->location == loc) {
      return cur;
    }
  }
  return nullptr;
}

// returns the non visited node with the smallest total, or nullptr if every node is visited
node_t* next_base(node_t* head) {
  node_t* res = nullptr;
  for (node_t* cur = head; cur != nullptr; cur = cur->next) {
    if (!cur->visited && (res == nullptr || cur->total < res->total)) {
      res = cur;
    }
  }
  return res;
}

/*
 * shortest_path_t
 */
shortest_path_t::shortest_path_t(location_t* from, location_t* to)
  : head { new node_t { nullptr, from, nullptr, 0.0, from->distance_to(to) } },
    base { nullptr },
    from { from },
    to { to } {
}

shortest_path_t::~shortest_path_t() {
  while (head != nullptr) {
    node_t* next = head->next;
    delete head;
    head = next;
  }
}

void shortest_path_t::compute() {
  base = next_base(head);

  // stops when the destination is reached or when there is no more base
  while (base != nullptr && base->location != to) {
    base->visited = true;

    location_t* city = base->location;
    for (std::size_t i = 0; i < city->nb_neighbors; i++) {
      location_t* cur = city->neighbors[i];
      double from_origin = base->from_origin + city->distance_to(cur);
      double total = from_origin + cur->distance_to(to);

      node_t* n = lookup(head, cur);

      if (n == nullptr) {
        // first time we reach cur
        head = new node_t { head, cur, base, from_origin, total };
      } else if (from_origin < n->from_origin) {
        // better path to cur: update it and explore it again
        n->from = base;
        n->from_origin = from_origin;
        n->total = total;
        n->visited = false;
      }
    }

    base = next_base(head);
  }
}

void shortest_path_t::display() {
  // after compute, base is the node of the destination if a path exists
  if (base == nullptr) {
    std::cout << "unable to find a path from " << from->name << " to " << to->name << std::endl;
  } else {
    std::cout << "path from " << from->name << " to " << to->name << std::endl;
    base->print(from);
  }
}
