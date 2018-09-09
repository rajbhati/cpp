#ifndef PAWN_HPP
#define PAWN_HPP

#include "piece.hpp"

class pawn : public piece {
public:
    pawn(const int coordinate, const team t);
    string display() override;
    list<chessmove> legalMoves(const board) override;
    string getSquare(const board& b) override;
    bool isLegalMove(string coordinate, board &b) override;
    private:

};

#endif /* PAWN_HPP */

