#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <iostream>
#include <omp.h>
#include <chrono>

#include "sorting.h"
#include "hashtable.h"

//benchmark functions
void benchmark_quicksort();
void benchmark_heapsort();
void benchmark_shellsort();
void benchmark_mergesort();


int main(int argc, char** argv) {

  Catch::Session().run();
  std::cin.get();

  benchmark_quicksort();
  benchmark_heapsort();
  benchmark_mergesort();
  benchmark_shellsort();
}

//executes benchmark for quicksort
void benchmark_quicksort() {
  //file stream
  std::ofstream quicksort_measurement;
  quicksort_measurement.open("/home/Studium/ADS/ADS/Praktika/Praktikum4/files/quicksort.txt", std::ios::out | std::ios::in | std::ios::app);

  //benchmark parameters / variables
  double dtime;
  int n_start = 1000;
  int n_step = 1000;
  int n_end = 1000000;

  std::vector<int> V;

  //actual benchmark loop
  for (int n = n_start; n<=n_end; n += n_step) {
    //"progress bar"
    std::cout << "Running Quicksort with n: " << n << std::endl;

    //generate n random integers
    sorting::randomizeVector(V, n);

    //start measurement
    //dtime = omp_get_wtime();
    auto start = std::chrono::steady_clock::now();

    //execzute sorting algorithm
    sorting::QuickSort(V,0,V.size()-1);

    //stop time
    //dtime = omp_get_wtime() - dtime;
    auto end = std::chrono::steady_clock::now();

    //write to file
    quicksort_measurement << n << "\t" << std::setprecision(10) << std::scientific << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
  }

  //close file handle
  quicksort_measurement.close();
}

void benchmark_mergesort() {
    //file stream
    std::ofstream mergesort_measurement;
    mergesort_measurement.open("/home/Studium/ADS/ADS/Praktika/Praktikum4/files/mergesort.txt", std::ios::out | std::ios::in | std::ios::app);

    //benchmark parameters / variables
    double dtime;
    int n_start = 1000;
    int n_step = 1000;
    int n_end = 1000000;

    std::vector<int> V;

    //actual benchmark loop
    for (int n = n_start; n<=n_end; n += n_step) {
        //"progress bar"
        std::cout << "Running Quicksort with n: " << n << std::endl;

        //generate n random integers
        sorting::randomizeVector(V, n);

        //start measurement
        //dtime = omp_get_wtime();
        auto start = std::chrono::steady_clock::now();

        //execzute sorting algorithm
        sorting::QuickSort(V,0,V.size()-1);

        //stop time
        //dtime = omp_get_wtime() - dtime;
        auto end = std::chrono::steady_clock::now();

        //write to file
        mergesort_measurement << n << "\t" << std::setprecision(10) << std::scientific << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
    }

    //close file handle
    mergesort_measurement.close();
}

void benchmark_heapsort() {
    //file stream
    std::ofstream heapsort_measurement;
    heapsort_measurement.open("/home/Studium/ADS/ADS/Praktika/Praktikum4/files/heapsort.txt", std::ios::out | std::ios::in | std::ios::app);

    //benchmark parameters / variables
    double dtime;
    int n_start = 1000;
    int n_step = 1000;
    int n_end = 1000000;

    std::vector<int> V;

    //actual benchmark loop
    for (int n = n_start; n<=n_end; n += n_step) {
        //"progress bar"
        std::cout << "Running Quicksort with n: " << n << std::endl;

        //generate n random integers
        sorting::randomizeVector(V, n);

        //start measurement
        //dtime = omp_get_wtime();
        auto start = std::chrono::steady_clock::now();

        //execzute sorting algorithm
        sorting::QuickSort(V,0,V.size()-1);

        //stop time
        //dtime = omp_get_wtime() - dtime;
        auto end = std::chrono::steady_clock::now();

        //write to file
        heapsort_measurement << n << "\t" << std::setprecision(10) << std::scientific << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
    }

    //close file handle
    heapsort_measurement.close();
}

void benchmark_shellsort() {
    //file stream
    std::ofstream shellsort_measurement;
    shellsort_measurement.open("/home/Studium/ADS/ADS/Praktika/Praktikum4/files/shellsort.txt", std::ios::out | std::ios::in | std::ios::app);

    //benchmark parameters / variables
    double dtime;
    int n_start = 1000;
    int n_step = 1000;
    int n_end = 1000000;

    std::vector<int> V;

    //actual benchmark loop
    for (int n = n_start; n<=n_end; n += n_step) {
        //"progress bar"
        std::cout << "Running Quicksort with n: " << n << std::endl;

        //generate n random integers
        sorting::randomizeVector(V, n);

        //start measurement
        //dtime = omp_get_wtime();
        auto start = std::chrono::steady_clock::now();

        //execzute sorting algorithm
        sorting::QuickSort(V,0,V.size()-1);

        //stop time
        //dtime = omp_get_wtime() - dtime;
        auto end = std::chrono::steady_clock::now();

        //write to file
        shellsort_measurement << n << "\t" << std::setprecision(10) << std::scientific << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
    }

    //close file handle
    shellsort_measurement.close();
}
