#ifndef FISCHERRANDOMBUILDER_HPP
#define FISCHERRANDOMBUILDER_HPP

#include "builder.hpp"
#include "board.hpp"

class fischerRandomBuilder : public builder {
public:
    fischerRandomBuilder();
    vector<piece *> makePawns() override;
    vector<piece *> makeKnights() override;
    vector<piece *> makeBishops() override;
    vector<piece *> makeRooks() override;
    vector<piece *> makeQueens() override;
    vector<piece *> makeKings() override;

    fischerRandomBuilder(const fischerRandomBuilder& orig);
    virtual ~fischerRandomBuilder();
private:

};

#endif /* FISCHERRANDOMBUILDER_HPP */

