#include "square.hpp"

square::square(int c)
    : coordinate(c), _piece(nullptr) {
}



string square::display() const {
    if(_piece){
        return _piece->display();
    } else {
        return string(". ");
    }
}

void square::setPiece(piece * const p) {
    _piece = p;
}

void square::deletePiece() {
    delete _piece;
}

bool square::isOccupied() const {
    return _piece != nullptr;
}

piece * square::getPiece() const {
    return _piece;
}
