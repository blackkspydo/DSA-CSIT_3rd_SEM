#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

void selectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}
void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

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

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int totalNumbers;
    printf("Enter the total number of elements: ");
    scanf("%d", &totalNumbers);
    int choice = 0;
    while (choice != 8)
    {

        printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Quick Sort\n5. Merge Sort\n6. Shell Sort\n7. Heap Sort\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int bubbleArray[totalNumbers];
        int selectionArray[totalNumbers];
        int insertionArray[totalNumbers];
        int quickArray[totalNumbers];
        int mergeArray[totalNumbers];
        int shellArray[totalNumbers];
        int heapArray[totalNumbers];

        switch (choice)
        {
        case 1:
            for (int i = 0; i < totalNumbers; i++)
                bubbleArray[i] = rand() % 100;
            printf("\nOriginal array: \n");
            printArray(bubbleArray, totalNumbers);
            bubbleSort(bubbleArray, totalNumbers);
            printf("\nSorted array: \n");
            printArray(bubbleArray, totalNumbers);
            break;
        case 2:
            for (int i = 0; i < totalNumbers; i++)
                selectionArray[i] = rand() % 100;
            printf("\nOriginal array: \n");
            printArray(selectionArray, totalNumbers);
            selectionSort(selectionArray, totalNumbers);
            printf("\nSorted array: \n");
            printArray(selectionArray, totalNumbers);
            break;
        case 3:
            for (int i = 0; i < totalNumbers; i++)
                insertionArray[i] = rand() % 100;
            printf("\nOriginal array: \n");
            printArray(insertionArray, totalNumbers);
            insertionSort(insertionArray, totalNumbers);
            printf("\nSorted array: \n");
            printArray(insertionArray, totalNumbers);
            break;
        case 4:
            for (int i = 0; i < totalNumbers; i++)
                quickArray[i] = rand() % 100;
            printf("\nOriginal array: \n");
            printArray(quickArray, totalNumbers);
            quickSort(quickArray, 0, totalNumbers - 1);
            printf("\nSorted array: \n");
            printArray(quickArray, totalNumbers);
            break;
        case 5:
            for (int i = 0; i < totalNumbers; i++)
                mergeArray[i] = rand() % 100;
            mergeSort(mergeArray, 0, totalNumbers - 1);
            break;
        case 6:
            for (int i = 0; i < totalNumbers; i++)
                shellArray[i] = rand() % 100;
            printf("\nOriginal array: \n");
            printArray(shellArray, totalNumbers);
            shellSort(shellArray, totalNumbers);
            printf("\nSorted array: \n");
            printArray(shellArray, totalNumbers);
            break;
        case 7:
            for (int i = 0; i < totalNumbers; i++)
                heapArray[i] = rand() % 100;
            printf("\nOriginal array: \n");
            printArray(heapArray, totalNumbers);
            heapSort(heapArray, totalNumbers);
            printf("\nSorted array: \n");
            printArray(heapArray, totalNumbers);
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}