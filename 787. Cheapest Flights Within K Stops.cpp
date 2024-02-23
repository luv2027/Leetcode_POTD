class Solution
{
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
  {
    vector<vector<pair<int, int>>> adj(n);
    for (auto x : flights)
    {
      int from = x[0];
      int to = x[1];
      int wt = x[2];
      adj[from].push_back({to, wt});
    }

    vector<int> step_node(n, INT_MAX);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src, 0});

    while (!pq.empty())
    {
      auto info = pq.top();
      pq.pop();

      int dist = info[0];
      int node = info[1];
      int steps = info[2];

      if (steps > step_node[node] || steps > k + 1)
      {
        continue;
      }

      step_node[node] = steps;
      if (node == dst)
        return dist;

      for (auto &[neighbour, price] : adj[node])
      {
        pq.push({price + dist, neighbour, steps + 1});
      }
    }
    return -1;
  }
};