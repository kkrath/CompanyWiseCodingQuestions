#include<iostream>
#include<set>
#include<map>
using namespace std;

/* fiven a dictionary of words and a string, findout whether the string can be devided into
   words that make up the dictionary. This is a DP approch with memoization */

bool is_word_break_possible(std::string str, set<std::string> const dictionary, map<std::string,bool> &memo){
    /* base case */
    if(str == "")
        return true;

    if(memo.find(str) != memo.end())
        return memo[str];

    int n = str.size();

    for(int i = 0; i <= n; i++){
        std::string prefix = str.substr(0,i);
        if(dictionary.find(prefix) != dictionary.end()){
            cout << prefix << endl;
            std::string suffix = str.substr(i,n);
            cout << suffix << endl;
            if(dictionary.find(suffix) != dictionary.end() || is_word_break_possible(suffix, dictionary, memo)){
                memo[str] = true;
                return true;
            }
        }
    }
    return false;
}

int main(){
    std::string str = "abcdefgh";
    set<std::string> dictionary{"ab", "cd", "abcd", "h"};
    map<std::string,bool> memo;
    cout << is_word_break_possible(str, dictionary, memo);
}