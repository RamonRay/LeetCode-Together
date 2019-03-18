class Solution {
public:
    int maxSubArray(vector<int>& vecNums) 
    {
        int i32Len = vecNums.size();
        if (i32Len<1)
        {
            cout<<"Wrong!"<<endl;
            return 0;
        }
        
        vector<pair<int, int>> vecRes(i32Len, make_pair<int,int>(0x80000000, 0x80000000));
        vecRes[0].first = vecNums[0];
        
        for (int i=1; i<i32Len; i++)
        {
            vecRes[i].first = max(vecRes[i-1].first+vecNums[i], vecNums[i]);
            vecRes[i].second = max(vecRes[i-1].first, vecRes[i-1].second);
        }
        
        
        return max(vecRes[i32Len-1].first, vecRes[i32Len-1].second);
    }
private:
    int max(int a, int b)
    {
        return a>b?a:b;
    }
};