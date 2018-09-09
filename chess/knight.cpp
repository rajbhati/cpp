#include "knight.hpp"
#include "board.hpp"

int knight::VECTOR[] = {6, -6, 10, -10, 15, -15, 17, -17};

knight::knight(int c, team t) : piece(c, t) {
    type = pieceType::KNIGHT;
}

string knight::getSquare(const board &b) {
    return b.getName(pieceCoordinate);
}

bool knight::isLegalMove(string dest, board& b) {
    int i = b.getCoordinate(dest);
    for(auto v: VECTOR){
        if( (pieceCoordinate + v) == i){
            return true;
        }
    }
    return false;
}

list<chessmove> knight::legalMoves(const board) {
    list<chessmove> legalMoves;
    return legalMoves;
}

string knight::display() {
    return (_team == team::WHITE) ? "N " : "n ";
}

