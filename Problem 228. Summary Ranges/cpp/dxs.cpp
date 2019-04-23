class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& vecNums) 
    {
        vector<string> vecRes;
        int i32L=-1, i32R=-1;
        int i32Len=vecNums.size();
        if (i32Len==0)return vecRes;
        
        for (int i=0;i<i32Len;i++)
        {
            if(i32L==-1)
            {
                i32L=i32R=i;
            }
            else
            {
                if(vecNums[i]==vecNums[i-1]+1)
                {
                    i32R=i;
                }
                else
                {
                    if(i32R==i32L)
                    {
                        char strTemp[100];
                        sprintf(strTemp,"%d",vecNums[i32L]);
                        vecRes.push_back(strTemp);
                    }
                    else
                    {
                        char strTemp[100];
                        sprintf(strTemp,"%d->%d",vecNums[i32L],vecNums[i32R]);
                        vecRes.push_back(strTemp);
                    }
                    i32L=i32R=i;
                }
            }
        }
        
        if(i32R==i32L)
        {
            char strTemp[100];
            sprintf(strTemp,"%d",vecNums[i32L]);
            vecRes.push_back(strTemp);
        }
        else
        {
            char strTemp[100];
            sprintf(strTemp,"%d->%d",vecNums[i32L],vecNums[i32R]);
            vecRes.push_back(strTemp);
        }
        
        return vecRes;
        
    }
};