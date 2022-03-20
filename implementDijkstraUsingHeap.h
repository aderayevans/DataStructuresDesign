#define INF 100000
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //make directed graph with indexes are u, values: v, w
        //** n+1 because we don't need 0 index. Therefore, we need extra
        vector< vector< pair<int,int>   >   > graph;
        graph.resize(n + 1);
        for(int i = 0; i < times.size(); i++)
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        
        //create distance vector
        vector<int> dist(n+1, INF);
        dist[k] = 0;
        
        //create heap (to get node have the least distance **using greater comparison)
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> heap;
        //pushing initial node
        heap.push({dist[k], k});
        
        //create discover check vector
        vector<bool> disc(n+1, false);
        
        while(!heap.empty())
        {
            int u = heap.top().second;
            heap.pop();
            disc[u] = true;
            
            for(auto edge : graph[u]){
                
                int v = edge.first;
                int weight = edge.second;
                
                if(disc[v] == false && dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    heap.push({dist[v], v});
                }
            }
        }
        
        //take max time to reach all node (defends on the problem)
        int ans = 0;
        for(int i = 1; i < dist.size(); i++)
        {
            ans = max(ans, dist[i]);
        }
        if(ans == INF) return -1;
        return ans;
    }
};
