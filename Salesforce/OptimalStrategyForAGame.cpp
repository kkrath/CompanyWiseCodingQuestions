#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int gameStrategy(vector<int> const array, int sum, int i, int j){
    /* select optimal stratey */
    if(j == i + 1)
        return max(array[i], array[j]);
    return max(sum - gameStrategy(array, sum- array[i],i+1,j),sum - gameStrategy(array, sum- array[j],i,j-1));
}

int main(){
    vector<int> coins{ 8, 15, 3, 7 };
    int sum  = accumulate(coins.begin(),coins.end(), sum);
    cout << gameStrategy(coins, sum, 0, coins.size()-1);
}