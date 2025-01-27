#include<stdio.h>
int main(void){
    int n;
    int MIN,MAX;
    scanf("%d", &n);
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    MIN = arr[0];
    MAX = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] < MIN) MIN = arr[i];
        else if(MAX < arr[i]) MAX = arr[i];
    }
    printf("%d %d", MIN,MAX);
}