# merge-sort-and-binary-search

## Merge Sort

Merge sort is a 'divide and conquer' algorithm, meaning that the sorting algorithm will divide itself into two halves and then calls itself on each of those two halves, then merges those two halves.

![Merge Sort Diagram](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e6/Merge_sort_algorithm_diagram.svg/300px-Merge_sort_algorithm_diagram.svg.png)

[Youtube: Merge Sort Briefly Explained](https://www.youtube.com/watch?v=4VqmGXwpLqc)

### Binary Search

A binary search is the most time efficient way to find the index of an item in a sorted array.
It works by finding the midpoint of a sorted list, and checking if the value at that index is less than the desired item. If so the whole left half of that array can be ignored. If the value is greater than the item, then the right half can be ignored. Finally if its equal you have found the exact index! Repeat this process of halving the search space until you either find the item or exhaust your options and determine the item doesnt exist in the sorted array.

![Binary Search Algorithm](https://upload.wikimedia.org/wikipedia/commons/thumb/8/83/Binary_Search_Depiction.svg/1920px-Binary_Search_Depiction.svg.png)

Here is an example main function:

```c++
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };

    int arr_len = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Given array is \n";
    printArray(arr, arr_len);

    mergeSort(arr, 0, arr_len - 1);

    std::cout << "\nSorted array is \n";
    printArray(arr, arr_len);

    std::cout << "Index of 11 in sorted array: ";
    std::cout << binarySearch(arr, 0, arr_len - 1, 11);

    std::cout << "\n\nIndex of 5 in sorted array: ";
    std::cout << binarySearch(arr, 0, arr_len - 1, 5);

    std::cout << "\n\nIndex of 100 in sorted array: ";
    std::cout << binarySearch(arr, 0, arr_len - 1, 100);
    std::cout << std::endl;

    return 0;
}
```

Output:

```txt
Given array is
12 11 13 5 6 7

Sorted array is
5 6 7 11 12 13
Index of 11 in sorted array: 3

Index of 5 in sorted array: 0

Index of 100 in sorted array: -1
```

## Compiling

](https://www.learncpp.com/cpp-tutorial/compiling-your-first-program/)

### Install

```console
$ sudo apt install g++
```

### Compile

```console
$ g++ -o assignment assignment.cpp
```

### Execute

```console
$ ./assignment
```