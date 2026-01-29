class Solution {
  public:
    string firstNonRepeating(string &a) {
        // code here
        // 29.01.26 potd
        string ans;
	    vector<int> fr(26,0);
	    queue<char> q;
	    
	    for(int i=0; i<a.size(); i++){
	        fr[a[i]-'a']++;
	        
	        if(fr[a[i]-'a'] <= 1)
	            q.push(a[i]);
	            
	        int flg=0;
	        
	        while(!q.empty()){
	            char x = q.front();
	            
	            if(fr[x-'a'] == 1){
	                ans += x;
	                flg=1;
	                break;
	            }
	            else
	                q.pop();
	        }
	        
	        if(q.empty() && flg==0)
	            ans += '#';
	    }
	    
	    return ans;
	}
};