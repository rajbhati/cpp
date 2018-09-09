#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "piece.hpp"

class bishop : public piece {
public:
    static int VECTOR[];
    bishop(int c, team t);

    string getSquare(const board& b) override;
    string display() override;
    bool isLegalMove(string dest, board& b) override;
    list<chessmove> legalMoves(const board) override;

private:
};

#endif /* BISHOP_HPP */

