#include <stdio.h>

typedef struct {
                int id;
                char name[50];
                float gpa;
        } Student;

int main() {
	int N; // Number of students
	
	printf("Enter the number of students: ");
	scanf(" %d",& N);

	Student students[N];

	for (int i = 0; i < N; i++) {
		printf("Enter ID for student %d: ", i + 1);
		scanf(" %d", &students[i].id);
		printf("Entere name for student %d: ", i + 1);
		scanf(" %s", students[i].name);
		printf("Enter GPA for student %d: ", i + 1);
		scanf(" %f", &students[i].gpa);
	}

	printf("Student Records:\n");

	for (int i = 0; i < N; i++) {
		printf("ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
	}

	return 0;
}
