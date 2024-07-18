/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>solve(TreeNode*root, int dist, int & cnt)
    {
        if(!root)
            return {0};
        if(!root->left && !root->right)
            return {1};
        
        vector<int>left = solve(root->left, dist, cnt);
        vector<int>right = solve(root->right, dist, cnt);
        
        for(auto i : left)
        {
            for(auto j : right)
            {
                if(i>0 && j>0)
                    if(i+j<=dist)
                    {
                        cnt++;
                    }
            }
        }
        
        vector<int>ans;
        for(auto it : left)
        {
            if(it>0 && it<dist)
            {
                ans.push_back(it+1);
            }
        }
        
        for(auto it : right)
        {
            if(it>0 && it<dist)
            {
                ans.push_back(it+1);
            }
        }
        
        return ans;
        
    }
    int countPairs(TreeNode* root, int distance) {
        int cnt = 0;
        solve(root,distance,cnt);
        return cnt;
    }
};