class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> res, seen(n);
        for (auto& e: edges)
            seen[e[1]] = 1;
        for (int i = 0; i < n; ++i)
            if (seen[i] == 0)
                res.push_back(i);
        return res;
    }
};



/*
    A Graph problem 
    
  / 0: 0,1,4
  X 1: 1,4
  / 2: 2,1,4
  / 3: 3,1
    4: 4
    
    
    Approach: 
     Know the reached nodes
     Loop over all the nodes from 0 to n-1
        If the node is reachable form itself only, it will be included
     
     We only have to count the number of nodes with zero incoming edges.
*/