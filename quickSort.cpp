/*
 * quickSort.cpp
 * quick sort
 *
 *  Created on: Dec 24, 2016
 *      Author: agreen16
 */

#include "quickSort.h"
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

// constructor
QuickSort::QuickSort(){ 
	sortArray.length = 0;
	sortArray.arr = NULL;
}

QuickSort::~QuickSort(){
	delete [] sortArray.arr;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void QuickSort::readList(){
	int currentCapacity = 10;
	sortArray.arr = new std::string[currentCapacity];

	while (std::getline(cin, sortArray.arr[sortArray.length])) {
		++sortArray.length;
		if (sortArray.length==currentCapacity) {
			std::string *temp = new std::string[currentCapacity*2];
			for (int i=0;i<currentCapacity;i++) {
				temp[i] = sortArray.arr[i];
			}
			delete [] sortArray.arr;
			sortArray.arr = temp;
			currentCapacity *= 2;
		}
	}
}

void QuickSort::sort(){
	// sorts using quickSort
	quick(0, sortArray.length-1);
}

void QuickSort::quick(int start, int end){
	int diff = end - start + 1;

	//if range is too small to partition
	if (diff <= 1) return;

	//picks random pivot
	srand (time(NULL));
	int index = rand() % diff + start;

	//partitions the range on either side of the pivot and returns its rank
	int rank = partition(index, start, end);

	//recurses on either side of the pivot
	quick(start, rank-1);
	quick(rank+1, end);
}

int QuickSort::partition(int index, int start, int end){
	std::string pivot = sortArray.arr[index];

	//finds rank of the pivot
	int rank = findRank(pivot, start, end);

	//swaps the pivot into its correct position
	sortArray.arr[index] = sortArray.arr[rank];
	sortArray.arr[rank] = pivot;

	//passes through range, swapping elements to their correct side of the pivot if not already
	int back = end;
	for (int front = start; front < rank; front++){
		//element on the left side that needs to move to the right
		if (sortArray.arr[front] >= pivot){
			//finds next element on the right side that can be swapped to the left
			while (back > rank){
				if (sortArray.arr[back] < pivot){
					std::string temp = sortArray.arr[front];
					sortArray.arr[front] = sortArray.arr[back];
					sortArray.arr[back] = temp;
					back--;
					break;
				}
				back--;
			}
		}
	}

	return rank;
}

int QuickSort::findRank(std::string pivot, int start, int end) {
	int rank = start;
	for (int i = start; i <= end; i++){
		if (sortArray.arr[i] < pivot){
			rank++;
		}
	}
	return rank;
}

void QuickSort::printArray(){
	// prints out the integers in sorted order
	for (int i = 0; i < sortArray.length; i++){
		cout << sortArray.arr[i] << endl;
	}
}