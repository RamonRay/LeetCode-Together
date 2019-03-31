class Solution 
{
public:
    int smallestDistancePair(vector<int>& vecNums, int i32K) 
    {
        sort(vecNums.begin(),vecNums.end());
        int i32Left=0;
        int i32Right=vecNums[vecNums.size()-1]-vecNums[0];
        int i32Mid;
        while(i32Left<i32Right)
        {
            i32Mid=(i32Left+i32Right)>>1;
            int i32Count=countLEPairs(vecNums, i32Mid);
            //cout<<i32Left<<" "<<i32Right<<" "<<i32Mid<<" "<<i32Count<<endl;
            if(i32Count<i32K)
            {
                i32Left=i32Mid+1;
            }
            else
            {
                i32Right=i32Mid;
            }
        }
        return i32Right;
        
    }
private:
    int countLEPairs(vector<int>& vecNums, int i32Thresh)
    {
        int i32L=0,i32R=0;
        int i32Res=0;
        
        for(i32R=0;i32R<vecNums.size();i32R++)
        {
            while(vecNums[i32R]-vecNums[i32L]>i32Thresh)
            {
                i32L++;
            }
            i32Res+=i32R-i32L;
        }
        return i32Res;
    }
};




















/////////////////////////////////////////////////////////////////////////////
/*class Solution 
{
public:
    int smallestDistancePair(vector<int>& vecNums, int i32K) 
    {
        vector<int> vecRes(i32K,0x7FFFFFFF);
        sort(vecNums.begin(), vecNums.end());
        for(int i=1;i<vecNums.size();i++)
        {
            vector<int> vecNewDis;
            for(int j=i-1;j>=max(0,i-i32K);j--)
            {
                vecNewDis.push_back(abs(vecNums[i]-vecNums[j]));
            }
            vecRes=mergeSortedVec(vecNewDis,vecRes,i32K);
        }
        return vecRes[i32K-1];
    }
private:
    vector<int> mergeSortedVec(vector<int> vec1, vector<int> vec2,int i32K)
    {
        int i32Time=i32K;
        int i=0,j=0;
        vector<int> vecR;
        while(i32Time>0)
        {
            i32Time--;
            
            if(i<vec1.size() && j<vec2.size())
            {
                if(vec1[i]<vec2[j])
                {
                    vecR.push_back(vec1[i]);
                    i++;
                }
                else
                {
                    vecR.push_back(vec2[j]);
                    j++;
                }
            }
            else if(i<vec1.size() && j>=vec2.size())
            {
                vecR.push_back(vec1[i]);
                i++;
            }
            else if(i>=vec1.size() && j<vec2.size())
            {
                vecR.push_back(vec2[j]);
                j++;
            }
            else
            {
                break;
            }
        }
        return vecR;
    }
};*/