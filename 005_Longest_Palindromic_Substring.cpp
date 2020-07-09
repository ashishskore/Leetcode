class Solution {
public:
    pair<int,int>expand(const string& s,int size,int left,int right)
    {
        int curMax = 0;
        if(left==right)
        {
            curMax = 1;
            left -= 1;
            right += 1;
        }    
        while(left>=0 && right < size && s[left] == s[right])
        {
            curMax+=2;
            --left;++right;
        }    
        return {curMax, left+1};
    }
    string longestPalindrome(string s) {
        int size = s.length();
        if(size==0)
            return s;
        int max = 0;
        int start = 0;
        string ret;
        for(int i=0;i<size;i++)
        {
            auto t = expand(s,size,i,i);
            if(max < t.first)
            {
                max = t.first;
                start = t.second;
            }
            t = expand(s,size, i,i+1);
            if(max < t.first)
            {
                max = t.first;
                start = t.second;
            }
        }
        cout<<start<<","<<max<<endl;
        ret = s.substr(start,max);
        return ret;
    }
};