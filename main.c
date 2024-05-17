//main.c
//Christopher Bowman
//Created Mon 13 Nov 2023
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#define LINE_LENGTH 20
int main (int argc, char **argv) {
	int exitCode = 0;
	if (argc > 1) {
		FILE *fileIn = fopen(argv[1], "r");
		if (fileIn != NULL) {
			int studentCount = 1;
			char currentChar = getc(fileIn);
			while (currentChar != EOF) {
				if (currentChar == '\n') {
					studentCount++;
				}
				currentChar = getc(fileIn);
			}
			rewind(fileIn);
			Student *students = (Student *) malloc(studentCount * sizeof(Student));
			int i;
			for (i = 0; i < studentCount; i++) {
				char currentLine[LINE_LENGTH];
				fgets(currentLine,  LINE_LENGTH, fileIn);
				int id;
				char name[NAME_LENGTH];
				sscanf(currentLine, "%d,%s", &id, name);
				students[i].id = id;
				strcpy(students[i].name, name);
			}
			fclose(fileIn);
			print(students, studentCount);
			sortStudents(students, studentCount);
			print(students, studentCount);
			int searchId;
			scanf("%d", &searchId);
			Student searchResult = searchStudent(students, studentCount, searchId);
			printf("(%d,%s)\n", searchResult.id, searchResult.name);
			free(students);
		} else {
			exitCode = -2;
			printf("ERROR FILE NOT OPEN\n");
		}
	} else {
		exitCode = -1;
		printf("ERROR NO ARGS\n");
	}
	return exitCode;
}
