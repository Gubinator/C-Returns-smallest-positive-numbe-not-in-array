/* Program that returns smallest positive number that is not in array (numbers in array are used interval). If the smallest 
number is <=0 (smaller or equal to zero), then it returns 1. */

// https://github.com/Gubinator

#include <stdio.h>
#include <limits.h>

int retgap(int A[], int n){
    int min, min2nd,max, store;
    min=INT_MAX;
    min2nd=INT_MAX;
    max=INT_MIN;
    int *pmin=&min;
    int *pmin2nd=&min2nd;
    
    for(int x=0; x<n;x++){
        if(min>A[x]){
            min=A[x];
        }
        if(max<A[x]){
            max=A[x];
        }
        for(int y=0; y<n;y++){
            if(A[y]>min && A[y]<min2nd){
                min2nd=A[y];
            }
        }
    }    
    printf("Minimum is %d, 2nd min is %d, maximum is %d\n", min, min2nd, max);
    for(int i=0; i<n;i++){
        if(min>A[i]){
            min=A[i];
            for(int j=0; j<n;j++){
                if(A[j]>min && A[j]<(*pmin2nd)){
                    min2nd=A[j];}
             }
        }
          printf("Minimum is %d, 2nd min is %d \n", min, min2nd);
          
        for(int j=0; j<n; j++){
            if(A[j]==(min+1) || (min==max && j==(n-1))){
                    *pmin=INT_MAX;
                    *pmin2nd=INT_MAX;
                    break;
                }
            if((min+1)>min && min2nd>(min+1)){
                    store=min+1; 
                }
            if((n-1)==j){
                if(min==max){
                    store=max+1;
                }
                if(store<1){
                    return 1;
                }
                return store;
            }
            }
        }
      
    }

int main()
{

    int A[]={4,4,5,5,2,5,-3,6,8,2}; // E.g. 1
    int B[]={3,1,5,3,3,4,12,6,8,2}; // E.g. 2
    int C[]={1,2,3,4,6,7,8,9,10,11}; // E.g. 3
    printf("[[Solution for example 1 is: %d]] \n", retgap(A,10));
    printf("[[Solution for example 2 is: %d]] \n", retgap(B,10));
    printf("[[Solution for example 2 is: %d]] \n", retgap(C,10));

    return 0;
}
