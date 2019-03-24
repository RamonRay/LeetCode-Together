class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        vector<vector<int>>& vec2dGrid=grid;
        vector<int> vecM(vec2dGrid[0].size(), 0);
        
        int i32Sum=0;
        for(int j=0;j<vec2dGrid[0].size();j++)
        {
            i32Sum+=vec2dGrid[0][j];
            vecM[j]=i32Sum;
            //cout<<vecM[j]<<endl;
        }
        for (int i=1;i<vec2dGrid.size();i++)
        {
            for(int j=0;j<vec2dGrid[0].size();j++)
            {
                if(j==0)
                {
                    vecM[j]=vecM[j]+vec2dGrid[i][j];
                }
                else
                {
                    vecM[j]=min(vecM[j-1]+vec2dGrid[i][j],vecM[j]+vec2dGrid[i][j]);
                }
                //cout<<vecM[j]<<endl;
            }
        }
        
        return vecM[vec2dGrid[0].size()-1];
    }
private:
     int min(int a,int b)
     {
         return a<b?a:b;
     }
};