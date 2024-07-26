class Solution {
public:
    vector<vector<pair<int, int>>> g;
    int threshold;
    int sz;
    vector<int> num_city;

    void bfs(int src){
        vector<int> dis;
        vector<int> vis;

        dis.assign(sz, 1e9);
        vis.assign(sz, 0);

        priority_queue<pair<int, int>> pq;
        dis[src] = 0;
        pq.push({0, src});

        int c = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();

            if(vis[node] == 1) continue;
            c++;
            vis[node] = 1;

            for(auto neigh: g[node]){
                if(dis[neigh.first] > dis[node] + neigh.second && dis[node] + neigh.second <= threshold){
                    dis[neigh.first] = dis[node] + neigh.second;
                    pq.push({-dis[neigh.first], neigh.first});
                }
            }
        }
        
        num_city[src] = c-1;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        g.resize(n);
        sz = n;
        threshold = distanceThreshold;
        num_city.resize(n);
        int num_edge = edges.size();

        for(int i=0; i<num_edge; i++){
            int from = edges[i][0];
            int to = edges[i][1];
            int wt = edges[i][2];

            g[from].push_back({to, wt});
            g[to].push_back({from, wt});
        }

        for(int i=0; i<n; i++){
            bfs(i);
        }

        int min_neighbour = 1e9;
        int ans = -1;

        for(int i=0; i<n; i++){
            cout << num_city[i] << " ";
            if(num_city[i] <= min_neighbour){
                ans = i;
                min_neighbour = num_city[i];
            }
        }

        return ans;
    }
};