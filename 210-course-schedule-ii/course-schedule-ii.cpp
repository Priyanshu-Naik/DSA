class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& visited,
             vector<int>& order) {
        if (visited[u] == 1)
            return false; 
        if (visited[u] == 2)
            return true; 

        visited[u] = 1; 

        for (int v : adj[u]) {
            if (!dfs(v, adj, visited, order))
                return false; 
        }

        visited[u] = 2;    
        order.push_back(u); 
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]); 
        }

        vector<int> visited(numCourses,
                            0); 
        vector<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited, order))
                    return {}; 
            }
        }

        reverse(order.begin(), order.end()); // reverse postorder
        return order;
    }
};