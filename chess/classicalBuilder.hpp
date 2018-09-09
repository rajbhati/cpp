#ifndef CLASSICALBUILDER_HPP
#define CLASSICALBUILDER_HPP
#include "builder.hpp"
#include "piece.hpp"

class classicalBuilder : public builder{
public:
    
    classicalBuilder();
    classicalBuilder(const classicalBuilder& orig);
    vector<piece *> makePawns() override;
    vector<piece *> makeKnights() override;
    vector<piece *> makeBishops() override;
    vector<piece *> makeRooks() override;
    vector<piece *> makeQueens() override;
    vector<piece *> makeKings() override;

    virtual ~classicalBuilder();
private:

};

#endif /* CLASSICALBUILDER_HPP */

