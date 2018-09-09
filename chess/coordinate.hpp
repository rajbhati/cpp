#ifndef COORDINATE_HPP
#define COORDINATE_HPP
#include<string>


class board;

class coordinate {
public:
    coordinate(int);
    coordinate(std::string, board &b);
    int getint ();
    std::string getname();
private:
    int _c;
    std::string c;
};

#endif /* COORDINATE_HPP */

