class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int len = edges.size();

        vector<vector<int>> mp(n);
        for(int i=0; i<len; i++){
            int s = edges[i][0];
            int d = edges[i][1];

            mp[s].push_back(d);
            mp[d].push_back(s);
        }

        queue<int> q;
        q.push(source);
        vector<bool> visited(n+1, false);

        visited[source] = true;

        while(!q.empty()){
            int current_node =  q.front();
            q.pop();
            vector<int> neighbors = mp[current_node];

            for(int i=0; i<neighbors.size(); i++){
                int node = neighbors[i];
                if(visited[node] == false){
                    q.push(node);
                    visited[node] = true;
                }
            }
        }

        return visited[destination];
    }
};