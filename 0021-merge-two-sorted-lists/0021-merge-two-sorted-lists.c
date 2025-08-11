struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy head to make it easier
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    // While both lists have nodes
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            tail->next = list1; // attach list1's node
            list1 = list1->next; // move forward in list1
        } else {
            tail->next = list2; // attach list2's node
            list2 = list2->next; // move forward in list2
        }
        tail = tail->next; // move tail forward
    }

    // Attach the rest of whichever list is not empty
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next; // first real node (skip dummy)
}
