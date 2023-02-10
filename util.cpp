#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{

//we need to split the string into words by finding all the spaces within the string
std::set<std::string> wordSet;
set<string>::iterator it = wordSet.begin();
stringstream ss(rawWords);
string word;
string newWord;

while(ss>>word){
    word = convToLower(word);
		newWord = word;
    //check if the word has any punctuation
    for(unsigned int i =0; i<word.size(); i++){
        //if the character is a punctuation, we will split it based on characters before and after it
        if(ispunct(word[i])){
            //checking if the size is less than 2
            if(word.size()<2){
                newWord = "";
            }
            //if the size is greater than 2 or 2
            else if(i>=2){
                newWord = word.substr(0,i);
            }
            //prints out the ending, assuming that the size is greater than 2
            else{
                newWord = word.substr(i+1, word.length());
        }

    }
    if(wordSet.size() == 0){
        wordSet.insert(newWord);
        set<string>::iterator it = wordSet.begin();
    }
    else{
        wordSet.insert(it,newWord);
        ++it;
    }
    
}
}
return wordSet;

}
/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
