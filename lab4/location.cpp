#include "location.h"

#include <cmath>
#include <numbers>

location_t::location_t(std::string name, double latitude, double longitude)
  : name { name },
    latitude { latitude },
    longitude { longitude },
    neighbors { nullptr },
    nb_neighbors { 0 } {
}

location_t::~location_t() {
  delete[] neighbors;
}

void location_t::set_neighbors(location_t* list[]) {
  std::size_t n = 0;
  while (list[n] != nullptr) {
    n++;
  }
  neighbors = list;
  nb_neighbors = n;
}

double location_t::distance_to(location_t* to) {
  const double R = 6378.0; // radius of the Earth in km

  double lat1 = latitude;
  double lon1 = longitude;
  double lat2 = to->latitude;
  double lon2 = to->longitude;

  return R * (std::numbers::pi / 2
              - std::asin(std::sin(lat2) * std::sin(lat1)
                          + std::cos(lon2 - lon1) * std::cos(lat2) * std::cos(lat1)));
}
