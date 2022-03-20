// Using lambda to compare elements.
auto cmp = [](pair<int,int> &left, pair<int,int> &right) 
{
  if (left.second == right.second) return left.first < right.first;
  return left.second < right.second; 
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> heap(cmp);
