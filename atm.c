#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

#define DOT_DURATION 200     // milliseconds
#define DASH_DURATION 600
#define SYMBOL_GAP 200       // between dots/dashes
#define LETTER_GAP 600       // between letters
#define WORD_GAP 1400        // between words

// Morse code dictionary
const char* morseTable[36] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",  // A-J
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",   // K-T
    "..-", "...-", ".--", "-..-", "-.--", "--..",                          // U-Z
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." // 0-9
};

void playDot() {
    Beep(750, DOT_DURATION);  // 750 Hz for a dot
    Sleep(SYMBOL_GAP);
}

void playDash() {
    Beep(750, DASH_DURATION); // 750 Hz for a dash
    Sleep(SYMBOL_GAP);
}

void playMorseCode(char ch) {
    if (isalpha(ch)) {
        ch = toupper(ch);
        const char* code = morseTable[ch - 'A'];
        printf("%c: %s\n", ch, code);
        for (int i = 0; code[i] != '\0'; i++) {
            if (code[i] == '.')
                playDot();
            else if (code[i] == '-')
                playDash();
        }
        Sleep(LETTER_GAP);
    } else if (isdigit(ch)) {
        const char* code = morseTable[ch - '0' + 26];
        printf("%c: %s\n", ch, code);
        for (int i = 0; code[i] != '\0'; i++) {
            if (code[i] == '.')
                playDot();
            else if (code[i] == '-')
                playDash();
        }
        Sleep(LETTER_GAP);
    } else if (ch == ' ') {
        Sleep(WORD_GAP);
    }
}

int main() {
    char input[100];

    printf("Enter a message to convert to Morse code: ");
    fgets(input, sizeof(input), stdin);

    printf("Playing Morse Code:\n");

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\n') continue;
        playMorseCode(input[i]);
    }

    printf("Done.\n");
    return 0;
}
