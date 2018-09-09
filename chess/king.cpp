#include "king.hpp"
#include "board.hpp"

king::king(int c, team t) : piece (c, t){
    type = pieceType::KING;
}

bool king::isLegalMove(string coordinate, board& b) {
return false;
}

list<chessmove> king::legalMoves(const board) {
    list<chessmove> legalMoves;
    return legalMoves;
}

string king::display() {
    return (_team == team::WHITE) ? "K " : "k ";
}
