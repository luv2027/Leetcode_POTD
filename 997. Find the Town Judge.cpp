class Solution
{
public:
  int findJudge(int n, vector<vector<int>> &trust)
  {
    unordered_map<int, int> mp;

    if (n == 1)
    {
      return 1;
    }

    for (auto t : trust)
    {
      mp[t[1]]++;
      mp[t[0]]--;
    }

    for (auto [person, trustCount] : mp)
    {
      if (trustCount == n - 1)
      {
        return person;
      }
    }

    return -1;
  }
};
