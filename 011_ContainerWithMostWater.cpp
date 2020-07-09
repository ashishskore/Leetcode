class Solution {
public:
    int maxArea(vector<int>& v) 
    {
        int maximumArea = 0;
        int previ = 0;
        for(int i = 0; i<v.size()-1; i++) {
            if(previ > 0 && v[previ] >= v[i])
                continue;
            for(int j = v.size()-1;j > i; j--) {
                maximumArea = max(maximumArea, (j - i) * min(v[i], v[j]));
                if(v[i] <= v[j]) break;
            }
            previ = i;
        }
        return maximumArea;
    }
};