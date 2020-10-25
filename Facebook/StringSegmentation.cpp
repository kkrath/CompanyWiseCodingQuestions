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

/* Time complexity is O(n) and space complexity is O(n) */

bool is_word_break_possible(std::string str, set<std::string> const dictionary){
    int n = str.size();
    bool dp[n+1]{false};
    dp[0] = true;
    for(int i = 1; i < n+1; i++){
        for(int j = i - 1; j > -1; j--){
            std::string prefix = str.substr(j,i);
            if(dp[j] && dictionary.find(prefix) != dictionary.end())
                dp[i] = true;
        }
    }
    return dp[n];
}

int main(){
    std::string str = "abcdef";
    set<std::string> dictionary{"ab", "cd", "abcd", "ef"};
    map<std::string,bool> memo;
    // cout << is_word_break_possible(str, dictionary, memo);
    cout << is_word_break_possible(str, dictionary);
    
}