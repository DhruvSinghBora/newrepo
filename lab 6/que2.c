#include <stdio.h>

int main(){
    int n;
    printf("enter size of array");
    scanf("%d", &n);
    int arr[n];
    int arrval[n];
    for (int i=0;i<n;i++){
        printf("enter %d profit and weight", i);
        scanf("%d %d", &arr[i], &arrval[i]);
    }
    int ratio[n];
    for (int i=0;i<n;i++){
        ratio[i]= arr[i]/arrval[i];
    }
    
    return 0;
}