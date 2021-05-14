/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105
*/


#include<iostream>
#include<vector>
using namespace std;

int TrapRainWater(vector<int>&v) {
    int li = 1;
    int ri = v.size()-1;
    if(ri<2)
        return 0;
        
    int lmax = v[0];
    int rmax = v[ri];
    ri -= 1;
    int ans = 0;
    int curlevel = min(lmax, rmax);
    bool IsLeft = lmax < rmax;
    
    while(li <= ri) {
        if(IsLeft){
            if(v[li]>curlevel){
                lmax = v[li];
            } else {
                ans += curlevel - v[li];
            }
            li++;
        } else {
            if(v[ri]>curlevel){
                rmax = v[ri];
            } else {
                ans += curlevel - v[ri];
            }
            ri--;
        }
        curlevel = min(lmax, rmax);
        IsLeft = lmax < rmax;
    }
    return ans;
}

int main(){
    // vector<int> v{0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v{4,0,5};
    cout << "Answer : " << TrapRainWater(v) <<endl;
    return 0;
}
