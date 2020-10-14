/*
 Problem Name: Path Sum 2
 Author: YokaiEmporer
 problem link: https://leetcode.com/problems/path-sum-ii/
 */

class Solution {
public:
    
    //create a global answer array to store node-leaf path that sum to target
    vector<vector<int>> ans;
    //Approach: apply dfs to find every possible path that would sum to target
    void dfs(TreeNode* root, vector<int> arr,int sum,int target)
    {
        if(!root)
            return;
        sum+=root->val;
        arr.push_back(root->val);
        //if leaf is reached check sum
        if(sum==target&&root->left==NULL&&root->right==NULL){
        ans.push_back(arr);
            return;
        }
        dfs(root->left,arr,sum,target);
        dfs(root->right,arr,sum,target);
        arr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> arr;
        dfs(root,arr,0,sum);
        return ans;
    }
};
