//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Merge(int arr[],int low,int mid,int high){
            int i,j,k;
            int n1 = mid - low + 1;
            int n2 = high - mid;
            int l[n1],r[n2];
            for(i=0;i<n1;i++){
                l[i] = arr[low+i];
            }
            for(j=0;j<n2;j++){
                r[j] = arr[mid+1+j];
            }
            i=0;j=0;k=low;
            while(i<n1 && l[i]<0){
                arr[k++] = l[i++];
            }
            while(j<n2 && r[j]<0){
                arr[k++] = r[j++];
            }
            while(i<n1){
                arr[k++] = l[i++];
            }
            while(j<n2){
                arr[k++] = r[j++];
            }
        }
        void MergeSort(int arr[],int low,int high){
            if(low>=high) return ;
            int mid = (low+high)/2;
            MergeSort(arr,low,mid);
            MergeSort(arr,mid+1,high);
            Merge(arr,low,mid,high);
        }
        void Rearrange(int arr[], int n){
            MergeSort(arr,0,n-1);
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends