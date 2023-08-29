//{ Driver Code Starts
import java.util.*;

class Node
{

    int data;
    Node next;

    Node(int d)
    {
        data = d;
        next = null;
    }
}


public class LinkedList
{
    
 

    /* Function to print linked list */
   public static void print(Node root)
    {
        Node temp = root;
        while(temp!=null)
        {
            System.out.print(temp.data + " ");
            temp=temp.next;
        }
    }


    /* Driver program to test above functions */
    public static void main(String args[])
    {

        /* Constructed Linked List is 1.2.3.4.5.6.
         7.8.8.9.null */
        int value;
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0 && sc.hasNextInt() )
        {
            int n = sc.nextInt();
            
            //int n=Integer.parseInt(br.readLine());
            int a1 = sc.nextInt();
            Node head = new Node(a1);
            Node tail = head;

            for (int i = 1; i < n && sc.hasNextInt() ; i++)
            {
                int a = sc.nextInt();
                tail.next = new Node(a);
                tail = tail.next;
            }


            Node result = new Solution().compute(head);
            print(result);
            System.out.println();
            t--;
        }
    }
}
// } Driver Code Ends


/*
class Node {
   int data;
   Node next;

  Node(int data) {
      this.data = data;
  }
}
*/
class Solution
{
    Node reverse(Node head){
        Node curr = head;
        Node prev = null;
        while(curr!=null){
            Node temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
        
    }
    Node compute(Node head){
        // Approach #1 TC(O(N)) SC(O(N))
        // ArrayList<Integer> al = new ArrayList<>();
        // Node temp = head;
        // while(temp!=null){
        //     al.add(temp.data);
        //     temp=temp.next;
        // }
        // int n = al.size();
        // ArrayList<Integer> ans = new ArrayList<>();
        // int mx = -1;
        // for(int i=n-1;i>=0;i--){
        //     if(al.get(i)>=mx){
        //         mx = al.get(i);
        //         ans.add(al.get(i));
        //     }
        // }
        // n = ans.size();
        // Node newHead = new Node(0);
        // Node newTemp = newHead;
        // for(int i=n-1;i>=0;i--){
        //     Node a = new Node(ans.get(i));
        //     newTemp.next = a;
        //     newTemp = newTemp.next;
        // }
        // return newHead.next;
        
        // Approach #2 TC(O(N)) SC(O(1))
        Node newHead = reverse(head);
        Node curr = newHead;
        Node prev = newHead;
        Node ans  = newHead;
        curr = curr.next;
        while(curr!=null){
            if(curr.data<prev.data){
                prev.next = curr.next;
                curr = prev.next;
            }else{
                prev = curr;
                curr = curr.next;
            }
        }
        return reverse(ans);
    }
}
  