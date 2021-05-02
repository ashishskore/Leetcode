class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int j=0;
        int size = nums.size();
        for(int i = 0; i < size; ++i)
        {
            if(nums[j]!=nums[i])
            {
                ++j;
                nums[j] = nums[i];
            }
        }
        
        return ++j;
    }
};
