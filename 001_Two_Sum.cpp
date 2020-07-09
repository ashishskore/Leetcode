class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size= nums.size();
        unordered_map<int,int> vals;
        vals[nums[0]] = 0;
        vector<int>ret={-1,-1};
        for(int i=1;i<size;i++)
        {
            auto found = vals.find(target-nums[i]);
            if(found != vals.end())
            {
                ret[0]=(*found).second;
                ret[1]=i;
                break;
            }
            else
            {
                vals[nums[i]] = i;
            }
        }
        return ret;
    }
};