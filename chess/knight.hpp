#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "piece.hpp"

class knight : public piece {
public:
    static int VECTOR[];
    knight(int c, team t);
    string getSquare(const board &b) override;
    string display() override;
    list<chessmove> legalMoves(const board) override;
    bool isLegalMove(string coordinate, board& b) override;

private:

};

#endif /* KNIGHT_HPP */

