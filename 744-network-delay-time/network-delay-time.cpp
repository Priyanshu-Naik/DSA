class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<>>pq;
        pq.push({0, k});

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int node = it.second;

            if(time > dist[node]) continue;

            for(auto iter : adj[node]){
                int nei = iter.first;
                int edgW = iter.second;

                if(time + edgW < dist[nei]){
                    dist[nei] = time + edgW;
                    pq.push({dist[nei], nei});
                }
            }
        }

        int ans = *max_element(dist.begin()+1, dist.end());
        return ans == INT_MAX ? -1 : ans; 
    }
};