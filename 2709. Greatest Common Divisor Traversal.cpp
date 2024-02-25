class DisjointSet
{
public:
  vector<int> parent;
  vector<int> size;

  DisjointSet(int n)
  {
    parent.resize(n + 1);
    size.resize(n + 1);

    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int x)
  {
    if (parent[x] == x)
    {
      return x;
    }
    return parent[x] = find(parent[x]);
  }

  void combine(int x, int y)
  {
    int px = find(x);
    int py = find(y);

    if (px == py)
      return;
    if (size[px] > size[py])
    {
      parent[py] = px;
      size[px] += size[py];
    }
    else
    {
      parent[px] = py;
      size[py] += size[px];
    }
  }
};

class Solution
{
public:
  bool canTraverseAllPairs(vector<int> &nums)
  {
    int n = nums.size();
    if (n <= 1)
    {
      return true;
    }

    DisjointSet ds(n);

    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 1)
      {
        return false;
      }
      for (int j = 2; j * j <= nums[i]; j++)
      {
        if (nums[i] % j == 0)
        {
          mp[j].push_back(i);
          int k = nums[i] / j;
          if (k == j)
          {
            continue;
          }
          mp[k].push_back(i);
        }
      }
      mp[nums[i]].push_back(i);
    }

    for (auto m : mp)
    {
      int x = m.first;
      for (int i = 0; i < mp[x].size() - 1; i++)
      {
        ds.combine(ds.find(mp[x][i]), ds.find(mp[x][i + 1]));
      }
    }

    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if ((ds.find(i) == i))
      {
        count++;
      }
      if (count > 1)
      {
        return false;
      }
    }

    if (count == 1)
    {
      return true;
    }

    return false;
  }
};