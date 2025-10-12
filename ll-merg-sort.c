#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *newNode, *temp;
    int data;
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

struct Node* mergeSorted(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;
    struct Node* result = NULL;
    if (a->data <= b->data) {
        result = a;
        result->next = mergeSorted(a->next, b);
    } else {
        result = b;
        result->next = mergeSorted(a, b->next);
    }
    return result;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n1, n2;
    struct Node *head1, *head2, *mergedHead;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);
    printf("Enter sorted elements of first list: ");
    head1 = createList(n1);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &n2);
    printf("Enter sorted elements of second list: ");
    head2 = createList(n2);

    mergedHead = mergeSorted(head1, head2);

    printf("Merged Sorted Linked List:\n");
    display(mergedHead);

    return 0;
}
