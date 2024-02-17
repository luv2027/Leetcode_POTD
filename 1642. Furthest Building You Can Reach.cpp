class Solution
{
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders)
  {
    priority_queue<int, vector<int>, greater<int>> minh;
    int n = heights.size();

    for (int i = 0; i < n - 1; i++)
    {
      int jump_diff = heights[i + 1] - heights[i];

      if (jump_diff > 0)
      {
        minh.push(jump_diff);
        if (minh.size() > ladders)
        {
          bricks -= minh.top();
          minh.pop();
        }
        if (bricks < 0)
        {
          return i;
        }
      }
    }

    return n - 1;
  }
};