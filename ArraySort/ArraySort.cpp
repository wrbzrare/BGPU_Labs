#include <iostream>
#include <chrono>
#include <cstdlib>
#include "SelectionSort.h"
#include "BubbleSort.h"

using namespace std;
using namespace std::chrono;

void fillRandom(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand()%1000;
    }
}

void copyArray(int source[], int new_arr[], int size) {
    for (int i = 0; i < size; i++) {
        new_arr[i] = source[i];
    }
}

int main() {
	system("chcp 1251");
	system("cls");
	
    int smallSize = 3000;
    int largeSize = 50000;
    
    int smallArray[smallSize];
    int largeArray[largeSize];
    
    fillRandom(smallArray, smallSize);
    fillRandom(largeArray, largeSize);
    
    int smallCopy[smallSize];
    int largeCopy[largeSize];
    
    copyArray(smallArray, smallCopy, smallSize);
    auto start = high_resolution_clock::now();
    selectionSort(smallCopy, smallSize);
    auto stop = high_resolution_clock::now();
    duration<double, milli> duration = stop - start;
    cout << "Сортировка выбором (маленький массив): " << duration.count() << " мс" << endl;
    
    copyArray(smallArray, smallCopy, smallSize);
    start = high_resolution_clock::now();
    bubbleSort(smallCopy, smallSize);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << "Пузырьковая сортировка (маленький массив): " << duration.count() << " мс" << endl;
    
    copyArray(largeArray, largeCopy, largeSize);
    start = high_resolution_clock::now();
    selectionSort(largeCopy, largeSize);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << "Сортировка выбором (большой массив): " << duration.count() << " мс" << endl;
    
    copyArray(largeArray, largeCopy, largeSize);
    start = high_resolution_clock::now();
    bubbleSort(largeCopy, largeSize);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << "Пузырьковая сортировка (большой массив): " << duration.count() << " мс" << endl;
    
    return 0;
}
