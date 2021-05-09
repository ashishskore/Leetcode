/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/


#include<iostream>
#include<vector>
using namespace std;

int first(vector<int>& v, int target){
    int left = 0;
    int right = v.size()-1;
    bool found = false;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(v[mid] == target) found = true;
        if(v[mid]>=target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return found? right+1 : -1;
}

int last(vector<int>&v, int target){
    int left = 0;
    int right = v.size() - 1;
    bool found = false;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(v[mid] == target) found = true;
        if(v[mid] <= target){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return found? left - 1 : -1;
}

vector<int> solve(vector<int>&v, int target){
    // int l1 = first(v,target);
    // int l2 = last(v,target);
    // cout <<"L1 = " <<l1 << "\n";
    // cout <<"L2 = " << l2 << "\n";
    vector<int> sol {first(v,target), last(v,target)};
    return sol;
}

void print (vector<int>v){
    cout << "v : " ;
    for(int i :v){
        cout<<i <<", ";
    }
    cout<<"\n";
    cout.flush();
}

int main(){
    vector<int> v{};
    int target = 11;
    print(v);
    print(solve(v,target));
    return 0;
}
