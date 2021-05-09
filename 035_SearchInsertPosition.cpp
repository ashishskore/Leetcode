/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
Example 4:

Input: nums = [1,3,5,6], target = 0
Output: 0
Example 5:

Input: nums = [1], target = 0
Output: 0

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& v){
    cout<<"v: [";
    for(int i : v)
        cout<< i << ", ";
    cout << "]"<< endl;
}

int searchInsert(vector<int>& v, int target) {
    int left = 0; 
    int right = v.size() -1;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(v[mid] == target) return mid;
        if(v[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return right + 1;
}

int main(){
    vector<int>v{1,3,5,6};
    int target = 0;
    print(v);
    cout << "Data : "<< searchInsert(v,target) << endl;
    return 0;
}
