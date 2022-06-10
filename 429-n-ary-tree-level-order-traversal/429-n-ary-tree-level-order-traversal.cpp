/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    vector<vector<int>> levelOrder(Node* root) {
        //bfs
        vector<vector<int>> ans;
        queue<Node*> q;
        if(root)
            q.push(root);
        while(q.size()) {
            int n = q.size();
            vector<int> oneRow;
            while(n--) {
                auto cur = q.front();
                q.pop();
                oneRow.push_back(cur->val);
                for(auto node : cur->children) {
                    q.push(node);
                }
            }
            ans.push_back(oneRow);
        }
        
        return ans;
    }
};