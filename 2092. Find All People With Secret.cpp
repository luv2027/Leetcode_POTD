class Solution
{
public:
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
  {
    vector<vector<pair<int, int>>> adj(n);

    for (auto x : meetings)
    {
      int f = x[0];
      int s = x[1];
      int t = x[2];

      adj[f].push_back({s, t});
      adj[s].push_back({f, t});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    pq.push({0, firstPerson});
    vector<bool> visited(n, false);

    while (!pq.empty())
    {
      auto x = pq.top();
      int time = x.first;
      int node = x.second;
      pq.pop();

      if (visited[node])
      {
        continue;
      }

      visited[node] = true;

      for (auto &[neighbour, time_neighbour] : adj[node])
      {
        if (!visited[neighbour] && time_neighbour >= time)
        {
          pq.push({time_neighbour, neighbour});
        }
      }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
      if (visited[i])
      {
        ans.push_back(i);
      }
    }

    return ans;
  }
};