/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order
Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    do {
    	ans.push_back(nums);
    } while(next_permutation(nums.begin(), nums.end()));
    return ans;
}

void print(vector<int>& v){
	cout<<"[";
	for(int num : v)
		cout << num <<", ";
	cout << "]";
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	vector<int>nums;
	int number;

	while(cin>>number){
		nums.push_back(number);
	}

	vector<vector<int>> vv = permuteUnique(nums);
	for(vector<int>& v :vv){
		print(v);
	}

	return 0;
}
