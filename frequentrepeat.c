#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LEN 50
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}
int main() {
    FILE *file;
    char word[WORD_LEN];
    char words[MAX_WORDS][WORD_LEN];
    int freq[MAX_WORDS] = {0};
    int totalWords = 0;
    int i, j, maxIndex = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input.txt\n");
        return 1;
    }

    while (fscanf(file, "%49s", word) == 1) {
        int len = strlen(word);
        int k = 0;
        char cleanWord[WORD_LEN];
        for (i = 0; i < len; i++) {
            if (isalpha(word[i])) {
                cleanWord[k++] = tolower(word[i]);
            }
        }
        cleanWord[k] = '\0';
        if (strlen(cleanWord) == 0)
            continue;
        for (i = 0; i < totalWords; i++) {
            if (strcmp(words[i], cleanWord) == 0) {
                freq[i]++;
                break;
            }
        }

        if (i == totalWords && totalWords < MAX_WORDS) {
            strcpy(words[totalWords], cleanWord);
            freq[totalWords] = 1;
            totalWords++;
        }
    }

    fclose(file);
    for (i = 1; i < totalWords; i++) {
        if (freq[i] > freq[maxIndex]) {
            maxIndex = i;
        }
    }
    if (totalWords > 0) {
        printf("Most frequent word: '%s'\n", words[maxIndex]);
        printf("Frequency: %d\n", freq[maxIndex]);
    } else {
        printf("No words found in the file.\n");
    }

    return 0;
}
