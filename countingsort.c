#include <stdio.h>
#include <stdlib.h>

void readFile(int arr[],int n, char *filename);
void countingSort(int arr[], int n);

int main()
{
    int n=10;
    int arr[n];
    readFile(arr,n,"input.txt");
    printf("array before sorting:\n");
    
    for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
    
       printf("\n");
    
    countingSort(arr,n);
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

void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}
