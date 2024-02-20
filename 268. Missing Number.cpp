class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);

    int n = nums.size();
    int sum_of_first_natural_number = n * (n + 1) / 2;

    int arr_sum = 0;
    for (auto x : nums)
    {
      arr_sum += x;
    }

    return sum_of_first_natural_number - arr_sum;
  }
};