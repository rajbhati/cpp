#ifndef BOARD_HPP
#define BOARD_HPP
#include <vector>
#include <map>
#include "square.hpp"
#include "chessmove.hpp"
#include "boardUtils.hpp"
#include "coordinate.hpp"
#include "piece.hpp"
#include "king.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "queen.hpp"
#include "bishop.hpp"
#include "pawn.hpp"
#include "rulebook.hpp"

using namespace std;

class board {
private:
    vector<square> squares;
    map<string, coordinate*> coordinates;
    vector<piece*> _pieces; // all active pieces
    vector<piece*> _pawns;
    vector<piece*> _knights;
    vector<piece*> _bishops;
    vector<piece*> _rooks;
    vector<piece*> _kings;
    vector<piece*> _queens;
    vector<piece*> _captured;
    rulebook *_rulebook;
    bool canCastle[2];
    bool underCheck[2];
    
public:
    board();
    
    void setRulebook(rulebook*);
    rulebook *ruleBook(){return _rulebook;};

    int getCoordinate(string s); // square name (e4) to coordinate (27)
    string getName(int i) const; // coordinate to square name
    square getSquare(const int i) const; // FIXME input cooridnate object

    string getPawnPosition(string dest, team t);
    string getCapturingPawnPos(char f, string dest, team t);
    string getPiecePos(pieceType type, string dest, team t);

    chessmove buildMove(string m, team t);
    
    void capturePiece(coordinate c);
    void movePiece(int dest, piece * const p);
    void movePiece(piece * p);
    void setPiece(int dest, piece* p);
    void setPiece(piece* p);
    void setPieces(vector<piece *>  p);

    void display();
};

#endif /* BOARD_HPP */
