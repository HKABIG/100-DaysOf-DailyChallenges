//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) { 
        // Brute Force T(C):O(NLOGN+N) S(C):O(N);
        //sort(arr,arr+n);
        // bool f = false;
        // vector<int> nums(n+1,0);
        // for(int i=0;i<n;i++){
        //     //if(arr[i]>n) break;
        //     if(arr[i]>0 && arr[i]<=n){
        //         nums[arr[i]]=1;
        //         f = true;
        //     }
        // }
        // if(!f) return 1;
        // int i = 1;
        // while(i<=n){
        //     if(nums[i]==0) return i;
        //     i++;
        // }
        // return n+1;
        
        // Brute Force Optimized TC:O(N) SC:O(N)
        // bool f = false;
        // vector<int> nums(n+1,0);
        // for(int i=0;i<n;i++){
        //     //if(arr[i]>n) break;
        //     if(arr[i]>0 && arr[i]<=n){
        //         nums[arr[i]]=1;
        //         f = true;
        //     }
        // }
        // if(!f) return 1;
        // int i = 1;
        // while(i<=n){
        //     if(nums[i]==0) return i;
        //     i++;
        // }
        // return n+1;
        
        // Optimal Approach TC:O(N) SC:(1)
        for(int i=0;i<n;i++){
            int CI = arr[i] - 1;
            while(arr[i]>0 && arr[i]<n && arr[i]!=arr[CI]){
                swap(arr[i],arr[CI]);
                CI = arr[i] - 1;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
        
        
    } 
};


//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends