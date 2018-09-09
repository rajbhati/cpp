#include <string>
#include "coordinate.hpp"
#include "boardUtils.hpp"

using namespace std;

coordinate::coordinate(int c) : _c(c) {
}

std::string coordinate::getname() {
    return c;
}

coordinate::coordinate(string c, board &b) : c(c) {
    _c = b.getCoordinate(c);
}

int coordinate::getint() {
    return _c;
}



