class Solution 
{
public:
    int superEggDrop(int K, int N) 
    {
        vector<vector<int>> a2dStep(K+1, vector<int>(N+1,-1));
        return getStep(K, N, a2dStep);
    }
private:
    int getStep(int i32K, int i32N, vector<vector<int>>& a2dStep)
    {
        if(a2dStep[i32K][i32N]!=-1)
        {
            return a2dStep[i32K][i32N];
        }
        int i32Res=0;
        if(i32K==1)
        {
            i32Res=i32N;
        }
        else if(i32N<=1)
        {
            i32Res=i32N;
        }
        else
        {
            int i32Left=1, i32Right=i32N;
            int i32Mid;
            int i32VaUp,i32VaDown;
            while(i32Left<i32Right)
            {
                i32Mid=(i32Left+i32Right)>>1;
                i32VaUp=getStep(i32K-1, i32Mid-1, a2dStep);
                i32VaDown=getStep(i32K, i32N-i32Mid, a2dStep);
                if(i32VaUp<i32VaDown)
                {
                    i32Left=i32Mid+1;
                }
                else if(i32VaUp>i32VaDown)
                {
                    i32Right=i32Mid;
                }   
                else
                {
                    break;
                }
            }
            i32Res=i32VaUp>i32VaDown?i32VaUp+1:i32VaDown+1;
        }
        
        a2dStep[i32K][i32N]=i32Res;
        return a2dStep[i32K][i32N];
    }
};