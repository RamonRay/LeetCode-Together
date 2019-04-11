class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& vec2dObsGrid) 
    {
        int i32H=vec2dObsGrid.size();
        int i32W=vec2dObsGrid[0].size();
        vector<vector<long long>> vec2dDp(i32H,vector<long long>(i32W,0));
            
        if(vec2dObsGrid[0][0]==0)vec2dDp[0][0]=1;
        for(int j=1;j<i32W;j++)
        {
            if(vec2dObsGrid[0][j]==0)vec2dDp[0][j]=vec2dDp[0][j-1];
        }
        for(int i=1;i<i32H;i++)
        {
            if(vec2dObsGrid[i][0]==0)vec2dDp[i][0]=vec2dDp[i-1][0];
            for(int j=1;j<i32W;j++)
            {
                if(vec2dObsGrid[i][j]==0)vec2dDp[i][j]=vec2dDp[i-1][j]+vec2dDp[i][j-1];
            }
        }
        return vec2dDp[i32H-1][i32W-1];
        
    }
};