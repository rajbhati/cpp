#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "piece.hpp"

class queen : public piece {
public:
    queen(const int c, const team t);
    string display() override;
    list<chessmove> legalMoves(const board) override;
    bool isLegalMove(string coordinate, board& b) override;

private:

};

#endif /* QUEEN_HPP */

