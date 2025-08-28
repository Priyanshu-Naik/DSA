class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& visited,
             vector<int>& order) {
        if (visited[u] == 1)
            return false; // cycle detected
        if (visited[u] == 2)
            return true; // already processed

        visited[u] = 1; // mark as visiting (in recursion stack)

        for (int v : adj[u]) {
            if (!dfs(v, adj, visited, order))
                return false; // cycle found in neighbor
        }

        visited[u] = 2;     // mark as done
        order.push_back(u); // add course to order
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]); // edge: prereq -> course
        }

        vector<int> visited(numCourses,
                            0); // 0 = unvisited, 1 = visiting, 2 = done
        vector<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited, order))
                    return {}; // cycle → no valid order
            }
        }

        reverse(order.begin(), order.end()); // reverse postorder
        return order;
    }
};