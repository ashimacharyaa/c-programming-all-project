//Write a C program to split a large text file into multiple smaller files, each containing a specified number of lines.

#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *inputFile, *outputFile;
    char line[1024];
    char outputFilename[50];
    int linesPerFile;
    int lineCount = 0, fileCount = 1;
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input.txt\n");
        return 1;
    }
    printf("Enter the number of lines per split file: ");
    scanf("%d", &linesPerFile);
    sprintf(outputFilename, "output_%d.txt", fileCount);
    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error: Could not create output file.\n");
        fclose(inputFile);
        return 1;
    }
    while (fgets(line, sizeof(line), inputFile)) {
        fputs(line, outputFile);
        lineCount++;
        if (lineCount == linesPerFile) {
            fclose(outputFile);
            fileCount++;
            lineCount = 0;
            sprintf(outputFilename, "output_%d.txt", fileCount);
            outputFile = fopen(outputFilename, "w");
            if (outputFile == NULL) {
                printf("Error: Could not create output file.\n");
                fclose(inputFile);
                return 1;
            }
        }
    }
    fclose(inputFile);
    fclose(outputFile);
    printf("File successfully split into %d parts.\n", fileCount);
    return 0;
}
