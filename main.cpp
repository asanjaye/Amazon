#include <string>
#include <set>
#include <iostream>
#include "util.h"

using namespace std;


int main(){

    //Testing parseStringToWords function

    string s = "horror drama";
    set<string> wordSet = parseStringToWords(s);
    for(set<string>::iterator it = wordSet.begin(); it!= wordSet.end(); ++it){
        cout << *it << endl;
    }

    // set<string> newWordSet  = parseStringToWords(y);
    // set<string> result = setIntersection(wordSet, newWordSet);
    // for(set<string>::iterator it = result.begin(); it!= result.end(); ++it){
    //     cout << *it << endl;
    // }
    
 

    
    
    
    
    return 0;

}