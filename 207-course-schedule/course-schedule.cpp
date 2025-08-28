class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& visited){
        if(visited[u] == 1) return false;
        if(visited[u] == 2) return true;
        
        visited[u] = 1;
        for(int v : adj[u]){
            if(!dfs(v, adj, visited)) return false;
        }
        visited[u] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            if(!dfs(i,adj,visited)){
                return false;
            }
        }
        return true;
    }
};