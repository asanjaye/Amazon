#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>

using namespace std;
/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
    std::set<T> result;
    typename set<T>::iterator it;
    typename set<T>::iterator it2;
    //loops through the content of s1
    for(it = s1.begin(); it!= s1.end(); ++it){
        T current = *it;
        //find the current element in s2
        typename set<T>::iterator match = s2.find(current);
        if(match != s2.end()){
            //adding the element to the result set
                result.insert(*it);
        }
    }
    return result;



}
template <typename T>
set<T> setUnion(set<T>& s1, set<T>& s2)
{
    std::set<T> result;
    typename set<T>::iterator it;
    //adding all the elements from s2 to the result set if the element isn't already in the result set
    for(it = s2.begin(); it!= s2.end(); ++it){
          s1.insert(*it);

    }
return s1;



}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
