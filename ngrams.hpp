#ifndef ngrams_hpp
#define ngrams_hpp

#include <stdio.h>
#include "ofMain.h"

class Ngrams{
    public:
    
    string id;
    vector<char> followers;
    
    void identify(string str);
    void add(char c);
};

#endif /* ngrams_hpp */
