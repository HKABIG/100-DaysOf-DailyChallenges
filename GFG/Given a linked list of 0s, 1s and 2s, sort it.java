//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

class Driverclass
{
    public static void main (String[] args) throws IOException
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t = Integer.parseInt(in.readLine().trim());
        
        while(t-- > 0)
        {
            int n =Integer.parseInt(in.readLine().trim());
            String s[] = in.readLine().trim().split(" ");
            Node head = new Node(Integer.parseInt(s[0]));
            Node tail = head;
            for (int i = 1; i < n; i++) {
                tail.next = new Node(Integer.parseInt(s[i]));
                tail = tail.next;
            }

            head = new Solution().segregate(head);
            printList(head, out);
            out.println();
        }
        out.close();
    }
    
    public static void printList(Node head,PrintWriter out)
    {
        if(head == null)
           return;
           
        Node temp = head;
        while(temp != null)
        {
            out.print(temp.data + " ");
            temp = temp.next;
        }
    }
    
    
}




// } Driver Code Ends


//User function Template for Java

/*
class Node
{
    int data;
    Node next;
    Node(int data)
    {
        this.data = data;
        next = null;
    }
}
*/
class Solution{
    //Function to sort a linked list of 0s, 1s and 2s.
    static Node segregate(Node head){
        Node temp = head;
        int [] freq = new int[3];
        int len = 0;
        while(temp!=null){
            freq[temp.data]++;
            len++;
            temp = temp.next;
        }
        Node nHead = new Node(0);
        Node node = nHead;
        for(int i=0;i<len;i++){
            if(freq[0]>0){
                Node t = new Node(0);
                node.next = t;
                node = t;
                freq[0]--;
            }
            else if(freq[1]>0){
                Node t = new Node(1);
                node.next = t;
                node = t;
                freq[1]--;
            }
            else if(freq[2]>0){
                Node t = new Node(2);
                node.next = t;
                node = t;
                freq[2]--;
            }
        }
        return nHead.next;
    }
}


