#include <stdio.h>
#include <stdlib.h>
void quick_sort(int left, int right, int *x);
void exchange (int i, int j, int *x);
void quick_sort(int left, int right, int *x){
     int i, j, m;
     i = left;
     j = right;
     m = x[(i+j+1)/2];
     do {
         while (x[i] < m) i++;
         while (x[j] > m) j--;
         if (i <= j) {
             exchange(i,j,x);
             i++;
             j--;
         }
     } while(i <= j);
     if (left < j) 
         quick_sort(left, j, x);
     if (i < right) 
         quick_sort(i, right, x);
}
void exchange (int i, int j, int *x){
     int tmp;
     tmp = x[i];
     x[i] = x[j];
     x[j] = tmp;
}
 
int main(void){
    int a[] = {13,85,5,44,6,8,14,65};
    for (unsigned int i = 0; i < 8; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n\n");
    quick_sort(0, 7, a);
    for (unsigned int i = 0; i < 8; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n\n");
    return 0;
}
