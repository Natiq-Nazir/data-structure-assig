#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head1 = NULL;
struct Node* head2 = NULL;

struct Node* create(int n) {
    struct Node *head = NULL, *newNode, *temp;
    int data;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
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

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2; 
    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;            
    temp->next = head2;               
    return head1;
}

int main() {
    int n1, n2;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);
    head1 = create(n1);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &n2);
    head2 = create(n2);

    printf("\nFirst Linked List: ");
    display(head1);

    printf("Second Linked List: ");
    display(head2);

    head1 = concatenate(head1, head2);  

    printf("\nLinked List after concatenation: ");
    display(head1);

    return 0;
}
