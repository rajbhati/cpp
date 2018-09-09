#ifndef BOARDUTILS_HPP
#define BOARDUTILS_HPP
#include<iostream>
#include<map>
#include "board.hpp"
#include "chessmove.hpp"

using namespace std;

class boardUtils{
public:
    static int BOARDSIZE;
    static int ROWSIZE;

    static bool isLegalCoordinate(int c);
    static void pgnPlay(const string pgn);
    static void FischerRandom();

    static chessmove makeMove(string move, board &b, team t);
//    static board makeClassicalBoard();
private:
	static void fischerPlay(string pgn, board &b);
};
#endif /* BOARDUTILS_HPP */

