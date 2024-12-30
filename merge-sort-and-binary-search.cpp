// Assignment: C++ Assignment 3 - Merge Sort and Binary Search
// Author: Michael Cox 
// Date: November 8, 2023

#include <iostream>

// function to merge left and right sub-arrays
void merge(int array[], int const left, int const middle, int const right)
{
    // initialize starting indexes for left, right, and merged sub-arrays
    int leftSubArrayIndx{ 0 };  // starting index of leftArray[]
    int rightSubArrayIndx{ 0 }; // starting index of rightArray[]
    int mergedSubArrayIndx{ left }; // starting index of merged array

    // establish left and right lengths 
    auto const lengthLeft = middle - left + 1;
    auto const lengthRight = right - middle;

    // next create two temporary arrays (leftArray, rightArray) to store left and right sub arrays
    auto *leftArray = new int [lengthLeft];
    int *rightArray = new int [lengthRight];

    // use for statements to copy data to temporary leftArray[] and rightArray[]
    for (int x = 0; x < lengthLeft; x++)
    {
        leftArray[x] = array[left + x];
    }

    for (int x = 0; x < lengthRight; x++)
    {
        rightArray[x] = array[middle + 1 + x];
    }

    // merge two sub-arrays into temp
    while (leftSubArrayIndx < lengthLeft && rightSubArrayIndx < lengthRight)
    {
        if (leftArray[leftSubArrayIndx] <= rightArray[rightSubArrayIndx])
        {
            array[mergedSubArrayIndx] = leftArray[leftSubArrayIndx];
            leftSubArrayIndx++;
        }

        else
        {
            array[mergedSubArrayIndx] = rightArray[rightSubArrayIndx];
            rightSubArrayIndx++;
        }
        mergedSubArrayIndx++;
    }

    // copy any leftArray[] remaining elements
    while (leftSubArrayIndx < lengthLeft)
    {
        array[mergedSubArrayIndx] = leftArray[leftSubArrayIndx];
        mergedSubArrayIndx++;
        leftSubArrayIndx++;
    }

    // copy any rightArray remaining elements 
    while (rightSubArrayIndx < lengthRight)
    {
        array[mergedSubArrayIndx] = rightArray[rightSubArrayIndx];
        mergedSubArrayIndx++;
        rightSubArrayIndx++;
    }
    return;
}

// recursive function to merge the two parts
void mergeSort(int array[], int const left, int const right)
{
    int middle;
    if (left < right)
    {
        middle = (left + right) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
    return;
}

// function for iterative binary search 
int binarySearch(int arr[], int left, int right, int item)
{
    while (left <= right) {
        int mid = left + (right - left) / 2;
 
        // Check if item is present at mid
        if (arr[mid] == item)
            return mid;
 
        // If item greater, ignore left half
        if (arr[mid] < item)
            left = mid + 1;
 
        // If item is smaller, ignore right half
        else
            right = mid - 1;
    }
 
    // If we reach this point, then the element was not present
    return -1;
}

// function to print array 
void printArray(int array[], int length)
{
    for (auto i = 0; i < length; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };

    // print given array of given size
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Given array is \n";
    printArray(arr, arr_len);

    // use mergeSort function to sort the sub-arrays
    mergeSort(arr, 0, arr_len - 1);

    // print sorted array 
    std::cout << "\nSorted array is \n";
    printArray(arr, arr_len);

    // print the indices of given item in given array 
    std::cout << "Index of 11 in sorted array: ";
    std::cout << binarySearch(arr, 0, arr_len - 1, 11);

    std::cout << "\n\nIndex of 5 in sorted array: ";
    std::cout << binarySearch(arr, 0, arr_len - 1, 5);

    std::cout << "\n\nIndex of 100 in sorted array: ";
    std::cout << binarySearch(arr, 0, arr_len - 1, 100);
    std::cout << std::endl;

    return 0;
}
