
#include <stdio.h>
#include <stdlib.h>
struct node{int data; struct node* next;};
struct node* table[10];
void insert(int key){
    int index=key%10;
    struct node* newNode=malloc(sizeof(struct node));
    newNode->data=key;
    newNode->next=table[index];
    table[index]=newNode;
}
void display(){
    for(int i=0;i<10;i++){
        printf("%d:",i);
        struct node* temp=table[i];
        while(temp){ printf(" %d",temp->data); temp=temp->next; }
        printf("\n");
    }
}
int main(){
    int n,key;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&key);
        insert(key);
    }
    display();
    return 0;
}
