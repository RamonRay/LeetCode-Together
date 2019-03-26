/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    { 
        vector<vector<int>> vec2dResult;
        if(!root)return vec2dResult;
        
        queue<vector<TreeNode*>> qTask;
        qTask.push(vector<TreeNode*>(1,root));
        while(!qTask.empty())
        {
            vector<TreeNode*> vecCurT=qTask.front();
            qTask.pop();
            vector<TreeNode*> vecWaitT;
            vector<int> vecCurR;
            for(auto i=vecCurT.begin();i!=vecCurT.end();i++)
            {
                vecCurR.push_back((*i)->val);
                //cout<<(*i)->val<<endl;
                if((*i)->left)
                {
                    vecWaitT.push_back((*i)->left);
                }
                if((*i)->right)
                {
                    vecWaitT.push_back((*i)->right);
                }
            }
            
            if(!vecWaitT.empty())qTask.push(vecWaitT);
            vec2dResult.push_back(vecCurR);
        }
        return vec2dResult;
    }
private:
    
};