// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        // 11.09.25 (potd)
	    int furthest = 0, end = 0, jmp = 0, n = arr.size();
	    
	    for(int i=0; i<n-1; i++) {
	        furthest = max(furthest, arr[i]+i);
	        
	        if(end==i){
	            jmp++;
	            if(end == furthest)
	                return -1;
	                
	           end = furthest;
	        }
	    }
	    return jmp;
    }
};

