class Solution 
{
public:
    int maximumGap(vector<int>& vecNums)
    {
        int i32Len = vecNums.size();
        if(i32Len<2)return 0;
        int i32MaxVal = 0;
        for (int i=0;i<i32Len;i++)
        {
            if(vecNums[i]>i32MaxVal)i32MaxVal=vecNums[i];
        }
        i32MaxVal++;
        vector<vector<int>> vec2dBarrel(i32Len, vector<int>());
        for (int i=0;i<i32Len;i++)
        {
            vec2dBarrel[i32Len*(vecNums[i]/i32MaxVal)].push_back(vecNums[i]);
        }
        for (int i=0;i<i32Len;i++)
        {
            sort(vec2dBarrel[i].begin(),vec2dBarrel[i].end());
        }
        int i32MaxGap = 0;
        int i32LastVal = vec2dBarrel[0][0];
        for (int i=0;i<i32Len;i++)
        {
            for (int j=0;j<vec2dBarrel[i].size();j++)
            {
                if(i32MaxGap<vec2dBarrel[i][j]-i32LastVal)i32MaxGap=vec2dBarrel[i][j]-i32LastVal;
                i32LastVal=vec2dBarrel[i][j];
            }
        }
        return i32MaxGap;
        
    }
};