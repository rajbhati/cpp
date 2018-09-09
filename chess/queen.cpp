#include "queen.hpp"
#include "board.hpp"

queen::queen(const int c, const team t)
    : piece(c, t) {
    type = pieceType::QUEEN;
}

bool queen::isLegalMove(string coordinate, board& b) {
return true;
}

list<chessmove> queen::legalMoves(const board) {
    list<chessmove> legalMoves;
    return legalMoves;
}


string queen::display() {
    return (_team == team::WHITE) ? "Q " : "q ";
}
