class Solution 
{
private:
    #define LARGE_PRIME (int(1e9+7))
    #define MAX_N (5001)
    int i32TransMat[10][10]={
        {2,4,6},
        {2,8,6},
        {2,7,9},
        {2,4,8},
        {3,3,9,0},
        {0,},
        {3,1,7,0},
        {2,2,6},
        {2,1,3},
        {2,2,4},};//i32TransMat[n][0]=number of obj
    int i32Mem[10][MAX_N];
    int getSum(int i32Start, int i32H)
    {
        if(i32H==1)return 1;
        if(i32Mem[i32Start][i32H]!=-1)return i32Mem[i32Start][i32H];
        
        int i32Sum=0;
        for(int i=1;i<=i32TransMat[i32Start][0];i++)
        {
            int i32ObjNum=i32TransMat[i32Start][i];
            i32Sum=(i32Sum+getSum(i32ObjNum, i32H-1))%LARGE_PRIME;           
        }
        i32Mem[i32Start][i32H]=i32Sum;
        return i32Mem[i32Start][i32H];
    }
public:
    int get1(int N) {
      const int mod = (int)1e9 + 7;
      std::vector<std::vector<int>> neighbours {
        {4,6}, {6,8}, {7,9}, {4,8}, {3,9,0},
        {}, {1,7,0}, {2,6}, {1,3}, {2,4}
      };
      // dp[i][n] is the number of distint numbers ending with digit i and 
      // having n hops remaining
      std::vector<std::vector<int>> dp(10, std::vector<int>(N));
      // base case
      for (int i = 0; i < 10; ++i) dp[i][0] = 1;
      for (int n = 1; n < N; ++n) {
        for (int i = 0; i < 10; ++i) {
          for (auto v: neighbours[i]) {
            dp[i][n] = (dp[i][n] + dp[v][n-1]) % mod;
          }
        }
      }
      int ans = 0;
      for (int i = 0; i < 10; ++i)
        ans = (ans + dp[i][N-1]) % mod;
      cout<<ans<<endl;
        for (int i = 0; i < 10; ++i)cout<<i<<":"<<dp[i][2]<<" "<<getSum(i, 3)<<endl;
        for (int i = 0; i < 10; ++i)cout<<i<<":"<<dp[i][3]<<" "<<getSum(i, 4)<<endl;
      return ans;
    }
    int knightDialer(int N) 
    {
        memset(i32Mem, -1, sizeof(i32Mem));
        //get1(N);
        int i32Sum=0;
        for(int i=0;i<=9;i++)
        {
           i32Sum=(i32Sum+getSum(i, N))%LARGE_PRIME; 
           //cout<<getSum(i, N)<<endl;
        }
        return i32Sum;
    }
};