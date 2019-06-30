#include "sorting.h"

namespace sorting {

    void swap(int *a, int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

    int partition(std::vector<int> &a, int left, int right) {
        int pivot = a[right];
        int i = left - 1;

        for (int j = left; j <= right - 1; j++) {
            if(a[j] <= pivot) {
                i++;
                swap(&a[i], &a[j]);
            }
        }

        swap(&a[i + 1], &a[right]);
        return i + 1;
    }

    void QuickSort(std::vector<int> &arr, int left, int right) {
        if(left < right) {
            int p = partition(arr, left, right);

            QuickSort(arr, left, p - 1);
            QuickSort(arr, p + 1, right);
        }
    }

    void Merge(std::vector<int> &a, std::vector<int> &b, int low, int middle, int high) {
        int i = 0, j = 0, k = 0;
        int n1 = middle - low + 1;
        int n2 = high - middle;

        std::vector<int> left, right;

        for(i = 0; i < n1; i++)
            left.push_back(a.at(low + i));

        for(j = 0; j < n2; j++)
            right.push_back(a.at(middle + 1 + j));

        i = 0;
        j = 0;
        k = low;

        while(i < n1 && j < n2) {
            if (left.at(i) <= right.at(j)) {
                a[k] = left.at(i);
                i++;
            } else {
                a[k] = right.at(j);
                j++;
            }

            k++;
        }

        while(i < n1) {
            a[k] = left.at(i);
            i++;
            k++;
        }

        while(j < n2) {
            a[k] = right.at(j);
            j++;
            k++;
        }
    }

    void MergeSort(std::vector<int> &a, std::vector<int> &b, int low, int high) {
        if (low < high) {
            int middle = (low + high) * 0.5;

            MergeSort(a, b, low, middle);
            MergeSort(a, b, middle + 1, high);

            Merge(a, b, low, middle, high);
        }
    }

    void heapify(std::vector<int> &a, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && a[left] > a[largest])
            largest = left;

        if(right < n && a[right] > a[largest])
            largest = right;

        if (largest != i) {
            swap(&a[i], &a[largest]);
            heapify(a, n, largest);
        }
    }

    void HeapSort(std::vector<int> &a, int n) {
        for(int i = n * 0.5 - 1; i >= 0; i--) {
            heapify(a, n, i);
        }

        for(int i = n - 1; i >= 0; i--) {
            swap(&a[0], &a[i]);

            heapify(a, i , 0);
        }
    }

    void ShellSort(std::vector<int> &a, int n) {
        int gap = n * 0.5 - 1;
        int tmp;
        int j = 0;

        while(gap > 0) {
            for(int i = gap; i < n; i++) {
                tmp = a[i];
                j = i;

                while (j >= gap && tmp < a[j - gap]){
                    a[j] = a[j - gap];
                    j = j - gap;
                }

                a[j] = tmp;
            }
            gap = gap * 0.5 - 1;
        }
    }

    void randomizeVector(std::vector<int> &array, int n) {
    array.resize(n);

    for(int & i : array)
      i=rand() % 1000000;
    }
}





