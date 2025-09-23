class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        // 23.09.25 (POTD)
        stack<int> s;
        
        while(!q.empty()){
            s.push(q.front());
            q.pop();
        }
        
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
    }
};