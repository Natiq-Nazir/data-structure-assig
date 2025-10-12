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
void deletionAtBeg(){
    if(head == NULL){
        printf("list is empty:");
    }
    else{
    struct Node* temp = head;
    head = head->next;
    free(temp);
    }
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


deletionAtBeg();
display();
return 0;

}