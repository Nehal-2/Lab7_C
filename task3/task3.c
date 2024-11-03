#include <stdio.h>

int main() {
	FILE *inFile, *outFile;
	int bit;
	int byte = 0;
	int bitCount = 0;

	inFile = fopen("cx-202-lab7/bitstream1.bit", "r");
	outFile = fopen("task3/bitstream1.hex", "w");

	if (inFile == NULL || outFile == NULL) {
		perror("Error! Could not open file.\n");
		return 1;
	}

	while (fscanf(inFile, "%d", &bit) == 1) {
		// Shift the current byte to the left by one position and add the new bit (Litlle-endianness)
		byte |= (bit & 1) << bitCount;
		bitCount++;
		
		if (bitCount == 8) {
			fprintf(outFile, "%02X\n", byte);
			byte = 0;
			bitCount = 0;
		}
	}
	// Zero-padding if no. of bits is not a multiple of 8
	if (bitCount > 0) {
		fprintf(outFile, "%02X\n", byte);
	}
	fclose(inFile);
	fclose(outFile);

	return 0;
}
