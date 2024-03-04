class Solution
{
public:
  int bagOfTokensScore(vector<int> &tokens, int power)
  {
    sort(tokens.begin(), tokens.end());
    int n = tokens.size();
    int l = 0;
    int r = n - 1;

    int s = 0;
    while (l < r)
    {
      if (tokens[l] <= power)
      {
        power -= tokens[l];
        l++;
        s++;
      }
      else
      {
        if (s > 0)
        {
          power += tokens[r];
          r--;
          s--;
        }
        else
        {
          break;
        }
      }

      if (power < 0)
      {
        break;
      }
    }

    if (l == r)
    {
      if (tokens[l] <= power)
      {
        s++;
      }
    }

    return s;
  }
};