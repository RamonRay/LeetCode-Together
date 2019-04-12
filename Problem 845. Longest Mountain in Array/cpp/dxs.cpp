class Solution 
{
public:
    int longestMountain(vector<int>& vecArray) 
    {
        int i32Len=vecArray.size();
        if(i32Len==0)return 0;
        vector<int> vecUp(i32Len,0);
        vector<int> vecDown(i32Len,0);
        int i32Max=0;
        
        vecUp[0]=1;
        for(int i=1;i<i32Len;i++)
        {
            if(vecArray[i]>vecArray[i-1])
            {
                vecUp[i]=vecUp[i-1]+1;
            }
            else
            {
                vecUp[i]=1;
            }
        }
        
        vecDown[i32Len-1]=1;
        for(int i=i32Len-2;i>=0;i--)
        {
            if(vecArray[i]>vecArray[i+1])
            {
                vecDown[i]=vecDown[i+1]+1;
            }
            else
            {
                vecDown[i]=1;
            }
        }
        
        for(int i=0;i<i32Len;i++)
        {
            if(vecUp[i]>=2&&vecDown[i]>=2)
            i32Max=max(i32Max,vecUp[i]+vecDown[i]-1);
        }
        
        return i32Max;
    }
};