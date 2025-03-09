#include <stdio.h>
#include <stdlib.h>

void readFile(int arr[],int n, char *filename);
void radixSort(int arr[], int n);
int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);

int main()
{
    int n=10;
    int arr[n];
    readFile(arr,n,"input.txt");
    printf("array before sorting:\n");
    
    for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
    
       printf("\n");
    
    radixSort(arr,n);
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

void radixSort(int arr[], int n) 
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int getMax(int arr[], int n) 
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp) 
{
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) 
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
