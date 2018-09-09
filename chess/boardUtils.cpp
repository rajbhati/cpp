#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unistd.h>
#include "fischerRandomBuilder.hpp"
#include "boardUtils.hpp"
#include "chessmove.hpp"
#include "coordinate.hpp"
#include "board.hpp"
#include "boardBuilder.hpp"
#include "boardBuilder.hpp"
#include "classicalBuilder.hpp"

using namespace std;

int boardUtils::BOARDSIZE = 64;
int boardUtils::ROWSIZE = 8;
  
vector<string> wsplit (const string str){
    vector<string> words;
    string item;
    stringstream ss(str);
    
    while(getline(ss, item, ' ')){
        words.push_back(item);
    }
    
    return words;
}

void boardUtils::FischerRandom() {
    fischerRandomBuilder frb;
    
    board b = boardBuilder::buildBoard(frb);
    b.display();
	fischerPlay(string("1. e4 e5"), b);
}

/* FIXME IS A COPY OF pgnPlay */
void boardUtils::fischerPlay(string pgn, board &b) {
    
    vector<string> moves = wsplit(pgn);
    int moveNumber;
    int i=0;
    for(auto &mv: moves) {
        ++i;
        if( i%3 == 1){
            moveNumber = stoi(mv.c_str());
        } else if( i%3 == 2){
            cout << moveNumber << ". " << mv << endl;
            b.buildMove(mv, team::WHITE).execute(); b.display(); sleep(1);
        } else if ( i%3 == 0) {
            cout << moveNumber << "..." << mv << endl;
            b.buildMove(mv, team::BLACK).execute(); b.display(); sleep(1);
        }
    }
}
void boardUtils::pgnPlay(string pgn) {

    classicalBuilder cb;
    
    board b = boardBuilder::buildBoard(cb);
    
    vector<string> moves = wsplit(pgn);
    int moveNumber;
    int i=0;
    for(auto &mv: moves) {
        ++i;
        if( i%3 == 1){
            moveNumber = stoi(mv.c_str());
        } else if( i%3 == 2){
            cout << moveNumber << ". " << mv << endl;
            b.buildMove(mv, team::WHITE).execute(); b.display(); sleep(1);
        } else if ( i%3 == 0) {
            cout << moveNumber << "..." << mv << endl;
            b.buildMove(mv, team::BLACK).execute(); b.display(); sleep(1);
        }
    }
}

bool boardUtils::isLegalCoordinate(int c){
    return c>=0 && c<BOARDSIZE;
}
