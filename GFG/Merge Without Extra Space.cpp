//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void Swap(long long arr1[], long long arr2[], int i, int j){
            arr1[i] += arr2[j];
            arr2[j] = arr1[i]-arr2[j];
            arr1[i] = arr1[i]-arr2[j];
        }
        void merge(long long arr1[], long long arr2[], int n, int m) { 
            // TC:O(N+M) SC:O(N+M);
            // priority_queue<int,vector<int>,greater<int>> pq;
            // for(int i=0;i<n;i++){
            //     pq.push(arr1[i]);
            // }
            // for(int i=0;i<m;i++){
            //     pq.push(arr2[i]);
            // }
            // for(int i=0;i<n;i++){
            //     arr1[i] = pq.top();
            //     pq.pop();
            // }
            // for(int i=0;i<m;i++){
            //     arr2[i] = pq.top();
            //     pq.pop();
            // }
            
            // TC:O((M+N)Log(M+N)) SC:O(1)
            int i = n-1;
            int j = 0;
            while(i>=0 && j<m){
                while(i>=0 && arr1[i]>arr2[j]){
                    // swap(arr1[i],arr2[j]);
                    Swap(arr1,arr2,i,j);
                    i--;
                }
                j++;
            }
            sort(arr1, arr1 + n);
            sort(arr2, arr2 + m);
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends