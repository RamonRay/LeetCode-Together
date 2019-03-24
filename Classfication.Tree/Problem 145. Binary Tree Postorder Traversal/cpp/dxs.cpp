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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> vecRes;
        if(root)getPostorderTraversal(vecRes, root);
        return vecRes;
    }
private:
    void getPostorderTraversal(vector<int>& vecRes, TreeNode* root)
    { 
        if(root->left)
        {
            getPostorderTraversal(vecRes, root->left);
        }
        if(root->right)
        {
            getPostorderTraversal(vecRes, root->right);  
        }
        vecRes.push_back(root->val);
    }
};

