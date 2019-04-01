class Solution 
{
private:
    struct stNode
    {
        int i32Val;
        int i32Idx;
        stNode(int idx, int val): i32Val(val), i32Idx(idx) {}
    };
public:
    int largestRectangleArea(vector<int>& vecHeights) 
    {
        vecHeights.push_back(0);
        vector<stNode> vecPriStack;
        int i32Res=0;
        
        for(int i=0;i<vecHeights.size();i++)
        {
            if(vecPriStack.empty())
            {
                vecPriStack.push_back(stNode(i, vecHeights[i]));
            }
            else
            {
                while(!vecPriStack.empty())
                {
                    stNode stTop=vecPriStack[vecPriStack.size()-1];
                    if(stTop.i32Val<=vecHeights[i])
                    {
                        vecPriStack.push_back(stNode(i, vecHeights[i]));
                        break;
                    }
                    else
                    {
                        vecPriStack.pop_back();
                        
                        if(vecPriStack.empty())
                        {
                            i32Res=max(i32Res, stTop.i32Val*(i));
                            vecPriStack.push_back(stNode(i, vecHeights[i]));
                            //cout<<stTop.i32Val*(i)<<endl;
                            break;
                        }
                        else
                        {
                            int preIdx=vecPriStack[vecPriStack.size()-1].i32Idx;
                            i32Res=max(i32Res, stTop.i32Val*(i-preIdx-1));
                            //cout<<stTop.i32Val*(i-preIdx-1)<<endl;
                        }
                    }
                }
            }
        }
        return i32Res;
    }

};