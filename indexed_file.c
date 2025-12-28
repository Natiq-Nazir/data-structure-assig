
#include <stdio.h>
int main(){
    int index[5]={101,102,103,104,105};
    int data[5]={10,20,30,40,50};
    int key;
    scanf("%d",&key);
    for(int i=0;i<5;i++){
        if(index[i]==key){
            printf("Data = %d",data[i]);
            return 0;
        }
    }
    printf("Record not found");
    return 0;
}
