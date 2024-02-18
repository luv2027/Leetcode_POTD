typedef long long ll;

class Solution
{
public:
  int mostBooked(int n, vector<vector<int>> &meetings)
  {
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);

    map<int, int> booked;

    auto compare = [](const pair<ll, int> &a, const pair<ll, int> &b)
    {
      if (a.first == b.first)
      {
        return a.second > b.second;
      }
      return a.first > b.first;
    };

    priority_queue<int, vector<int>, greater<int>> freeRooms;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, decltype(compare)> minh;
    for (int i = 0; i < n; i++)
    {
      freeRooms.push(i);
    }

    sort(meetings.begin(), meetings.end());

    for (auto &meeting : meetings)
    {
      ll start = meeting[0];
      ll end = meeting[1];

      while (!minh.empty() && minh.top().first <= start)
      {
        freeRooms.push(minh.top().second);
        minh.pop();
      }

      if (!freeRooms.empty())
      {
        booked[freeRooms.top()]++;
        minh.push({end, freeRooms.top()});
        freeRooms.pop();
      }
      else
      {
        booked[minh.top().second]++;
        auto p = minh.top();
        minh.pop();
        minh.push({p.first + (end - start), p.second});
      }
    }

    int meeting_room = 0;
    int meeting_freq = 0;

    for (auto book : booked)
    {
      if (book.second > meeting_freq)
      {
        meeting_room = book.first;
        meeting_freq = book.second;
      }
    }

    return meeting_room;
  }
};