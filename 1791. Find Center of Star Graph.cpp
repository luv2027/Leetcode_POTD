class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int num_edges = edges.size();
        int num_nodes = num_edges + 1;
        vector<int> degree(num_nodes+1, 0);

        for(int i=0; i<num_edges; i++){
            degree[edges[i][0]]++;a
            degree[edges[i][1]]++;
        }

        int maxi = 0;
        int node = -1;
        for(int i=1; i<=num_nodes; i++){
            if(degree[i] > maxi){
                maxi = degree[i];
                node = i;
            }
        }
        return node;
    }
};