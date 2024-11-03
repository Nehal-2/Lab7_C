#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT 3

void encrypt(char *text);
void decrypt(char *text);

int main() {
	FILE *file;
	char choice1, choice2;
	char input[100] = {0};
	char filename[50];

	printf("Welcome to the Caesar Cipher Program!\n\n");
	printf("Do you want to perform (E)ncryption or (D)ecryption?\n");
	scanf(" %c", &choice1);

	if (choice1 == 'E' || choice1 == 'D') {
		printf("Do you want to encrypt data from a (F)ile or enter a (S)tring?\n");
		scanf(" %c", &choice2);

		switch (choice2) {
			case 'F':
				printf("Please enter the filename:\n");
				scanf(" %s", filename);

				file = fopen(filename, choice1 == 'E' ? "r" : "r+"); // read for encryption, read and write for decryption
				if (file == NULL) {
					perror("Error! Could not open file.\n");
					return 1;
				}

				size_t bytesRead = fread(input, sizeof(char), sizeof(input) - 1, file);
				input[bytesRead] = '\0'; // Null-terminate to avoid garbage
				fclose(file);

				if (choice1 == 'E') {
					encrypt(input);
					printf("Encrypted data: %s\n", input);

					file = fopen("encrypted.txt", "w");
					if (file == NULL) {
						perror("Error! Could not open file.");
						return 1;
					}
				
				
					fwrite(input, sizeof(char), strlen(input), file);
					fclose(file);
					printf("\nEncrypted data saved to encrypted.txt\n");
				} else {
					decrypt(input);
					printf("\nDecrypted data: %s\n", input);
				}
				break;

			case 'S':
				printf("Please enter the string to encrypt:\n> ");
				getchar();
				fgets(input, 100, stdin);
				
				if (choice1 == 'E') {
					encrypt(input);
					printf("\nEncrypted string: %s\n", input);
				} else {
					decrypt(input);
					printf("\nDecrypted string: %s\n", input);
				}
				break;

			default:
				printf("Invalid input. Please try again\n");
				break;
		}
	} else {
		printf("Invalid input. Please try again\n");
	}

	return 0;
}

void encrypt(char *text) {
	for (int i = 0; text[i] != '\0'; i++) {
		if (text[i] >= 'A' && text[i] <= 'Z') {
			text[i] = ((text[i] - 'A' - SHIFT + 26)%26) + 'A';
		} else if (text[i] >= 'a' && text[i] <= 'z') {
			text[i] = ((text[i] - 'a' - SHIFT + 26)%26) + 'a';
		}
	}
}

void decrypt(char *text) {
	for (int i = 0; text[i] != '\0'; i++) {
		if (text[i] >= 'A' && text[i] <= 'Z') {
			text[i] = ((text[i] - 'A' + SHIFT)%26) + 'A';
		} else if (text[i] >= 'a' && text[i] <= 'z') {
			text[i] = ((text[i] - 'a' + SHIFT)%26) + 'a';
		}
	}
}
