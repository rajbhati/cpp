#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

#include "board.hpp"
#include "classical.hpp"
#include "piece.hpp"
#include "coordinate.hpp"
#include "square.hpp"

using namespace std;

classical::classical(board b) : _board(b){
}

classical::~classical() {
}

void classical::executeMove(chessmove c) {

}

void classical::executeMove(int src, int dest) {

}

bool classical::isLegalMove(chessmove c) {

}

