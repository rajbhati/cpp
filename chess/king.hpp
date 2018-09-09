#ifndef KING_HPP
#define KING_HPP

#include "piece.hpp"

class king : public piece {
public:
    king(int c, team t);
    string display() override;
    list<chessmove> legalMoves(const board) override;
    bool isLegalMove(string coordinate, board& b) override;


private:

};

#endif /* KING_HPP */

