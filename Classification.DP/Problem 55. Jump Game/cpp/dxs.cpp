class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>& vecNums=nums;
        int i32RemainStep=1;
        for(int i=0;i<vecNums.size()-1;i++)
        {
            i32RemainStep--;
            if(vecNums[i]<=0&&i32RemainStep<=0)return false;
            i32RemainStep=i32RemainStep>vecNums[i]?i32RemainStep:vecNums[i];
        }
        return true;
        
    }
};