#include<stdio.h>
int main(void){
    int n,max,index;
    max=0;
    for(int i=0;i<9;i++){
        scanf("%d\n",&n);
        if(max < n) {max = n; index=i+1;}
    }
    printf("%d\n%d",max, index);
}