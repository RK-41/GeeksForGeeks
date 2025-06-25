//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    // 25.06.25 POTD
	    unordered_map<char,int> fr;
	    unordered_map<int,int> frfr;
	    
	    for(auto c: s){
	        fr[c]++;
	    }
	    
	    for(auto f: fr){
	        frfr[f.second]++;
	    }
	    
	    if(frfr.size() > 2) 
	        return false;
	        
	    if(frfr.size() == 1)
	        return true;
	        
	    vector<int> v;
	    for(auto ff: frfr)
	        v.push_back(ff.first);

	    
	    if(frfr[1]==1)
	        return true;

	    if(v[0] > v[1] && frfr[v[0]] == 1 && v[0]-v[1] == 1)
	        return true;
	    
	    
	    return (frfr[v[1]]==1 && v[1]-v[0]==1);
	}
};
