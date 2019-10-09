#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void siftDown(vector<int> &arr, int startIndex, int endIndex) {
    // sifting down from root at start
    int root = startIndex;

    // 2*root + 1 is the index of the left child
    while(2*root + 1 <= endIndex) {
        int child = 2*root + 1;
        // checking right child exists and swapping if larger
        if (child + 1 <= endIndex && arr[child] < arr[child + 1]) {
            ++child;
        }

        if (arr[root] < arr[child]) {
            swap(arr[root], arr[child]);

            root = child;
        }
        else {
            return; // we are done because child must already have heap property maintained
        }
    }

}

void heapify(vector<int> &arr, int size) {
    int lastIndex = size - 1;

    // parent node of last one
    int start = (lastIndex - 1) / 2;

    while (start >= 0) {
        // will sift down until we get to largest left node
        // sift down all possible parents (leaves are trivial heap)
        siftDown(arr, start, lastIndex);
        --start;
    }
}

void heapSort(vector<int> &arr, int size) {
    heapify(arr, size);
    int lastIndex = size - 1;
    while (lastIndex > 0) {
        // highest value is at back
        swap(arr[0], arr[lastIndex]);
        // moving bounds since this is sorted
        --lastIndex;
        // restore heap property not including last value that we swapped
        siftDown(arr, 0, lastIndex);
    }
}

int main () {
    vector<int> unsortedArr = {-2, 3, 5, 0, 1, 0, -12, 10};
    heapSort(unsortedArr, unsortedArr.size());
    for_each(unsortedArr.begin(), unsortedArr.end(), [](auto val) {cout << val << ' ';});
    return 0;
}