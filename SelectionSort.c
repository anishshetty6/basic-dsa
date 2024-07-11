#include<stdio.h>

void printarray(int* a, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void selectionSort(int *a, int n){
    int indexOfMin, temp;
    printf("Running Selection sort...\n");
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            if(a[j] < a[indexOfMin]){
                indexOfMin = j;
            }
        }
        // Swap a[i] and a[indexOfMin]
        temp = a[i];
        a[i] = a[indexOfMin];
        a[indexOfMin] = temp;
    }
}

int main(){
    int a[] = {3, 5, 2, 13, 12};
    int n = 5;
    printarray(a, n);
    selectionSort(a, n);
    printarray(a, n);

    return 0;
}
