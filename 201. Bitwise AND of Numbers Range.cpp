class Solution
{
public:
  int rangeBitwiseAnd(int left, int right)
  {
    if (left == 0 || right == 0)
    {
      return 0;
    }

    int num_of_bits_left = (int)floor(log2(left)) + 1;
    int num_of_bits_right = (int)floor(log2(right)) + 1;

    if (num_of_bits_left != num_of_bits_right)
    {
      return 0;

      long long ans = left & right;
      for (long long i = (long long)left + 1; i < right; i++)
      {
        ans = ans & i;
      }

      return ans;
    }
  };