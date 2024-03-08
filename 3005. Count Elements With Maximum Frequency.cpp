class Solution
{
public:
  int maxFrequencyElements(vector<int> &nums)
  {
    unordered_map<int, int> mp;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      mp[nums[i]]++;
    }

    int maxi = INT_MIN;

    for (auto x : mp)
    {
      if (x.second > maxi)
      {
        maxi = x.second;
      }
    }

    int c = 0;
    for (auto x : mp)
    {
      if (x.second == maxi)
      {
        c += x.second;
      }
    }

    return c;
  }
};