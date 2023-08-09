//{ Driver Code Starts
//Initial Template for Java


import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int N = Integer.parseInt(read.readLine());
            Solution ob = new Solution();
            System.out.println(ob.largestPrimeFactor(N));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static long largestPrimeFactor(int N) {
        // prime factor of a number lies between it's square root and 1
        // using prime factorization of N
        // TC(O(N^2))
        int n = 2;
        while((n*n)<=N){
            if(N%n==0){
                N/=n;
            }
            else{
                n++;
            }
        }
        return N;
    }
}

