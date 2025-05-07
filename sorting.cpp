#include <iostream>
#include <vector>
#include <random>
using namespace std;

// Function to print the elements of a vector
void printVector(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Function to generate n random numbers between min and max
vector<int> generateRandomNumbers(int n, int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(min, max);

    vector<int> randomNumbers;
    for (int i = 0; i < n; i++)
    {
        randomNumbers.push_back(distribution(gen));
    }

    return randomNumbers;
}

// Function to perform Bubble Sort
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
        printVector(arr);
    }
}

// Function to perform Insertion Sort
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printVector(arr);
    }
}

// Function to perform Selection Sort
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
        printVector(arr);
    }
}

// Function to perform Merge Sort
void merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

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

    printVector(arr);
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Function to perform Heapify in Heap Sort
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
        printVector(arr);
    }
}

// Function to perform Heap Sort
void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapify(arr, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; --i)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        printVector(arr);
    }
}

// Function to partition in Quick Sort
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform Quick Sort
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
        printVector(arr);
    }
}

// Function to perform Shell Sort
void shellSort(vector<int> &arr)
{
    int n = arr.size();

    // Start with a large gap and reduce it
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; ++i)
        {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
        printVector(arr);
    }
}

// Function to get the maximum value in Radix Sort
int getMax(vector<int> &arr)
{
    int max = arr[0];
    for (int num : arr)
    {
        if (num > max)
        {
            max = num;
        }
    }
    return max;
}

// Function to perform counting sort for Radix Sort
void countSort(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    const int radix = 10;

    vector<int> count(radix, 0);

    for (int i = 0; i < n; ++i)
    {
        count[(arr[i] / exp) % radix]++;
    }

    for (int i = 1; i < radix; ++i)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i)
    {
        output[count[(arr[i] / exp) % radix] - 1] = arr[i];
        --count[(arr[i] / exp) % radix];
    }

    for (int i = 0; i < n; ++i)
    {
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort
void radixSort(vector<int> &arr)
{
    int max = getMax(arr);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, exp);
        printVector(arr);
    }
}

int main()
{
    cout << "                    ~~ELEMENT SORTER PROGRAM~~\n" << endl;
    char repeat;

    do
    {
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;

        vector<int> arr = generateRandomNumbers(n, 0, 99);
        cout << "Generated random numbers: ";
        printVector(arr);
        cout << endl
             << "Select a sorting algorithm: " << endl
             << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Merge Sort" << endl;
        cout << "5. Heap Sort" << endl;
        cout << "6. Quick Sort" << endl;
        cout << "7. Shell Sort" << endl;
        cout << "8. Radix Sort" << endl;
        cout << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bubbleSort(arr);
            break;
        case 2:
            insertionSort(arr);
            break;
        case 3:
            selectionSort(arr);
            break;
        case 4:
            mergeSort(arr, 0, n - 1);
            break;
        case 5:
            heapSort(arr);
            break;
        case 6:
            quickSort(arr, 0, n - 1);
            break;
        case 7:
            shellSort(arr);
            break;
        case 8:
            radixSort(arr);
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

        cout << endl<< "Sorted array: ";
        printVector(arr);
        cout << endl;

        cout << "Do you want to sort another array? (y/n): ";
        cin >> repeat;
        cout << endl;

    } while (repeat == 'y' || repeat == 'Y');

    cout << "Exiting program. Goodbye!" << endl;

    return 0;
}
