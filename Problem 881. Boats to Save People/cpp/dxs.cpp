class Solution 
{
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        vector<int>& vecWeights=people;
        sort(vecWeights.begin(), vecWeights.end());
        int i=0,j=vecWeights.size()-1;
        int i32Res=vecWeights.size();
        int& i32Limit=limit;
        
        while(i<j)
        {
            int find=0;
            while(j>i)
            {
                if(vecWeights[j]+vecWeights[i]<=i32Limit)
                {
                    find=1;
                    break;
                }
                j--;
            }
            if(find)
            {
                i32Res--;
                i++; 
                j--;
            }
            else
            {
                break;
            }
        }
        return i32Res;      
        
    }
};