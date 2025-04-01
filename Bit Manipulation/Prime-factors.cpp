Prob Link : "https://www.geeksforgeeks.org/problems/prime-factors5052/1"

Hint : - jis method se school me karte the , usi method se karo.

































CODE:
class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	    vector<int>ans;

    for(int i=2;i<=sqrt(N);i++){
        if(N%i==0){
            ans.push_back(i);
            while(N%i==0)N=N/i;}
    }
    
    if(N!=1){ans.push_back(N);return ans;}
    
    return ans;
	}
};
