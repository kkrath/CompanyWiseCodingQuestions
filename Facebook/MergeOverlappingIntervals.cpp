#include<iostream>
#include<vector>
using namespace std;

pair<int, int> findOverlappingIntervals(vector<pair<int,int>> intervals){

    if(intervals.size() < 1)
        return make_pair(0,0);

    pair<int, int> interim_pair = make_pair(1,1);
    for(auto interval : intervals){
        int first , second = 0;
        if(interim_pair.second >= interval.first){
            first = min(interim_pair.first,interval.first);
            second = max(interim_pair.second, interval.second);
        }else{
            first = interim_pair.first;
            second = interval.second;
        }
        interim_pair = make_pair(first, second);
    }
    return interim_pair;
}

int main(){
    vector<pair<int,int>> intervals{make_pair(1,5),make_pair(2,4),make_pair(3,9),make_pair(4,6),make_pair(5,6),make_pair(6,8)};
    pair<int, int> overlapping_interval = findOverlappingIntervals(intervals);
    cout << overlapping_interval.first << "," << overlapping_interval.second;
}