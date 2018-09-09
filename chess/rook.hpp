#ifndef ROOK_HPP
#define ROOK_HPP

#include "piece.hpp"
#include "chessmove.hpp"

class rook : public piece {
    // inherit
	// int pieceCoordinate;
    // team _team;
private:
    static const int MOVE_VECTOR[]; // move direction on board

public:
    rook(const int coordinate, const team t);    
    string display();
    list<chessmove> legalMoves(const board b) override;
    bool isLegalMove(string coordinate, board& b) override;

private:
    bool rowException(int pieceCoordinate, int destination);
};

#endif /* ROOK_HPP */

