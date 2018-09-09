#ifndef CLASSICAL_HPP
#define CLASSICAL_HPP
#include <string>
#include "rulebook.hpp"
#include "team.hpp"
#include "chessmove.hpp"

using namespace std;
class board;

class classical : public rulebook {
private:
    board _board;

public:
    classical(board b);
    bool isLegalMove(chessmove c) override;
    void capturePiece(coordinate c);
    void executeMove(chessmove c);
    void executeMove(int src, int dest);
    virtual ~classical();
};

#endif /* CLASSICAL_HPP */

