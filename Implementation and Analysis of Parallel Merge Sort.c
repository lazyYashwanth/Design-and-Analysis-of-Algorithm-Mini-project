/* ============================================================
 * Mini Project: Implementation and Analysis of Merge Sort
 * Algorithm   : Merge Sort using Divide and Conquer
 * Author      : [Student Name]
 * Date        : [DD-MM-YYYY]
 * Description : Program to sort an array using Merge Sort
 * ============================================================ */

/* -------- Include Header Files -------- */
#include <stdio.h>

/* -------- Function to Merge Two Subarrays -------- */
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;

    /* Calculate sizes of two subarrays */
    int n1 = mid - left + 1;
    int n2 = right - mid;

    /* Temporary arrays */
    int L[n1], R[n2];

    /* Copy data to temporary arrays */
    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    /* Initial indexes */
    i = 0;
    j = 0;
    k = left;

    /* Merge temporary arrays back into arr[] */
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
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

    /* Copy remaining elements of L[] */
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy remaining elements of R[] */
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* -------- Merge Sort Function -------- */
void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        /* Find middle index */
        int mid = left + (right - left) / 2;

        /* Sort first half */
        mergeSort(arr, left, mid);

        /* Sort second half */
        mergeSort(arr, mid + 1, right);

        /* Merge sorted halves */
        merge(arr, left, mid, right);
    }
}

/* -------- Function to Print Array -------- */
void printArray(int arr[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

/* -------- Main Function -------- */
int main()
{
    int n, i;

    /* Read number of elements */
    printf("Enter number of elements: ");
    scanf("%d", &n);

    /* Edge case: Empty array */
    if(n == 0)
    {
        printf("Array is empty.\n");
        return 0;
    }

    int arr[n];

    /* Read array elements */
    printf("Enter array elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* Display original array */
    printf("\nOriginal Array:\n");
    printArray(arr, n);

    /* Call Merge Sort */
    mergeSort(arr, 0, n - 1);

    /* Display sorted array */
    printf("\nSorted Array:\n");
    printArray(arr, n);

    return 0;
}

