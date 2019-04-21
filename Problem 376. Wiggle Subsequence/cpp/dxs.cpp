class Solution 
{
public:
    int wiggleMaxLength(vector<int>& vecNums) 
    {
        int i32Len=vecNums.size();
        if(i32Len==0)return 0;
        
        vector<int> vecUp(i32Len, 0);
        vector<int> vecDown(i32Len, 0);
        vecUp[0]=1;
        vecDown[0]=1;
        
        for(int i=1;i<i32Len;i++)
        {
            if(vecNums[i]>vecNums[i-1])
            {
                vecUp[i]=vecDown[i-1]+1;
                vecDown[i]=vecDown[i-1];
                
            }
            else if(vecNums[i]<vecNums[i-1])
            {
                vecDown[i]=vecUp[i-1]+1;
                vecUp[i]=vecUp[i-1];
            }
            else if((vecNums[i]==vecNums[i-1]))
            {
                vecUp[i]=vecUp[i-1];
                vecDown[i]=vecDown[i-1];
            }
        }
         
        return max(vecDown[i32Len-1], vecUp[i32Len-1]);
    }
};