
#include <stdio.h>
int main(){
    FILE *fp;
    int n,x;
    fp=fopen("seq.txt","w");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        fprintf(fp,"%d\n",x);
    }
    fclose(fp);
    fp=fopen("seq.txt","r");
    while(fscanf(fp,"%d",&x)!=EOF)
        printf("%d ",x);
    fclose(fp);
    return 0;
}
