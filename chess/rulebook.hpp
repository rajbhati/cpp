#ifndef RULEBOOK_HPP
#define RULEBOOK_HPP
#include "chessmove.hpp"
#include "team.hpp"

class rulebook {
public:
//    virtual void capturePiece(coordinate c)=0;
    virtual void executeMove(chessmove c)=0;
    virtual void executeMove(int src, int dest)=0;
    virtual bool isLegalMove(chessmove c)=0;
    virtual ~rulebook();
private:

};

#endif /* RULEBOOK_HPP */

