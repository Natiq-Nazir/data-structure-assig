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

void insertAtAnyP(int data,int pos){
    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
   struct Node* temp = head;
    newNode->data = data;
    
    if(pos == 1){
        newNode->next = head;
        head=newNode;
        return;
    }

for(int i= 1;i<pos-1 && temp !=NULL;i++){
    temp = temp->next;
}

if(temp == NULL){
    printf("position out of range \n");
}
else{
    newNode->next = temp->next;
    temp->next = newNode;
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

printf("enter data to insert at any position:\n");
    scanf("%d",&data);
    printf("enter the position:\n");
    scanf("%d",&pos);
insertAtAnyP(data,pos);
display();
return 0;

}