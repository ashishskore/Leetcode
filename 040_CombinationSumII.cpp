/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/



#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void combination(vector<int>&v, int size, int start, int target, vector<int>&current, set<vector<int>>& res){
    if (target == 0) {
        res.insert(current);
        return;
    }

    if(target < 0 ) return;

    for(int i=start; i < size; i++){
        current.push_back(v[i]);
        combination(v, size, i+1, target - v[i],current, res);
        current.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    set<vector<int>> result;
    sort(candidates.begin(),candidates.end());
    int size = candidates.size();
    vector<int> current;
    combination(candidates,size,0,target, current, result);
    vector<vector<int>> res(result.begin(), result.end());
    return res;
}

void print (vector<int> v){
    cout<<"data : [";
    for(int i : v)
        cout<< i << ", ";
    cout<< "]" << endl;
}

int main(){
    vector<int> v {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> result;
    result = combinationSum2(v, target);
    cout <<"["<<endl;
    for(auto res : result)
        print(res);
    cout <<"]"<<endl;
    return 0;
}
