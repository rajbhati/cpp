#include <cstdlib>
#include <utility>
#include <list>
#include <unistd.h>
#include "board.hpp"
#include "pawn.hpp"
#include "boardBuilder.hpp"

using namespace std;

int main() {
    string pgn;
    
    string line;
    while(getline(cin, line)){
        pgn.append(line);
        pgn.append(" ");
    }

    boardUtils::FischerRandom();
    //boardUtils::pgnPlay(pgn);
    // boardUtils::twoPlayer();
    // boardUtils::playMachine();
    return 0;
}

