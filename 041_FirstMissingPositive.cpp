/*
Given an unsorted integer array nums, find the smallest missing positive integer.
Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
 

Constraints:

1 <= nums.length <= 300
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space?
*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    set<int> st;
    for(int i : nums){
        if (i > 0 )
            st.insert(i);
    }
    int i = 1;
    for(int ele : st){
        // cout << ele <<endl;
        if(ele != i)
            return i;
        i++;
    }
    return i;
}

int main()
{
    vector<int>v{3,4,-1,1};
    cout << firstMissingPositive(v) << "\n";
    return 0;
}
