#include "ngrams.hpp"

void Ngrams::identify(string str){
    id = str;
}

void Ngrams::add(char c){
    followers.push_back(c);
}
