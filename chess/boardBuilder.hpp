#ifndef BOARDBUILDER_HPP
#define BOARDBUILDER_HPP

#include "board.hpp"
#include "builder.hpp"

class boardBuilder {
public:
    static board buildBoard(builder &b);

private:
    boardBuilder();

};

#endif /* BOARDBUILDER_HPP */

