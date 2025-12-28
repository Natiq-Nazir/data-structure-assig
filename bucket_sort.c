
#include <stdio.h>
int main(){
    int a[10],bucket[10]={0},n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        bucket[a[i]]++;
    }
    for(int i=0;i<10;i++)
        while(bucket[i]--)
            printf("%d ",i);
    return 0;
}
