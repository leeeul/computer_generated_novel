#include "markov.hpp"

void Markov::init(string str, int order){
    data = ofBufferFromFile(str);
    this->order = order;
    
    parse();
}

void Markov::parse(){
    ngrams.clear();
    
    for(int i=0; i<data.size()-order; i++){
        
        Ngrams n;
        
        if(i==0){
            string str = data.substr(i, order);
            
            n.identify(str);
            n.add(data.at(i+order));
            
            ngrams.push_back(n);
        }
        else{
            string str = data.substr(i, order);
            
            bool found = false;
            for(int j=0; j<ngrams.size(); j++){
                if(ngrams.at(j).id.compare(str)==0){
                    ngrams.at(j).add(data.at(i+order));
                    found = true;
                    break;
                }
            }
            
            if(!found){
                n.identify(str);
                n.add(data.at(i+order));
                
                ngrams.push_back(n);
            }
        }
    }
}

string Markov::getFirst(){
    int leng = ngrams.size();
    
    bool gotBlank = true;
    string id;
    while(gotBlank){
        int i = (int)ofRandom(leng);
        id = ngrams.at(i).id;
        
        for(int j=0; j<id.size(); j++){
            if(id.at(j)==' '){
                gotBlank = true;
                break;
            }else{
                gotBlank = false;
            }
        }
    }
    return id;
}

char Markov::getNext(string str){
    for(int i=0; i<ngrams.size(); i++){
        Ngrams &ng=ngrams.at(i);
        if(ng.id.compare(str)==0){
            int leng = ng.followers.size();
            return ng.followers.at((int)ofRandom(leng));
        }
    }
    
    return 30;
}



