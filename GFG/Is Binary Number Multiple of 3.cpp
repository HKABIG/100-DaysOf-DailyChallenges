//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])throws IOException
        {
            BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
            PrintWriter out=new PrintWriter(System.out);
            int t = Integer.parseInt(in.readLine().trim());
            while(t-->0)
                {
                    String s = in.readLine().trim();
                    Solution ob = new Solution();
                    out.println(ob.isDivisible(s));
                }
                out.close();
        }
}    
// } Driver Code Ends


//User function Template for Java

class Solution {
    int isDivisible(String s) {
        int n = s.length();
        int sum = 0;
        int pow = 1;
        for(int i=n-1;i>=0;i--){
            sum = (sum%3+(s.charAt(i)-'0')%3*pow%3)%3;
            pow = (pow*2)%3;
        }
        if(sum%3==0) return 1;
        return 0;
    }
}

