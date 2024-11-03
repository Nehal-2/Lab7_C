#include <stdio.h>
#include <ctype.h>

int main() {
	FILE *file;
	char data[100];
	int charCount = 0;
	int wordCount = 0;
	int lineCount = 0;
	int inWord = 0;
	
	file = fopen("cx-202-lab7/task2test.txt", "r");
	if (file == NULL) {
		perror("Error! Could not open file.\n");
		return 1;
	}
	while (fgets(data, sizeof(data), file) != NULL) {
		lineCount++;

		for (int i = 0; data[i] != '\0'; i++) {
			charCount++;

			// Check if the current character is a separator 
			if (isspace(data[i])) {
				if (inWord) {
					wordCount++;
					inWord = 0;
				}
			} else {
				inWord = 1;
			}
		}
		if (inWord) {
			wordCount++;
			inWord = 0;
		}
	}

	fclose(file);
	
	printf("Number of words: %d\n", wordCount);
	printf("Number of characters: %d\n", charCount);
	printf("Number of lines: %d\n", lineCount);

	return 0;
}
