class Solution 
{

public:
    double new21Game(int i32N, int i32K, int i32W) 
    {
        if(i32K==0)return 1.0;
        //vector<double> vecP(i32K-1+i32W+1, 0);
        vector<double> vecP(i32K-1+i32W+2, 0);
        vecP[0]=1;
        vecP[1]=1.0/i32W;
        //vector<double> vecPP(i32K-1+i32W+2, 0);
        //vecPP[0]=1;
        //vecPP[1]=1.0/i32W;
        double dSum=0;
        double dRes=0;
        for(int i=2;i<=i32K-1+i32W;i++)
        {
            if(i<=i32K)
            {
                double dTemp=i-1-i32W>=0?vecP[i-1-i32W]:0;
                vecP[i]=vecP[i-1]+((double)(1.0)/i32W)*(vecP[i-1]-dTemp);
            }
            else
            {
                double dTemp=i-1-i32W>=0?vecP[i-1-i32W]:0;
                vecP[i]=vecP[i-1]-((double)(1.0)/i32W)*dTemp;
                /*for(int j=1;j<=i32W;j++)
                {
                    if(i-j>=0&&i-j<i32K)
                    {
                        vecP[i]+=(double)1.0/i32W*vecP[i-j];
                    }
                }*/
            }
            /*for(int j=1;j<=i32W;j++)
            {
                if(i-j>=0&&i-j<i32K)
                {
                    vecPP[i]+=(double)1.0/i32W*vecPP[i-j];
                }
            }
            cout<<i<<" "<<vecPP[i]<<" "<<vecP[i]<<endl;*/
        }
        for(int i=i32K;i<=i32K-1+i32W;i++)
        {
            dSum+= vecP[i];
        }
        for(int i=i32K;i<=min(i32N,i32K-1+i32W);i++)
        { 
            dRes+= vecP[i];
        }
        return dRes/dSum;
            
    }
};