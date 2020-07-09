class Solution {
public:
    int reverse(int x) {
        long long t=0;
        int n = x;
        x = abs(x);
        while(x>0)
        {
            if(INT_MAX / 10 < t )
                return 0;
            else
                t = t*10;
            if((INT_MAX - (x%10)) < t)
                return 0;
            t += (x%10);
            x/=10;
        }
        if(n<0)
            t = 0-t;
        return t;
    }
};