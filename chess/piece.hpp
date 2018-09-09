#ifndef PIECE_HPP
#define PIECE_HPP
#include <list>
#include <string>
#include "chessmove.hpp"
#include "team.hpp"

using namespace std;

class board;

enum class pieceType{
    PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
};

class piece {
public:
    piece(const int coordinate, const team t);
    void setCooridinate(int c);
    int getCoordinate();
    virtual list<chessmove> legalMoves(const board)=0;
    virtual string display()=0;
    team getTeam();
    pieceType piecetype() { return type; }
    virtual bool isLegalMove(string dest, board &b)=0;
    virtual string getSquare(const board &b){return "";};
    virtual ~piece();
protected:
    int pieceCoordinate;
    team _team;
    pieceType type;
};

#endif /* PIECE_HPP */