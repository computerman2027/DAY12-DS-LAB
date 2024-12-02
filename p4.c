#include <stdio.h>
#define MAXSIZE 10

int heap[MAXSIZE + 1]; // +1 because heap is 1-based index
int N = 0;

// Swap two elements in the heap
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert an element into the heap
void insert(int val)
{
    N = N + 1;
    int pos = N, par;
    heap[N] = val;
    while (pos > 1)
    {
        par = pos / 2;
        if (heap[pos] <= heap[par])
        {
            return;
        }
        else
        {
            swap(&heap[pos], &heap[par]);
            pos = par;
        }
    }
}

// Delete the root of the heap (the max element)
void delete()
{
    int last = heap[N];
    N = N - 1;
    int ptr = 1, left = 2, right = 3;
    heap[ptr] = last;
    while (left <= N)
    {
        int larger = ptr;
        if (left <= N && heap[left] > heap[larger])
        {
            larger = left;
        }
        if (right <= N && heap[right] > heap[larger])
        {
            larger = right;
        }
        if (larger == ptr)
        {
            return;
        }
        swap(&heap[ptr], &heap[larger]);
        ptr = larger;
        left = 2 * ptr;
        right = left + 1;
    }
}

// Heapsort function: build the heap and sort the array
void heapsort(int arr[], int len)
{
	int i;
    // Build the heap
    for (i = 0; i < len; i++)
    {
        insert(arr[i]);
    }

    // Extract elements from the heap
    for ( i = len - 1; i >= 0; i--)
    {
        arr[i] = heap[1];  // The largest element (root) goes to the array
        delete();           // Remove the root from the heap
    }
}

int main()
{
    printf("ENTER NUMBER OF ELEMENTS\n");
    int n, i, val;
    scanf("%d", &n);

    // Insert values into the heap
    int arr[MAXSIZE];
    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &val);
        insert(val);
    }

    printf("DISPLAYING ELEMENTS OF HEAP\n");
    for (i = 1; i <= N; i++)
    {
        printf(i == N ? "%d\n" : "%d, ", heap[i]);
    }

    // Perform heapsort and display the sorted array
    heapsort(arr, n);

    printf("DISPLAYING SORTED ELEMENTS\n");
    for (i = 0; i < n; i++)
    {
        printf(i == n - 1 ? "%d\n" : "%d, ", arr[i]);
    }

    return 0;
}

