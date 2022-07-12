#include"../inc/solution.hpp"


ListNode* Solution::swapPairs(ListNode* head)
{
    if(!head || !head->next){ return head; }  // handles empty list and single node

    ListNode* leader{head->next}, * follower{head};

    follower->next = leader->next;
    leader->next = follower;
    follower = leader;
    leader = leader->next;  // node pair have been swapped, follower and leader retain relative positions
    head = follower;

    while(leader->next)  // while at least one additional node exists
    {
        if(leader->next->next)  // check if additional node has a partner
        {
            ListNode* tmp{leader};  // placeholder used to connect swapped pairs

            // shift the pointers forward to the next node pair
            follower = leader->next;
            leader = follower->next;

            // swap the node pair
            follower->next = leader->next;
            leader->next = follower;
            follower = leader;
            leader = leader->next;

            // connect second node of the previous pair with first node of current pair
            tmp->next = follower;
        }
        else{ break; }
    }

    return head;
}