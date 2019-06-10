#ifndef _SORTING_H_
#define _SORTING_H_

#include <vector>
#include <iostream>
#include <string>

namespace sorting {
  void QuickSort(std::vector<int> &arr, int left, int right);
  void Merge(std::vector<int> &a, std::vector<int> &b,int low, int middle, int high);
  void MergeSort(std::vector<int> &a, std::vector<int> &b, int low, int high);
  void HeapSort(std::vector<int> &a, int n);
  void ShellSort(std::vector<int> &a, int n);
  void randomizeVector(std::vector<int> &array, int n);
 }
#endif 
