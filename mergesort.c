#include <stdio.h>
#include <stdlib.h>

void readFile(int arr[], int n, char *filename);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main()
{
    int n = 10;
    int arr[n];
    readFile(arr, n, "input.txt");
    printf("array before sorting:\n");
    
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    
    mergeSort(arr, 0, n - 1);
    printf("array after sorting:\n");
    
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    return 0;
}

void readFile(int arr[], int n, char *filename)
{
    FILE *input;
    input = fopen(filename, "r");
    if (input == NULL) 
    {
        printf("File couldn't be found\n");
        exit(1);
    }
    else
    {
        for (int i = 0; i < n; i++)
            fscanf(input, "%d", &arr[i]);

        fclose(input);
    }
}

void mergeSort(int arr[], int l, int r) 
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r) 
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}