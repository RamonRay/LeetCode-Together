class Solution 
{
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        vector<int>& vecArray=A;
        int i32Result=0;
        if(vecArray.size()<3)return i32Result;
        vector<int> vecRecord(vecArray.size(),0);
        
        for (int i=0+2;i<vecArray.size();i++)
        {
            if(vecArray[i]-vecArray[i-1]==vecArray[i-1]-vecArray[i-2])
            {
                vecRecord[i]=vecRecord[i-1]+1;
            }
            i32Result+=vecRecord[i];
        }
        return i32Result;   
    }
};