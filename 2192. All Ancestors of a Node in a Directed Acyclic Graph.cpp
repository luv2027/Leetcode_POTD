class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> g(n);
        vector<int> indegree(n, 0);

        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            g[u].push_back(v);
            indegree[v]++;
        }

        vector<vector<int>> parents(n);
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto v: g[node]){
                indegree[v]--;

                    set<int> s;
                    vector<int> par = parents[v]; // abhi tak k khud k ancestors
                    vector<int> parents_ancestor = parents[node]; // ancestors k ancestors
                    for(auto x: par){
                        s.insert(x);
                    }

                    for(auto x: parents_ancestor){
                        s.insert(x);
                    }

                    s.insert(node); // parent khud

                    vector<int> p;
                    for(auto x: s){
                        p.push_back(x);
                    }

                    parents[v] = p;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        return parents;
    }
};