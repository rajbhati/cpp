#include <algorithm>
#include "chessmove.hpp"
#include "board.hpp"
#include "coordinate.hpp"

chessmove::chessmove(int s, int d, board &b) 
: source(s), destination(d), _board(b) {
}

chessmove::chessmove(coordinate src, coordinate dest, board &b) 
    : _board(b) {
    source = src.getint();
    destination = dest.getint();
}

void chessmove::execute() {
    piece *p = _board.getSquare(source).getPiece();
    _board.movePiece(destination, p);
}

chessmove::~chessmove() {
}