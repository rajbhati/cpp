#include <string>
#include <map>
#include <algorithm>

#include "board.hpp"
#include "boardUtils.hpp"
#include "rook.hpp"
#include "pawn.hpp"
#include "queen.hpp"
#include "bishop.hpp"
#include "king.hpp"
#include "knight.hpp"
#include "coordinate.hpp"
#include "rulebook.hpp"

board::board() {
    string cols[] = {"h", "g", "f", "e", "d", "c", "b", "a"};
    int rows[] = {1, 2, 3, 4, 5, 6, 7, 8};

    // e4: 35 coordinate
    for (auto r : rows) {
        int i = 0;
        for (auto c : cols) {
            string sq = c.append(to_string(r));
            coordinate *pc = new coordinate( (r-1) * boardUtils::ROWSIZE + i );
            coordinates.insert( std::pair<string, coordinate*>(sq, pc) );
            i++;
        }
    }
    
    for(int i=0; i<boardUtils::BOARDSIZE; i++){
        squares.push_back(square(i));
    }
}

chessmove board::buildMove(string m, team t) {
    string src, dest;
    
    // check move
    // promotion move
    
    // is pawn move
    if(m[0] >= 'a' && m[0] <= 'h'){
        string src;
        if (auto x = std::find(m.begin(), m.end(), 'x') != m.end()) { // capture move
            dest = m.substr(x + 1, m.size());
            src = getCapturingPawnPos(m[0], m, t);
        } else{
            dest = m;
            src = getPawnPosition(m, t);
        }
        chessmove c(coordinate(src, *this), coordinate(dest, *this), *this);
        return c;
    }
    // Piece move 
    else if(isupper(m[0])){

        if (auto x = find(m.begin(), m.end(), 'x') != m.end()) {
            dest = m.substr(x + 1, m.size());
        } else{
            dest = m.substr(1, m.size());
        }
        
        pieceType type;
        switch (m[0]){
            case 'N' :
                type = pieceType::KNIGHT;
                break;
            case 'B':
                type = pieceType::BISHOP;
                break;
            case 'R':
                type = pieceType::ROOK;
                break;
            case 'Q':
                type = pieceType::QUEEN;
                break;
            case 'K':
                type = pieceType::KING;
                break;
        }
        src = getPiecePos(type, dest, t);
        return chessmove (coordinate(src, *this), coordinate(dest, *this), *this);
    }

    else  if(m == "O-O"){
        
    } else if (m == "O-O-O"){
        
    }
}

string board::getPiecePos(pieceType type, string dest, team t) {
    vector<piece *> pieces;
    
    switch(type){
        case(pieceType::KNIGHT):
            pieces = _knights;
            break;
        case(pieceType::BISHOP):
            pieces = _bishops;
            break;
        case(pieceType::ROOK):
            pieces = _rooks;
            break;
        case(pieceType::QUEEN):
            pieces = _queens;
            break;
        case(pieceType::KING):
            pieces = _kings;
            break;
    }
    for(auto p: pieces){
        if(t == p->getTeam()){
            if( p->isLegalMove(dest, *this)) {
                return getName(p->getCoordinate());
            }
        }
    }
    return "";
}

string board::getCapturingPawnPos(char f, string dest, team t) {
    for (auto pawn : _pawns){
        if(pawn->getTeam() == t && pawn->getSquare(*this)[0] == f &&
            pawn->isLegalMove(dest.substr(1), *this)){
            return getName(pawn->getCoordinate());
        }
    }
    return "";
}

string board::getPawnPosition(string dest, team t) {
    for (auto pawn : _pawns){
        if(pawn->getTeam() == t){
            if(pawn->isLegalMove(dest, *this)){
                return getName(pawn->getCoordinate());
            }
        }
    }
    return "";
}

void board::capturePiece(coordinate c) {
    piece *p = squares[c.getint()].getPiece();

    if(p != nullptr){
        _captured.push_back(p);
    }
    squares[c.getint()].setPiece(nullptr);
}


void board::setRulebook(rulebook *rb) {
    _rulebook = rb;
}

int board::getCoordinate(string str) {
    return coordinates[str]->getint();
}

square board::getSquare(const int i) const{
    return squares[i];
}

string board::getName(int i) const {
    for (auto &c: coordinates){
        if(c.second->getint() == i){
            return c.first;
        }
    }
    return string();
}

void board::setPiece(int dest, piece* p) {
    squares[dest].setPiece(p);
    p->setCooridinate(dest);
}

void board::setPiece(piece* p) {
    squares[p->getCoordinate()].setPiece(p);
}

void board::setPieces(vector<piece*> pieces) {

    for(auto p: pieces){

        switch(p->piecetype()){
            case pieceType::PAWN:
                _pawns.push_back(p);
                break;
            case pieceType::BISHOP:
                _bishops.push_back(p);
                break;
            case pieceType::KNIGHT:
                _knights.push_back(p);
                break;
            case pieceType::ROOK:
                _rooks.push_back(p);
                break;
            case pieceType::QUEEN:
                _queens.push_back(p);
                break;
            case pieceType::KING:
                _kings.push_back(p);
                break;
        }
        _pieces.push_back(p);
        squares[p->getCoordinate()].setPiece(p);
    }
}

void board::movePiece(const int dest, piece * const p){
    _pieces.push_back(p);
    
    piece *destPiece = squares[dest].getPiece();
    if(destPiece != nullptr){
        _captured.push_back(destPiece);
    }
    
    squares[dest].setPiece(p);
    squares[p->getCoordinate()].setPiece(nullptr);
    if(p) {
        p->setCooridinate(dest);
    } else {

    }
}

void board::display() {
    int i=0;
    for (i=0; i< 2*(boardUtils::ROWSIZE) + 10; i++) cout << "=";
    cout <<  endl << " || " ;
	i=0;
    for(auto s: squares){
        cout << s.display();
        if( ! ((++i) % boardUtils::ROWSIZE)) cout << " || " << (i/8 -1) <<  endl 
                << " || " ;
        
    }
    for (i=0; i< 2*(boardUtils::ROWSIZE) + 6; i++) cout << "=";
    cout << endl;
    cout << endl;
}
