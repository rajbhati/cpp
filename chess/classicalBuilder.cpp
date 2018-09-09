#include <vector>

#include "board.hpp"
#include "classicalBuilder.hpp"

vector<piece *> classicalBuilder::makeBishops(){
    vector<piece *> bishops;
    for (auto i: { 2, 5} ) {
        piece *p = new bishop(i, team::WHITE);
        bishops.push_back(p);
        p = new bishop(63 - i, team::BLACK);
        bishops.push_back(p);
    }
    return bishops;
}

vector<piece *> classicalBuilder::makeKnights(){
    vector<piece *> knights;
    for (auto i: { 1, 6} ) {
        piece *p = new knight(i, team::WHITE);
        knights.push_back(p);
        p = new knight(63 - i, team::BLACK);
        knights.push_back(p);
    }
    return knights;
}

vector<piece *> classicalBuilder::makePawns(){
    vector<piece *> pawns;
    
    for(int i=0; i < boardUtils::ROWSIZE; i++){
        int idx = i + 8; 
        int bidx = 63-i - 8;
        piece *p = new pawn(idx, team::WHITE); 
        pawns.push_back(p);
        p = new pawn(bidx, team::BLACK);
        pawns.push_back(p);
    }
    return pawns;
}

vector<piece *> classicalBuilder::makeRooks(){
   
    vector<piece *> rooks;
    
    for (auto i: { 0, 7 } ) {
        piece *p = new rook(i, team::WHITE);
        rooks.push_back(p);
        p = new rook(63 - i, team::BLACK);
        rooks.push_back(p);
    }
    return rooks;
}

vector<piece *> classicalBuilder::makeKings(){
    vector<piece *> kings;
        
    piece *p = new king(3, team::WHITE);
    kings.push_back(p);
    p = new king(59, team::BLACK);
    kings.push_back(p);

    return kings;
}

vector<piece *> classicalBuilder::makeQueens(){
    vector<piece *> queens;

    piece *p = new queen(4, team::WHITE);
    queens.push_back(p);
    p = new queen(60, team::BLACK);
    queens.push_back(p);
    return queens;
}


classicalBuilder::classicalBuilder() {
}

classicalBuilder::classicalBuilder(const classicalBuilder& orig) {
}

classicalBuilder::~classicalBuilder() {
}