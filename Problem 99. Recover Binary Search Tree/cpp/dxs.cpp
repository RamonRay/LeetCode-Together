/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> vecResult;
        vector<int> vecRecord;
        
        getRec(root, vecRecord);
        sort(vecRecord.begin(), vecRecord.end());
        
        int i32It=0;
        findPs(vecResult, root, vecRecord, i32It);
        int temp=vecResult[0]->val;
        vecResult[0]->val=vecResult[1]->val;
        vecResult[1]->val=temp;
        return;
    }
private:
    void getRec(TreeNode* pstRoot, vector<int>& vecRecord)
    {
        if(!pstRoot)return;
        if(pstRoot->left)getRec(pstRoot->left, vecRecord);
        if(pstRoot->right)getRec(pstRoot->right, vecRecord);
        vecRecord.push_back(pstRoot->val);
    }
    void findPs(vector<TreeNode*>& vecResult, TreeNode* pstRoot, vector<int>& vecRecord, int& i32It)
    {
        if(!pstRoot)return;
        if(pstRoot->left)findPs(vecResult, pstRoot->left, vecRecord, i32It);
        if(vecRecord[i32It]!=pstRoot->val)vecResult.push_back(pstRoot);   
        i32It++;
        if(pstRoot->right)findPs(vecResult, pstRoot->right, vecRecord, i32It);
    }
};