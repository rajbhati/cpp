#include "piece.hpp"
#include "team.hpp"
#include "coordinate.hpp"
#include "boardUtils.hpp"

piece::piece(int c, team t)
    : pieceCoordinate(c), _team(t) {
}

void piece::setCooridinate(int c) {
    pieceCoordinate = c;
}

int piece::getCoordinate() {
    return pieceCoordinate;
}

team piece::getTeam(){
    return _team;
}

piece::~piece() {	
}

