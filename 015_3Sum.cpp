class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int previ = INT_MIN ,prevj = INT_MIN;
        map<int, vector<int>> m;
        sort(nums.begin(),nums.end());
        int twos = 0;
        for(auto i=nums.begin();i<nums.end();i++)
        {
            if(*i>0)break;
            for(auto j = i+1; j<nums.end();j++)
            {
                twos = *i + *j;
                if(twos > 0) break;
                auto it = m.find(*i);
                if(it == m.end())
                {
                    if( binary_search(j+1, nums.end(),0-twos))
                    {
                        m.emplace(*i,vector<int>{*j});
                        ret.emplace_back(vector<int>{*i,*j,0-twos});
                    }
                } else {
                    if(!binary_search(it->second.begin(), it->second.end(),*j)){
                        if(binary_search(j+1, nums.end(),0-twos))
                        {
                            it->second.emplace_back(*j);
                            ret.emplace_back(vector<int>{*i,*j,0-twos});
                        }
                    }
                }
            }
        }
        return ret;
    }
};
