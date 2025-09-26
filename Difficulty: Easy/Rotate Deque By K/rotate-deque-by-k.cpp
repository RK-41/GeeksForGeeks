class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // 26.09.25 potd
         if(type == 1){
            int count = 0;
            while(count<k){
                int a = dq.back();
                dq.pop_back();
                dq.push_front(a);
                count++;
            }
         }
         else{
            int count = 0;
            while(count<k){
                int a = dq.front();
                dq.pop_front();
                dq.push_back(a);
                count++;
            }
         }
    }
};

