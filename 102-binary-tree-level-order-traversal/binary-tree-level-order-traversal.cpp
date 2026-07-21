class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        int currLevel = -1;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while (!q.empty()) {
            pair<int, TreeNode*> temp = q.front();
            q.pop();
            if (temp.second->left)
                q.push({temp.first + 1, temp.second->left});
            if (temp.second->right)
                q.push({temp.first + 1, temp.second->right});
            if (currLevel != temp.first) {
                ans.push_back({});
                currLevel = temp.first;
            }

            ans[temp.first].push_back(temp.second->val);
        }

        return ans;
    }
};