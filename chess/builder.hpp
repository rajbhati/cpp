#ifndef BUILDER_HPP
#define BUILDER_HPP
#include <vector>
#include "piece.hpp"

class builder {
public:
    builder();
    builder(const builder& orig);
    virtual ~builder();
    virtual vector<piece *> makePawns()=0;
    virtual vector<piece *> makeKnights()=0;
    virtual vector<piece *> makeBishops()=0;
    virtual vector<piece *> makeRooks()=0;
    virtual vector<piece *> makeQueens()=0;
    virtual vector<piece *> makeKings()=0;

private:

};

#endif /* BUILDER_HPP */

