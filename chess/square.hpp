#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "piece.hpp"

class square {
private:
    int coordinate;
    piece* _piece;
    string name;

public:
    
    square(const int coordinate);
    square(const string &e4);
    string display()const;
    piece *getPiece()const;
    void setPiece(piece * const p);
    bool isOccupied()const;
    void deletePiece ();
};

#endif /* SQUARE_HPP */

