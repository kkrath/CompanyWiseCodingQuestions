#include<iostream>
#include<vector>
using namespace std;

void moveZerosToLeft(vector<int> &array){
    int n = array.size();
    if(n == 0)
        return;
    int zero_pointer = -1;
    int reg_pointer = 0;
    while(reg_pointer < n ){
        if(array[reg_pointer] == 0){
            for(int i = reg_pointer-1; i > zero_pointer; i--){
                array[i+1] = array[i];
            }
            array[++zero_pointer] = 0;
        }
        reg_pointer++;
    }

}
\
/* Runtime Complexity of this algortihm is O(n) and space complexity is O(1) */

void moveZerosToLeftFast(vector<int> &array){
    int n = array.size();
    if(n < 1)
        return;
    int non_zero_pointer = n - 1;
    int reg_pointer = n -1 ;
    while(reg_pointer >= 0){
        if(array[reg_pointer] != 0){
            array[non_zero_pointer--] = array[reg_pointer];
        }
        reg_pointer--;
    }

    while(non_zero_pointer >= 0){
        array[non_zero_pointer--] = 0;
    }

}

int main(){
    vector<int> array{1,0,0,0,0,0,1};
    moveZerosToLeftFast(array);
    for(auto arr: array)
        cout << arr << ",";
    cout <<  endl;
}