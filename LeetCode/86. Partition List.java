
class Solution {
    public ListNode partition(ListNode head, int x) {
        if(head==null) return head;

        ListNode smallerHead = new ListNode();
        ListNode smallerTail = smallerHead;

        ListNode greaterHead = new ListNode();
        ListNode greaterTail = greaterHead;

        ListNode curr = head;
        while(curr!=null){
            if(curr.val<x){
                smallerTail.next = curr;
                smallerTail = smallerTail.next;
            }
            else{
                greaterTail.next = curr;
                greaterTail = greaterTail.next;
            }
            curr = curr.next;
        }
        greaterTail.next = null;
        smallerTail.next = greaterHead.next;
        head = smallerHead.next;
        return head;        
    }
}