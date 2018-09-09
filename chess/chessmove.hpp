#ifndef CHESSMOVE_HPP
#define CHESSMOVE_HPP
#include <string>

class board;
class piece;
class coordinate;

using namespace std;

class chessmove {
private:
    int source;
    int destination;
    piece *pieceMoved;
    board & _board;

public:
    void execute();
    chessmove(string m, board &b); // e4 pawn move, capture, promotion, castle 
    chessmove(const int s, const int d, board &b);
    chessmove(const coordinate src, const coordinate dest, board &b);
    virtual ~chessmove();
};

#endif /* CHESSMOVE_HPP */

