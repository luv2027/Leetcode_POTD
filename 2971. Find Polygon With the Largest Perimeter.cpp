class Solution
{
public:
  long long largestPerimeter(vector<int> &nums)
  {
    int n = nums.size();
    vector<long long> pre(n, 0);
    sort(nums.begin(), nums.end());

    pre[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
      pre[i] = pre[i - 1] + nums[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
      long long num = pre[i] - nums[i];
      if (num > nums[i])
      {
        return pre[i];
      }
    }

    return -1;
  }
};