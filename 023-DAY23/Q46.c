/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    // Base case: if list is empty or has only one node without a cycle
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Move fast pointer by 2 and slow by 1
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Tortoise moves 1 step
        fast = fast->next->next;    // Hare moves 2 steps

        // If they meet, there is a cycle
        if (slow == fast) {
            return true;
        }
    }

    // If fast reaches the end, no cycle exists
    return false;
}
