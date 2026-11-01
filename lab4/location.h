#ifndef LOCATION_H
#define LOCATION_H

#include <cstddef>
#include <string>

// a city of the road map
struct location_t {
  std::string  name;
  double       latitude;      // in radians
  double       longitude;     // in radians
  location_t** neighbors;     // array of neighbors, ends with nullptr
  std::size_t  nb_neighbors;

  location_t(std::string name, double latitude, double longitude);
  ~location_t();

  void   set_neighbors(location_t* list[]);
  double distance_to(location_t* to);
};

#endif
