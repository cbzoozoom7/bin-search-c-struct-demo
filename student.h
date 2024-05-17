//student.h
//Christopher Bowman
//Created Fri 10 Nov 2023
#ifndef STUDENT_H
	#define STUDENT_H
	#include <stdlib.h>
	#include <stdio.h>
	#define NAME_LENGTH 10
	typedef struct {
		int id;
		char name[NAME_LENGTH];
	} Student;
	void sortStudents(Student[], int);
	void print(Student[], int);
	Student searchStudent(Student[], int, int);
	void mergeSortStudents(Student[], int, int);
	Student binSearchStudent(Student[], int, int, int);
#endif
