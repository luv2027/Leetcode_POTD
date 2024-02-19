class Solution
{
public:
  bool isPowerOfTwo(int n)
  {
    if (n == 0)
    {
      return false;
    }

    double val = log2(n);

    if (floor(val) == val)
    {
      return true;
    }

    return false;
  }
};