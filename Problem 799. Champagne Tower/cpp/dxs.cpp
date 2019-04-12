class Solution 
{
public:
    double champagneTower(int i32Poured, int i32Row, int i32Line) 
    {
        vector<vector<double>> vec2dWine(i32Row+2, vector<double>(i32Row+2,0));
        vec2dWine[0][0]=i32Poured;
        
        for(int i=0;i<i32Row;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(vec2dWine[i][j]>1)
                {
                    vec2dWine[i+1][j]+=(vec2dWine[i][j]-1)/2;
                    vec2dWine[i+1][j+1]+=(vec2dWine[i][j]-1)/2;
                    vec2dWine[i][j]=1;
                }
            }
        }
        return vec2dWine[i32Row][i32Line]>1?1:vec2dWine[i32Row][i32Line];
    }
};