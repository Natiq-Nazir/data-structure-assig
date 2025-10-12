#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head =NULL;

void create(int n){
    struct Node *newNode,*temp;
    int data;

    for(int i=0;i<n;i++){
        newNode = (struct Node*)malloc(sizeof(struct Node));
printf("Enter data for node %d: ",i+1);
scanf("%d",&data);
newNode->data = data;
newNode->next = NULL;

if(head == NULL){
    head = newNode;
}
else{
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}


    }
}

void insertAtBeg(int data){
    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void display(){
    struct Node*temp = head;
    printf("list: ");
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
       
    }
    printf("NULL\n");
}


int main(){
    int n, data;
    printf("enter the number of nodes:\n");
    scanf("%d",&n);
create(n);
display();

printf("enter data to insert at beginnng:\n");
    scanf("%d",&data);
insertAtBeg(data);
display();
return 0;

}