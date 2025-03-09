#include<stdio.h>
#include<stdlib.h>

void readFile(int arr[],int n, char *filename);
void quicksort(int arr[],int low,int high);
int partition(int arr[], int low, int high);

int main()
{
    int n=10,arr[n];
    readFile(arr,n,"input.txt");
    printf("array before sorting:\n");
    
    for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
    
       printf("\n");
    quicksort(arr,0,n-1);
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

void quicksort(int arr[],int low, int high)
{
    if(low<high)
    {
        int a=partition(arr,low,high);
        quicksort(arr,low,a-1);
        quicksort(arr,a+1,high);
    }
}

int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}
