
#include <stdio.h>
int main(){
    FILE *fp;
    int x;
    fp=fopen("direct.dat","w+");
    for(int i=1;i<=5;i++)
        fwrite(&i,sizeof(int),1,fp);
    fseek(fp,2*sizeof(int),SEEK_SET);
    fread(&x,sizeof(int),1,fp);
    printf("%d",x);
    fclose(fp);
    return 0;
}
