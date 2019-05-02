class Solution 
{
private:
    double binarySearch(int i32L, int i32R, vector<int>& vecNums1, vector<int>& vecNums2)
    {
        int i32Len1=vecNums1.size();
        int i32Len2=vecNums2.size();
        while(i32R-i32L>=2)
        {
            //cout<<i32L<<" "<<i32R<<endl;
            int i32Mid=i32L+((i32R-i32L)>>1);
            //cout<<i32Mid<<endl;
            int i32I=i32Mid;
            int i32J=(i32Len1+i32Len2)/2-i32I;
            int i32Num1LeftMax=i32I-1>=0?vecNums1[i32I-1]:0xFFFFFFFF;
            int i32Num1RightMin=i32I<=i32Len1-1?vecNums1[i32I]:0x7FFFFFFF;
            int i32Num2LeftMax=i32J-1>=0?vecNums2[i32J-1]:0xFFFFFFFF;
            int i32Num2RightMin=i32J<=i32Len2-1?vecNums2[i32J]:0x7FFFFFFF;
            
            if(i32Num1LeftMax>i32Num2RightMin)
            {
                i32R=i32Mid-1;
                //cout<<'r'<<endl;
            }
            else if(i32Num2LeftMax>i32Num1RightMin)
            {
                i32L=i32Mid+1;
                //cout<<'l'<<endl;
            }
            else
            {
                if((i32Len1+i32Len2)%2==0)
                {
                    return (max(i32Num1LeftMax,i32Num2LeftMax)+min(i32Num1RightMin,i32Num2RightMin))*1.0/2;
                }
                else
                {
                    return min(i32Num1RightMin,i32Num2RightMin);
                }
            }
        }
        
        int i32I=i32L;
        int i32J=(i32Len1+i32Len2)/2-i32I;
        int i32Num1LeftMax=i32I-1>=0?vecNums1[i32I-1]:0xFFFFFFFF;
        int i32Num1RightMin=i32I<=i32Len1-1?vecNums1[i32I]:0x7FFFFFFF;
        int i32Num2LeftMax=i32J-1>=0?vecNums2[i32J-1]:0xFFFFFFFF;
        int i32Num2RightMin=i32J<=i32Len2-1?vecNums2[i32J]:0x7FFFFFFF;
        if(i32Num1LeftMax<=i32Num2RightMin&&i32Num2LeftMax<=i32Num1RightMin)
        {
            if((i32Len1+i32Len2)%2==0)
            {
                return (max(i32Num1LeftMax,i32Num2LeftMax)+min(i32Num1RightMin,i32Num2RightMin))*1.0/2;
            }
            else
            {
                return min(i32Num1RightMin,i32Num2RightMin);
            }
        }
        else
        {
            int i32I=i32R;
            int i32J=(i32Len1+i32Len2)/2-i32I;
            int i32Num1LeftMax=i32I-1>=0?vecNums1[i32I-1]:0xFFFFFFFF;
            int i32Num1RightMin=i32I<=i32Len1-1?vecNums1[i32I]:0x7FFFFFFF;
            int i32Num2LeftMax=i32J-1>=0?vecNums2[i32J-1]:0xFFFFFFFF;
            int i32Num2RightMin=i32J<=i32Len2-1?vecNums2[i32J]:0x7FFFFFFF;
            if((i32Len1+i32Len2)%2==0)
            {
                return (max(i32Num1LeftMax,i32Num2LeftMax)+min(i32Num1RightMin,i32Num2RightMin))*1.0/2;
            }
            else
            {
                return min(i32Num1RightMin,i32Num2RightMin);
            }
        } 
    }
public:
    double findMedianSortedArrays(vector<int>& vecNums1, vector<int>& vecNums2) 
    {
        if(vecNums1.size()<=vecNums2.size())
        {
            return binarySearch(0,vecNums1.size(), vecNums1, vecNums2);
        }
        else
        {
            return binarySearch(0,vecNums2.size(), vecNums2, vecNums1);
        }
        
    }
};