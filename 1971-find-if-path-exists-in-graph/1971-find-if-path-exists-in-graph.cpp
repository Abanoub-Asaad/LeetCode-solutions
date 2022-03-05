class Solution {
public:
    
    unordered_map<int, vector<int>> graph;
    
    bool bfs(int n, int cur, int destination) {
        
        vector<bool> visited(n,0);
        visited[cur] = 1;
        queue<int> q;
        q.push(cur);

        while(q.size()) 
        {
            int current = q.front();
            if(current == destination) return true;
            q.pop();
            for(auto &node : graph[current])
            {
                if(!visited[node]) {
                    visited[node] = 1;
                    q.push(node);
                }
            }
        }

        return false;  
    }
    
    bool dfs(int n, int cur, int destination) {
        
        vector<bool> visited(n,0);
        visited[cur] = 1;
        stack<int> st;
        st.push(cur);

        while(st.size()) 
        {
            int current = st.top();
            if(current == destination) return true;
            st.pop();
            for(auto &node : graph[current])
            {
                if(!visited[node]) {
                    visited[node] = 1;
                    st.push(node);
                }
            }
        }

        return false;  
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        return bfs(n, source, destination);
    }
};