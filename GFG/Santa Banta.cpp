//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    vector<int> primes;
    void precompute(){
        int n = 1000000;
        vector<bool> isPrime(n+1,true);
        for(int i=2;i*i<=n;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(isPrime[i]){
                primes.push_back(i);
                //cout<<i<<" ";
            }
        }
    }
    int dfs(int ind,vector<bool>& vis,vector<vector<int>> &g){
        int count = 0;
        vis[ind] = true;
        for(auto it:g[ind]){
            if(!vis[it]){
                count += dfs(it,vis,g);
            }
        }
        return count + 1;
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        int ans = 0;
        for(int i=1;i<=n;i++){
            vector<bool> vis(n+1,false);
            ans = max(ans,dfs(i,vis,g));
        }
        return primes[ans-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends