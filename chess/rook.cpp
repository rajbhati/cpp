#include "rook.hpp"
#include "board.hpp"

const int rook::MOVE_VECTOR[] = { -8, 8, -1, +1};


rook::rook(const int coordinate, const team t)
    : piece(coordinate, t) {
    type = pieceType::ROOK;
}

bool rook::isLegalMove(string coordinate, board& b) {
return false;
}

bool rook::rowException(int pieceCoordinate, int destination){
    int floor = (pieceCoordinate/boardUtils::ROWSIZE)*boardUtils::ROWSIZE;
    return floor <= destination && destination <= (floor+1);
}

list<chessmove> rook::legalMoves(const board b){
    list<chessmove> legalMoves;
    
    int destination; 
    
    for(int i: MOVE_VECTOR){
        destination = pieceCoordinate;
        while(boardUtils::isLegalCoordinate(destination)){
            destination += i;
            if(rowException(pieceCoordinate, destination))
                break;
            square destSquare = b.getSquare(destination);
            if(destSquare.isOccupied()){
                piece *p = destSquare.getPiece();
                if(p->getTeam() == _team){ // non-attacking move
                    
                } else { // attacking move
                    
                }
                break;
            } else {
//                chessmove m;
//                legalMoves.push_back(m);
            }
        }
    }
}

string rook::display(){
    if(_team == team::WHITE){
        return "R ";
    } else {
        return "r ";
    }
    
}
