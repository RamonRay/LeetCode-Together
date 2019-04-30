class Solution 
{
private:
    char substitute(char ch0, int i32Times)
    {
        int i32New=ch0+i32Times;
        //cout<<int('z')<<" "<<int(chNew)<<endl;
        if(i32New>'z')i32New=i32New-26;
        
        return char(i32New);
    }
public:
    string shiftingLetters(string S, vector<int>& vecShifts) 
    {
        //cout<<0x7FFFFFFF<<endl;
        int i32Len=vecShifts.size();
        vector<int> vecTimes(i32Len, 0);
        long long i64SumTimes=0;
        
        for(int i=0;i<i32Len;i++)i64SumTimes=((i64SumTimes)+(vecShifts[i]))%26;
        //i64SumTimes=i64SumTimes%26;
        for(int i=0;i<i32Len;i++)
        {
            //cout<<i64SumTimes<<endl;
            //stupid c could get negetive int from % operation
            vecTimes[i]=i64SumTimes%26;
            i64SumTimes=(i64SumTimes%26-vecShifts[i]%26+26)%26;
            
        }
        
        for(int i=0;i<i32Len;i++)
        {
            S[i]=substitute(S[i], vecTimes[i]);
        }
        return S; 
    }
};