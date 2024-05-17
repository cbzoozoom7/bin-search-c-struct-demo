//student.c
//Christopher Bowman
//Created Fri 10 Nov 2023
#include "student.h"
void sortStudents(Student students[], int size) {
	mergeSortStudents(students, 0, size-1);
}
void mergeSortStudents(Student arr[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSortStudents(arr, low, mid);
		mergeSortStudents(arr, mid + 1, high);
		int size = high - low + 1;
		Student *temp = (Student *) malloc(size * sizeof(Student));
		int tempI = 0;
		int leftI = low;
		int rightI = mid + 1;
		while (leftI <= mid && rightI <= high) {
			if (arr[leftI].id <= arr[rightI].id) {
				temp[tempI++] = arr[leftI++];
			} else {
				temp[tempI++] = arr[rightI++];
			}
		}
		while (leftI <= mid) {
			temp[tempI++] = arr[leftI++];
		}
		while (rightI <= high) {
			temp[tempI++] = arr[rightI++];
		}
		for (tempI = 0; tempI < size; tempI++) {
			arr[low+tempI] = temp[tempI];
		}
		free(temp);
	}
}
void print(Student arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("(%d,%s) -> ", arr[i].id, arr[i].name);
	}
	printf("\n");
}
Student searchStudent(Student students[], int size, int id) {
	return binSearchStudent(students, 0, size - 1, id);
}
Student binSearchStudent(Student students[], int low, int high, int id) {
	if (low <= high) {
		int mid = (low + high) / 2;
		if (students[mid].id > id) {
			return binSearchStudent(students, low, mid-1, id);
		} else if (students[mid].id < id) {
			return binSearchStudent(students, mid+1, high, id);
		} else {
			return students[mid];
		}
	} else {
		return students[0];
	}
}
