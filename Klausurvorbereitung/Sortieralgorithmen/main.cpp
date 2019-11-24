#include <iostream>
#include <vector>
#include <cmath>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void merge(std::vector<int> &arr, int low, int middle, int high) {
    int n1 = middle - low + 1;
    int n2 = high - middle;

    std::vector<int> left, right;

    for(int i = 0; i < n1; i++)
        left.push_back(arr.at(low + i));
    for(int i = 0; i < n2; i++)
        right.push_back(arr.at(middle + 1 + i));

    int k = low;
    int i = 0;
    int j = 0;

    while(i < n1 && j < n2) {
        if(left.at(i) <= right.at(j)) {
            arr[k] = left.at(i);
            i++;
        } else {
            arr[k] = right.at(j);
            j++;
        }

        k++;
    }

    while(i < n1) {
        arr[k] = left.at(i);
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = right.at(j);
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &arr, int l, int r) {
    if(l < r) {
        int m = l + (r -l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int partition(std::vector<int> &arr, int low, int high) {
    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(std::vector<int> &arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void heapify(std::vector<int> &arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && arr[l] > arr[largest])
        largest = l;

    if(r < n && arr[r] > arr[largest])
        largest = r;

    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(std::vector<int> &arr, int n) {
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void insertionsort(std::vector<int> &arr, int n) {
    int key, j;

    for(int i = 0; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void selectionsort(std::vector<int> &arr, int n) {
    int minIdx;

    for(int i = 0; i < n - 1; i++) {
        minIdx = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIdx])
                minIdx = j;

            swap(&arr[minIdx], &arr[i]);
        }
    }
}

void bubblesort(std::vector<int> &arr, int n) {
    for(int i = 0; i < n; i++) {
        bool swapped = false;

        for(int j = 0; j < n - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

void shellsort(std::vector<int> &arr, int n) {
    for(int gap = n / 2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            int tmp = arr[i];

            int j;
            for(j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = tmp;
        }
    }
}

int checkMinHeap(std::vector<int> &heap) {
    int height = log2(heap.size());
//    for (int i = heap.size() - 1; i > 0; i--) {
//        if(i % 2 == 0) { //left child
//            if(heap[i] <= heap[i - (2 * height + 1)])
//                return i;
//        } else if(i % 2 != 0){ //right child
//            if(heap[i] <= heap[i - (2 * height)])
//                return i;
//        }
//
//        if(i == heap.size() - pow(height, 2))
//            height--;
//    }

    int j = 0;
    int k = 0;
    for (int i = heap.size() - 1; i > 0; i--) {
        if (height % 2 == 0)
            k = -1;
        else
            k = 1;

        if(i % 2 == 0) { //right child
            if (heap[i] <= heap[i / 2 - 1])
                return i;
        } else { // left child
            if (heap[i] <= heap[i / 2])
                return i;
        }

        if(i == height * 2 + k)
            height--;
    }

    return -1;
}

void buildMinHeap(std::vector<int> &heap) {
    int height = log2(heap.size());
    int k = 1;

    while (-1 != checkMinHeap(heap)) {
        for (int i = heap.size() - 1; i > 0; i--) {
            if (height % 2 == 0)
                k = -1;
            else
                k = 1;

            if(i % 2 == 0) { //right child
                if (heap[i] <= heap[i / 2 - 1])
                    swap(&heap[i], &heap[i / 2 - 1]);
            } else { // left child
                if (heap[i] <= heap[i / 2])
                    swap(&heap[i], &heap[i / 2]);
            }

            if(i == height * 2 + k)
                height--;
        }
    }


    for (int i = 0; i < heap.size(); i++) {
        std::cout << heap[i] << ", ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {5, 7, 2, 8, 6, 3, 4, 1, 9, 0};
    std::vector<int> arr2 = {1, 2, 3, 4, 5, 6};

    std::cout << checkMinHeap(arr) << std::endl;
    std::cout << checkMinHeap(arr2) << std::endl;

    buildMinHeap(arr);

    //mergeSort(arr, 0, arr.size() - 1);
    //quicksort(arr, 0, arr.size() - 1);
    //heapsort(arr, arr.size());
    //insertionsort(arr, arr.size());
    //selectionsort(arr, arr.size());
    bubblesort(arr, arr.size());
    //shellsort(arr, arr.size());

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;

    std::cout << checkMinHeap(arr) << std::endl;

    return 0;
}

//DONE: Merge Sort
//DONE: Quick Sort
//DONE: Heap Sort
//DONE: Insertion Sort
//DONE: Selection Sort
//DONE: Bubble Sort
//DONE: Shell Sort