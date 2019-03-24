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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> vecRes;
        if(root)getPreorderTraversal(vecRes, root);
        return vecRes;
    }
private:
    void getPreorderTraversal(vector<int>& vecRes, TreeNode* root)
    {
        vecRes.push_back(root->val);
        if(root->left)
        {
            getPreorderTraversal(vecRes, root->left);
        }
        if(root->right)
        {
            getPreorderTraversal(vecRes, root->right);  
        }
    }
};