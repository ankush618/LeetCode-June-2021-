class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        long long int ret = 0;
      vector<vector<int> > v;//2d vector
      for (int i = 0; i < n; i++) {
         v.push_back({ e[i], s[i] });//insert at end 
      }
        
      sort(v.rbegin(), v.rend());//the array v in reverse order
      priority_queue<int, vector<int>, greater<int> > pq;
        //one priority queue pq
      long long int sum = 0;
      for (int i = 0; i < n; i++) {
         if (pq.size() == k) {
            sum -= pq.top();
            pq.pop();
         }
         sum += v[i][1];
         pq.push(v[i][1]);
         ret = max(ret, sum * v[i][0]);
      }
      return ret % (long long int)(1e9 + 7);
        
    }
};
//code by shreyashi
