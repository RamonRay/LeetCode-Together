class NumMatrix 
{
private:
    vector<vector<int>> vec2dMatrix;
    vector<vector<int>> vec2dSum;
public:
    NumMatrix(const vector<vector<int>>& matrix) 
    {
        if(matrix.size()==0)return;
        vec2dMatrix.assign(matrix.begin(),matrix.end());
        int i32R=vec2dMatrix.size();
        int i32C=vec2dMatrix[0].size();
        //cout<<i32R<<i32C<<endl;
        vec2dSum=vector<vector<int>>(i32R,vector<int>(i32C,0));

        for (auto j=0;j<i32C;j++)
        {
            if(j==0)
            {
                vec2dSum[0][j]=vec2dMatrix[0][j];
            }
            else
            {
                vec2dSum[0][j]=vec2dMatrix[0][j]+vec2dSum[0][j-1];
            } 
            //cout<<vec2dSum[0][j]<<" ";
        }
        //cout<<endl;
        for (auto i=1;i<i32R;i++)
        {
            for (auto j=0;j<i32C;j++)
            {
                if(j==0)
                {
                    vec2dSum[i][j]=vec2dMatrix[i][j]+vec2dSum[i-1][j];
                }
                else
                {
                    vec2dSum[i][j]=vec2dMatrix[i][j]+vec2dSum[i][j-1]+vec2dSum[i-1][j]-vec2dSum[i-1][j-1];
                }  
                //cout<<vec2dSum[i][j]<<" ";
            }
            //cout<<endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        //return 0;
        if(row1*col1!=0)
        {
            return vec2dSum[row2][col2]-vec2dSum[row2][col1-1]-vec2dSum[row1-1][col2]+vec2dSum[row1-1][col1-1];
        }
        else if(row1==0&&col1!=0)
        {
            return vec2dSum[row2][col2]-vec2dSum[row2][col1-1];
        }
        else if(row1!=0&&col1==0)
        {
            return vec2dSum[row2][col2]-vec2dSum[row1-1][col2];
        }
        else if(row1==0&&col1==0)
        {
            return vec2dSum[row2][col2];
        }
        return 0;
    }

};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */