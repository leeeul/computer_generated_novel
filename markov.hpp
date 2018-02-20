#ifndef markov_hpp
#define markov_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ngrams.hpp"

class Markov{
    public:
    
    int order;
    string data;
    vector<Ngrams> ngrams;
    
    void init(string str, int order);
    void parse();
    string getFirst();
    char getNext(string str);    
};


#endif
