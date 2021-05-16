/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.
*/

class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> vv;
    map<string, int> mp;
    string s;
    int index = 0;
    for(string str : strs)
    {
    	s = str;
    	sort(str.begin(), str.end());
    	auto pr = mp.find(str);
    	if(pr != mp.end()){
    		// found
    		vv[(*pr).second].push_back(s);
    	} else {
    		// Not Found push back
    		vector<string> lv {s};
    		vv.push_back(lv);
    		mp[str] = index++;
    	}
    }
    return vv;
}
};
