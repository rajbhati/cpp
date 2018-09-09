#include <list>
#include "pawn.hpp"
#include "board.hpp"


pawn::pawn(const int coordinate, const team t) 
    : piece(coordinate, t) {
    type = pieceType::PAWN;
}

string pawn::getSquare(const board &b){
    return b.getName(pieceCoordinate);
}

/* capture moves start with 'x'*/
bool pawn::isLegalMove(string c, board& b) {
    int dest;

    if (c[0] == 'x') { //capture move
        dest = coordinate(c.substr(1, c.size()), b).getint();
        if (dest == pieceCoordinate + 7 || dest == pieceCoordinate + 9 ||
            dest == pieceCoordinate - 7 || dest == pieceCoordinate - 9) {
            return true;
        }
    } else {
        dest = coordinate(c, b).getint();
        if (dest == pieceCoordinate + 8 || dest == pieceCoordinate + 16 ||
            dest == pieceCoordinate - 8 || dest == pieceCoordinate - 16 ) {
            return true;
        }
    }
    return false;
}

string pawn::display() {
    return (_team == team::WHITE) ? "P " : "p ";
}

list<chessmove> pawn::legalMoves(const board) {
    list<chessmove> legalMoves;
    return legalMoves;
}
