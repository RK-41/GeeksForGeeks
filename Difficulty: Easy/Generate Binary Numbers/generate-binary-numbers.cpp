class Solution {
  public:
    vector<string> generateBinary(int N) {
        // code here
        // 25.09.25 (POTD)
        if(N==0)    return {"0"};
	
    	vector<string> ans;
    	queue<string> q;
    	q.push("1");
    	
    	while(N--){
    	    ans.push_back(q.front());
    	    q.push(q.front()+"0");
    	    q.push(q.front()+"1");
    	    q.pop();
    	}
    	
    	return ans;
    }
};