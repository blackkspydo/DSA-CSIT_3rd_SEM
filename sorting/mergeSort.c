#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int arr[], int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

// Test the Merge Sort algorithm
int main()
{
    int totalNumbers;
    printf("Enter the total number of elements: ");
    scanf("%d", &totalNumbers);
    int arr[totalNumbers];

    for (int i = 0; i < totalNumbers; i++)
        arr[i] = rand() % 100;

    printf("Original array: \n");
    for (int i = 0; i < totalNumbers; i++)
        printf("%d ", arr[i]);

    mergeSort(arr, 0, totalNumbers - 1);

    printf("\nSorted array: \n");
    for (int i = 0; i < totalNumbers; i++)
        printf("%d ", arr[i]);

    return 0;
}
