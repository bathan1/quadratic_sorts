#include <iostream>
#include <vector>
#include <string>

using std::vector;

template <typename T> void selection_sort(vector<T>& vec);
template <typename T> void insertion_sort(vector<T>& vec);
template <typename T> void bubble_sort(vector<T>& vec);
template <typename T> void print_arr(vector<T>& vec, void (*func)(vector<T>&), std::string sort_name, std::string arr_name);

int main() {
  vector<int> arr1 = {9, 3, 6, 2, 7, 1, 4, 8, 5};
  vector<int> arr2 = {14, 22, 7, 31, 2, 10, 18, 27, 5, 11};
  vector<int> arr3 = {41, 29, 38, 50, 15, 43, 8, 20, 3, 35};

  print_arr(arr1, selection_sort, "selection_sort", "arr1");
  print_arr(arr2, selection_sort, "selection_sort", "arr2");
  print_arr(arr3, selection_sort, "selection_sort", "arr3");

  std::cout << std::endl << "selection sort test done" << std::endl << std::endl;

  arr1 = {9, 3, 6, 2, 7, 1, 4, 8, 5};
  arr2 = {14, 22, 7, 31, 2, 10, 18, 27, 5, 11};
  arr3 = {41, 29, 38, 50, 15, 43, 8, 20, 3, 35};

  print_arr(arr1, insertion_sort, "insertion_sort", "arr1");
  print_arr(arr2, insertion_sort, "insertion_sort", "arr2");
  print_arr(arr3, insertion_sort, "insertion_sort", "arr3");

  std::cout << std::endl << "insertion sort test done" << std::endl << std::endl;

  arr1 = {9, 3, 6, 2, 7, 1, 4, 8, 5};
  arr2 = {14, 22, 7, 31, 2, 10, 18, 27, 5, 11};
  arr3 = {41, 29, 38, 50, 15, 43, 8, 20, 3, 35};

  print_arr(arr1, insertion_sort, "insertion_sort", "arr1");
  print_arr(arr2, insertion_sort, "insertion_sort", "arr2");
  print_arr(arr3, insertion_sort, "insertion_sort", "arr3");
  return 0;
}

template <typename T>
void print_arr(vector<T>& vec, void (*sort_func)(vector<T>&), std::string sort_name, std::string arr_name) {
  std::cout << arr_name << " before " << sort_name << ": { ";
  for (int i = 0; i < vec.size(); i++) {
    if (i < vec.size() - 1) {
      std::cout << vec[i] << ", ";
    } else {
      std::cout << vec[i] << " }" << std::endl;
    }
  }
  sort_func(vec);
  std::cout << arr_name << " after " << sort_name << ": { ";
  for (int i = 0; i < vec.size(); i++) {
    if (i < vec.size() - 1) {
      std::cout << vec[i] << ", ";
    } else {
      std::cout << vec[i] << " }" << std::endl;
    }
  }
}

template <typename T>
void selection_sort(vector<T>& vec) {
  for (int i = 0; i < vec.size(); i++) {
    int min = i;
    for (int j = i + 1; j < vec.size(); j++) {
      if (vec[j] < vec[min]) {
        min = j;
      }
    }
    if (min != i) {
      T temp = vec[i];
      vec[i] = vec[min];
      vec[min] = temp;
    }
  }
}

template <typename T>
void insertion_sort(vector<T>& vec) {
  for (int i = 1; i < vec.size(); i++) {
    int j = i;
    while (j > 0 && vec[j] < vec[j - 1]) {
      T temp = vec[j - 1];
      vec[j - 1] = vec[j];
      vec[j] = temp;
      j--;
    }
  }
}

template <typename T>
void bubble_sort(vector<T>& vec) {
  for (int i = vec.size() - 1; i > 0; i--) {
    bool swapped = false;
    for (int j = 0; j < i; j++) {
       if (vec[j] > vec[j + 1]) {
        T temp = vec[j];
        vec[j] = vec[j + 1];
        vec[j + 1] = temp;
        swapped = true;
       }
    }
    if (!swapped) {
      return;
    }
  }
}