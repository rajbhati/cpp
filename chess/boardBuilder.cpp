#include "boardBuilder.hpp"
#include "board.hpp"
#include "bishop.hpp"
#include "knight.hpp"
#include "pawn.hpp"
#include "classical.hpp"
#include "builder.hpp"

boardBuilder::boardBuilder() {
}

board boardBuilder::buildBoard(builder &bldr) {
    board b;
    vector<piece *> pieces;
    vector<piece *> p;
    
    p = bldr.makePawns();
    copy(p.begin(), p.end(), back_inserter(pieces));
    p = bldr.makeKnights();
    copy(p.begin(), p.end(), back_inserter(pieces));
    p = bldr.makeBishops();
    copy(p.begin(), p.end(), back_inserter(pieces));
    p = bldr.makeKings();
    copy(p.begin(), p.end(), back_inserter(pieces));
    p = bldr.makeRooks();
    copy(p.begin(), p.end(), back_inserter(pieces));
    p = bldr.makeQueens();
    copy(p.begin(), p.end(), back_inserter(pieces));
    
    b.setPieces(pieces);
 
    rulebook *rb = new classical(b);
    b.setRulebook(rb);

    return b;
}


