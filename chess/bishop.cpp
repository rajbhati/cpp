#include "bishop.hpp"
#include "board.hpp"

int bishop::VECTOR[] = {7, -7, 9, -9};

bishop::bishop(int c, team t) : piece(c, t) {
    type = pieceType::BISHOP;
}

string bishop::getSquare(const board &b){
    return b.getName(pieceCoordinate);
}
 
bool bishop::isLegalMove(string dest, board& b) {
    int didx = b.getCoordinate(dest);

    for(auto v : VECTOR) {
        int i = pieceCoordinate;
        while (boardUtils::isLegalCoordinate(i)) {
            if (i == didx) {
                return true;
                // FIXME if(rowException(pieceCoordinate, dest))
            }
            i += v;
        }
    }
    return false;
}

list<chessmove> bishop::legalMoves(const board) {
    list<chessmove> legalMoves;
    return legalMoves;
}

string bishop::display() {
    return (_team == team::WHITE) ? "B " : "b ";
}
