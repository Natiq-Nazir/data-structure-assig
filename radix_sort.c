
#include <stdio.h>
int getMax(int a[],int n){
    int max=a[0];
    for(int i=1;i<n;i++) if(a[i]>max) max=a[i];
    return max;
}
void countSort(int a[],int n,int exp){
    int output[10],count[10]={0};
    for(int i=0;i<n;i++) count[(a[i]/exp)%10]++;
    for(int i=1;i<10;i++) count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--){
        output[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++) a[i]=output[i];
}
int main(){
    int a[10],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int max=getMax(a,n);
    for(int exp=1;max/exp>0;exp*=10)
        countSort(a,n,exp);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
