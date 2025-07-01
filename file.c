#include <stdio.h>

int main() {
    FILE *file;
    int numbers[] = {10, 20, 30, 40, 50};

    file = fopen("numbers.bin", "wb");
    if (file == NULL) {
        printf("Error: Could not create file.\n");
        return 1;
    }

    fwrite(numbers, sizeof(int), 5, file);
    fclose(file);

    printf("File created with 5 integers.\n");

    return 0;
}
