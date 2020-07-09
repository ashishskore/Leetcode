class Solution {
public:
    int myAtoi(string str) {
    string word = "";
    stringstream ss(str);
    bool negate = false;
    int i = 0;
    int ans = 0;
    const int divlimit = INT_MAX/10;
    if (ss>>word)
    {
        if(word[i] == '-' || word[i] == '+' || (word[i]>='0'&&word[i]<='9'))
        {
            if(word[i] == '-') {negate = true; i = 1;}
            if(word[i] == '+') { i = 1;}
            unsigned int size = word.size();
            while(i < size)
            {
                if((word[i]>='0'&&word[i]<='9'))
                {
                    if(divlimit < ans || INT_MAX - (word[i]&0x0F) < (ans * 10))
                    {
                        if(negate) return INT_MIN;
                        else return INT_MAX;
                    }
                    ans = ans * 10 + (word[i]&0x0F);
                }
                else break;
                i++;
            }
            if(negate)
                ans = 0 - ans;
        }
    }
    return ans;
}
};