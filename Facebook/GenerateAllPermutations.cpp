#include<iostream>
#include<vector>
using namespace std;

void printAll(std::string str, vector<char> permutation, int const n){
    
    if(permutation.size() == n){
        for(auto ch : permutation)
            cout<< ch;
        cout << endl;
        return;
    }

    for(int i = 0; i < str.size(); i++){
        std:string nex_str = str.substr(0,i) + str.substr(i+1);
        permutation.push_back(str[i]);
        printAll(nex_str, permutation, n);
        permutation.pop_back();
    }
}


int main()
{
    std::string str = "ABC";
    vector<char> permutations;
    int n = str.size();
    printAll(str, permutations, n);
}