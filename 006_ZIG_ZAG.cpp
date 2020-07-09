class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if(numRows <= 1)
            return s;
        int slab = numRows + (numRows - 2);
        int curslab = slab;
        string ret;
        ret.reserve(size);
        for(int i =0;i<numRows;i++)
        {
            int f = 0;
            for(int j =0; j<size;j++)
            {
                f = i + (j*slab);
                if(f>=size)
                    break;
                ret += s[f];
                if(curslab == 0 || curslab == slab)
                    continue;
                f += curslab;
                if(f>=size)
                    break;
                ret += s[f];
            }
            curslab -= 2;
        }
        return ret;
    }
};