

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void heapify(int arr[], int N, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    if (l < N && arr[l] > arr[largest])
        largest = l;

    
    if (r < N && arr[r] > arr[largest])
        largest = r;


    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{
    int count = 0;

    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    
    for (int i = N - 1; i > 0; i--)
    {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
        count++;

    }
    printf(" no of steps - %d\n", count);
}


void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


int main()
{
    int arr[100];
    srand(time(0));
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 100;
    }
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    heapSort(arr, N);

    cout << "Sorted array is \n";
    printArray(arr, N);
}
