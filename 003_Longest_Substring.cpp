class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxvalue = 0;
        int current = 0;
        unordered_map<char,int> hash;
        int index = 0;
        for(char c:s)
        {
            auto found = hash.find(c);
            if(found == hash.end())
            {
                ++current;
            }
            else{
                current = min (index - (*found).second, current+1);
            }
            hash[c] = index;
            maxvalue = max(maxvalue,current);
            ++index;
        }
        return maxvalue;
    }
};