#include "fischerRandomBuilder.hpp"

fischerRandomBuilder::fischerRandomBuilder() {
}

vector<piece *> fischerRandomBuilder::makeBishops(){
    vector<piece *> bishops;
    for (auto i: { 1, 6} ) {
        piece *p = new bishop(i, team::WHITE);
        bishops.push_back(p);
        p = new bishop(63 - i, team::BLACK);
        bishops.push_back(p);
    }
    return bishops;
}

vector<piece *> fischerRandomBuilder::makeKnights(){
    vector<piece *> knights;
    for (auto i: { 2, 5} ) {
        piece *p = new knight(i, team::WHITE);
        knights.push_back(p);
        p = new knight(63 - i, team::BLACK);
        knights.push_back(p);
    }
    return knights;
}

vector<piece *> fischerRandomBuilder::makePawns(){
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

vector<piece *> fischerRandomBuilder::makeRooks(){
   
    vector<piece *> rooks;
    
    for (auto i: { 3, 4 } ) {
        piece *p = new rook(i, team::WHITE);
        rooks.push_back(p);
        p = new rook(63 - i, team::BLACK);
        rooks.push_back(p);
    }
    return rooks;
}

vector<piece *> fischerRandomBuilder::makeKings(){
    vector<piece *> kings;
        
    piece *p = new king(0, team::WHITE);
    kings.push_back(p);
    p = new king(56, team::BLACK);
    kings.push_back(p);

    return kings;
}

vector<piece *> fischerRandomBuilder::makeQueens(){
    vector<piece *> queens;

    piece *p = new queen(7, team::WHITE);
    queens.push_back(p);
    p = new queen(63, team::BLACK);
    queens.push_back(p);
    return queens;
}

fischerRandomBuilder::fischerRandomBuilder(const fischerRandomBuilder& orig) {
}

fischerRandomBuilder::~fischerRandomBuilder() {
}

