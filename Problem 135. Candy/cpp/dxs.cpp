class Solution 
{
public:
    int candy(vector<int>& ratings) 
    {
        int i32Result=0;
        int i32OverLap=0;
        vector<int>& vecRates=ratings;
        int i32CountUp=0;
        int i32CountDown=0;
        for (int i=0;i<vecRates.size();i++)
        {
            if(i==0)
            {
               i32CountUp++; 
            }
            else if(vecRates[i]==vecRates[i-1])
            {
                i32Result+=getRes(i32CountUp, i32CountDown+1);
                i32CountUp=i32CountDown=0;
                i32CountUp+=1;
            }
            else if(i32CountDown==0)
            {
                if(vecRates[i-1]<vecRates[i])
                {
                    i32CountUp++;
                }
                else
                {
                    i32CountDown++;
                }
            }
            else if(i32CountDown>0)
            {
                if(vecRates[i-1]<vecRates[i])
                {
                    i32Result+=getRes(i32CountUp, i32CountDown+1);
                    i32CountUp=i32CountDown=0;
                    i32CountUp+=2;
                    i32OverLap+=1;
                }
                else
                {
                    i32CountDown++;
                }
            }
        }
        i32Result+=getRes(i32CountUp, i32CountDown+1);
        return i32Result-i32OverLap;
    }
    
private:
    int getRes(int i32Up, int i32Down)
    {
        int i32Max=i32Up>i32Down?i32Up:i32Down;
        int i32Min=i32Up<i32Down?i32Up-1:i32Down-1;
        return (i32Min+1)*i32Min/2+i32Max*(i32Max+1)/2;
    }
};