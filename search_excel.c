#include <stdio.h>
int main() 
{
    FILE *inputFile;
    int values[10];
    int searchValue, found = 0;
    inputFile = fopen("input.csv","r");
    if (inputFile == NULL) 
    {
        printf("Error opening file.\n");
        return 1;
    }
    printf("Enter the value to search: ");
    scanf("%d", &searchValue);
    for (int i=0;i<10;i++) 
    {
        fscanf(inputFile, "%d", &values[i]);
        if (values[i] == searchValue) 
        {
            found=1;
            break;
        }
    }
    if (found) 
        printf("Element is present.\n");
    
    else
        printf("Element is absent.\n");

    fclose(inputFile);
    return 0;
}