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
void deletionAtAnyP(int pos){
    if(head == NULL){
        printf("list is empty:");
    }
    else if(pos == 1){
struct Node* temp = head;
head = head->next;
free(temp);
    }
    else{
    struct Node* temp = head;
for(int i= 1;i<pos-1 && temp->next !=NULL;i++){
    temp = temp->next;
}
if(temp->next == NULL){
    printf("position out of range");
}
else{
    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}
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
    int n, data,pos;
    printf("enter the number of nodes:\n");
    scanf("%d",&n);
create(n);
display();

printf("enter the position:\n");
    scanf("%d",&pos);
deletionAtAnyP(pos);
display();
return 0;

}