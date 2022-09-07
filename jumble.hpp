#ifndef JUMBLE_HPP
#define JUMBLE_HPP 

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

class jumble
{
private:
    std::string _word;
    bool _end;

public:
    jumble(/* args */);
    std::string shuffle(std::string word);
    void play(std::string word);
    void setWord(std::string mot);
    std::string getWord();
    void setEnd(bool end);
    bool getEnd();
    int replay();

};


#endif