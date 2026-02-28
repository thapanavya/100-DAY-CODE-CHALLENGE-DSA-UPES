#include <stdbool.h>

// Function to reverse linked list
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *next = NULL;

    while(head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {

    if(head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head, *fast = head;

    // Find middle
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    slow = reverse(slow);

    // Compare halves
    struct ListNode* temp = head;

    while(slow) {
        if(temp->val != slow->val)
            return false;

        temp = temp->next;
        slow = slow->next;
    }

    return true;
}
