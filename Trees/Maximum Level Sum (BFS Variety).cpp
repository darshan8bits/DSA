class Solution {
public:
    int bfs(TreeNode* root){
        queue<TreeNode*> q;
        int maxm = root->val;
        q.push(root);

        while(!q.empty()){
            int levelSum = 0;
            vector<TreeNode*> nodes;
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                nodes.push_back(node);    
            }
            for(int i = 0; i < nodes.size(); i++){
                levelSum += nodes[i]->val;
                if(nodes[i]->right) q.push(nodes[i]->right);
                if(nodes[i]->left) q.push(nodes[i]->left);
            }
            
            maxm = max(levelSum, maxm);
        }

        return maxm;
    }

    int maxLevelSum(TreeNode* root) {
        int maxm = bfs(root);
        int counter = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            counter++;
            int levelSum = 0;
            vector<TreeNode*> nodes;
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                nodes.push_back(node);    
            }
            for(int i = 0; i < nodes.size(); i++){
                levelSum += nodes[i]->val;
                if(nodes[i]->right) q.push(nodes[i]->right);
                if(nodes[i]->left) q.push(nodes[i]->left);
            }

            if(levelSum == maxm) return counter;
        }

        return -1; 

    }
};