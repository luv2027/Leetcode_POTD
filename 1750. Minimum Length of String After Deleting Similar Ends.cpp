class Solution
{
public:
  int minimumLength(string s)
  {
    int n = s.size();

    if (n == 1)
    {
      return 1;
    }

    int i = 0;
    int j = n - 1;

    while (i < j)
    {
      char l = s[i];
      char r = s[j];

      if (l != r)
      {
        break;
      }

      while (i < j && s[i] == l)
      {
        i++;
      }

      while (i <= j && s[j] == r)
      {
        j--;
      }
    }

    return j - i + 1;
  }
};