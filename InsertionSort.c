#include<stdio.h>

void printArray(int *a,int n){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void insertionSort(int *a,int n){
	int key,j;
	for(int i=1;i<n;i++){
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
			}
		a[j+1]=key;
	}
}

int main(){
	int a[]={5,2,6,11,79,4,9};
	int n=7;
	printArray(a,n);
	insertionSort(a,n);
	printArray(a,n);
	return 0;
}
 
 int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Original array: ");
    printArray(a, n);

    insertionSort(a, n);

    printf("Sorted array: ");
    printArray(a, n);

    return 0;
}