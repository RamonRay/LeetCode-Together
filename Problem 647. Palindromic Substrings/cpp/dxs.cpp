class Solution 
{
public:
    int countSubstrings(string s) 
    {
        string& strS=s;
        int i32Len=strS.size();
        int i32Total=0;
        vector<vector<bool>> vec2dRes(i32Len, vector<bool>(i32Len,0));
        
        for (int i=0;i<i32Len;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==i)
                {   
                    vec2dRes[j][i]=1;
                }
                else if(j==i-1&&strS[j]==strS[i])
                {
                    vec2dRes[j][i]=1;
                }
                else if(strS[j]==strS[i]&&vec2dRes[j+1][i-1])
                {
                    vec2dRes[j][i]=1;
                } 
            }
        }
        
        for (int i=0;i<i32Len;i++)
        {
            for(int j=0;j<=i;j++)
            {
                i32Total+=vec2dRes[j][i];
            }
        }
        return i32Total;
    }
};