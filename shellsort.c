#include <stdio.h>
#include <stdlib.h>

void readFile(int arr[],int n, char *filename);
void shellSort(int arr[], int n);

int main()
{
    int n=10;
    int arr[n];
    readFile(arr,n,"input.txt");
    printf("array before sorting:\n");
    
    for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
    
       printf("\n");
    
    shellSort(arr,n);
    printf("array after sorting:\n");
    
    for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
    
       printf("\n");
    return 0;
}

void readFile(int arr[],int n,char *filename)
{
    FILE *input;
    input=fopen(filename, "r");
    if (input == NULL) 
    {
        printf("File couldn't be found\n");
        exit(1);
    }
    else
    {
        for(int i=0;i<n;i++)
            fscanf(input, "%d", &arr[i]);

        fclose(input);
    }
}

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}