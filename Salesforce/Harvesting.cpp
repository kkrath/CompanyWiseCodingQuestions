#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int findKMaxSum(vector<int> const arr, int curr, int count, int const k, int curr_sum){
        /* base case */
        if(count == k)
            return curr_sum;
        if(curr >= arr.size())
            return 0;;
        int selct_sum  = findKMaxSum(arr, curr+1, count+1, k, curr_sum+arr[curr]);
        int reejct_sum = findKMaxSum(arr, curr+1, count, k, curr_sum);
        return max(selct_sum, reejct_sum);
}


int main(){
    vector<int> arr = {3,6,-7,9,2,1};
    int k = 2;
    cout << findKMaxSum(arr, 0, 0, k, 0);

}