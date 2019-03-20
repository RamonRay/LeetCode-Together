class Solution {
private:
        map<int,int> mapSteps;
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        
        auto i=mapSteps.find(n);
        if(i!=mapSteps.end())return i->second;
        
        int i32Ans=climbStairs(n-1)+climbStairs(n-2);
        mapSteps[n]=i32Ans;
        return i32Ans;

    }
};