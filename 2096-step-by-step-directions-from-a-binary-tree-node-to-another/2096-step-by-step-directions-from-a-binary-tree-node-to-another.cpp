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
    //--------------- Time: O(N)
private:
    bool findPath(TreeNode* root, string &ans, int &target)
    {
        if(!root)
            return false;
        if(root->val == target) 
            return true;
        
        if(findPath(root->left, ans, target)) {
            ans+="L";
            return true;
        }
        if(findPath(root->right, ans, target)) {
            ans+="R";
            return true;
        }
        
        return false;
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        string startStr = "";
        string destStr = "";
        
        findPath(root, startStr, startValue);
        findPath(root, destStr, destValue);
		
		// removing the common part
        while(startStr.size() > 0 && destStr.size() > 0 && (startStr.back() == destStr.back())) {
            startStr.pop_back();
            destStr.pop_back();
        }
        
		//replacing startStr with U
        for(int i=0; i<startStr.size(); i++) {
            startStr[i] = 'U';
        }
        
		//reversing the destStr
        reverse(destStr.begin(), destStr.end());
		
        return startStr+destStr;
    }
};

/*------------------------------------------------
Memory Limit Exceeded at test 287 / 332
--------------------------------------------------
class Solution {
public:
    
    // Make a hash map and map each value to its parent
    void mapToParent(unordered_map<TreeNode*, TreeNode*> &map, TreeNode* root, TreeNode* parent) {
        if(!root)
            return;
        
        map[root] = parent;
            
        mapToParent(map, root->left, root);
        mapToParent(map, root->right, root);
    }
    
    // Get the corresponding node to its value
    TreeNode* getNode(TreeNode* root, int value) {
        if(!root)
            return NULL;
        if(root->val == value)
            return root;
        
        TreeNode* leftNode = getNode(root->left, value);
        TreeNode* rightNode = getNode(root->right, value); 
        
        return leftNode ? leftNode : rightNode;    
    }
    
    // Do bfs to get the shortest path between the start and destination
   string bfs(unordered_map<TreeNode*, TreeNode*> &map, TreeNode* startNode, int destValue) {
        unordered_set<int> visited;
        queue<pair<TreeNode*, string>> q;
        q.push({startNode, ""});
        while(q.size()) 
        {
            int n = q.size();
            while(n--) 
            {
                pair<TreeNode*, string> curr = q.front();
                q.pop();
                TreeNode* node = curr.first;
                string directStr = curr.second;
                
                if(node->val == destValue)
                    return directStr;
                
                if(node->left && !visited.count(node->left->val)) {
                    q.push({node->left, directStr+"L"});
                    visited.insert(node->left->val);
                }
                if(node->right && !visited.count(node->right->val)) {
                    q.push({node->right, directStr+"R"});
                    visited.insert(node->right->val);
                }
                if(map[node]->val != -1 && !visited.count(map[node]->val)) {
                    q.push({map[node], directStr+"U"});
                    visited.insert(map[node]->val);
                }
            }
        }
       return "";
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        unordered_map<TreeNode*, TreeNode*> map;
        mapToParent(map, root, new TreeNode(-1));
        TreeNode* startNode = getNode(root, startValue);
        
        return bfs(map, startNode, destValue);
    }
};

------------------------------------------------*/