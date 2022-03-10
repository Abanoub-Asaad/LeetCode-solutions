class Solution {
public:

    int ans = 0;
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>> &res, vector<int> &path, int cur) {
        path.push_back(cur);
        if(cur == graph.size()-1) 
            res.push_back(path);
        else {
            for(auto i : graph[cur]) 
            dfs(graph, res, path, i);
        }    
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> res;
        vector<int> path;
        dfs(graph, res, path, 0);
        return res;
    }
};


/*
    Make a graph using a hash map of vectors
     node -> vector
    
    DFS and Backtracking
    
    Make a function(graph, source)
    From source, when I reach a target , I will add the path into a vector
    to return after that
    
    0 -> 1 -> 3
    0 -> 2 -> 3

*/