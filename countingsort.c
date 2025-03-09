#include <stdio.h>
#include <stdlib.h>

void loadArrayFromFile(int a[], int n, char *filename);
void countingSort(int a[], int n);

int main() {
    int n = 10;
    int a[n];

    loadArrayFromFile(a, n, "input.txt");

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    countingSort(a, n);

    printf("After sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void loadArrayFromFile(int a[], int n, char *filename) {
    FILE *in = fopen(filename, "r");
    if (!in) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    printf("Reading numbers from file...\n");  // Debug message

    for (int i = 0; i < n; i++) {
        if (fscanf(in, "%d", &a[i]) != 1) {  // Handle possible read errors
            printf("Error: Failed to read number at index %d\n", i);
            fclose(in);
            exit(1);
        }
    }

    fclose(in);
}

void countingSort(int a[], int n)
{
    // Check if already sorted
    int alreadySorted = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            alreadySorted = 0;
            break;
        }
    }
    if (alreadySorted)
    {
        printf("Array is already sorted.\n");
        return;
    }

    // Find maximum value in the array
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }

    // Allocate memory for count array (calloc ensures zero initialization)
    int *cnt = calloc(max + 1, sizeof(int));
    if (!cnt)
    {  // Check if allocation failed
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    // Count occurrences of each number
    for (int i = 0; i < n; i++)
        cnt[a[i]]++;

    // Reconstruct sorted array
    int idx=0;
    for (int i=0;i<=max;i++)
    {
        while(cnt[i]==0)
            a[idx++]=i;
    }
    free(cnt);
}
