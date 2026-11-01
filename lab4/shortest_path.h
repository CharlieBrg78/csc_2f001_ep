#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include "location.h"

// an element of the unordered set of reached cities
struct node_t {
  node_t*     next;         // next node of the set
  location_t* location;     // city represented by the node
  node_t*     from;         // previous city on the best known path
  double      from_origin;  // distance from the origin
  double      total;        // from_origin + distance as the crow flies to the destination
  bool        visited;

  node_t(node_t* next, location_t* location, node_t* from, double from_origin, double total);

  void print(location_t* origin);
};

struct shortest_path_t {
  node_t*     head;  // first node of the set
  node_t*     base;  // current base
  location_t* from;  // origin
  location_t* to;    // destination

  shortest_path_t(location_t* from, location_t* to);
  ~shortest_path_t();

  void compute();
  void display();
};

#endif
