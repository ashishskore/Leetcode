class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string s = to_string(x);
        int siz = s.size();
        int mid = siz/2;
        for(int i = 0; i < mid; ++i)
            if(s[i] != s[siz-1 - i]) return false;
        return true;
        // if(x < 0) return false;
        // int y = x;
        // long rev = 0;
        // while(y > 0)
        // {
        //     rev = rev* 10+(y%10);
        //     y /= 10;
        // }
        // return rev == x? true:false;
    }
};