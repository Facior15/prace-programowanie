#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void usage(char *program_name) {
    printf("Usage: %s number1 operation number2\n", program_name);
    printf("Available operations:\n");
    printf("\tadd, sub, mul, div, mod\n\n");
}

// ============================================================================
// ALTERNATYWNY PRZYKŁAD 1: Wypisywanie przekazanych argumentów
// ============================================================================
/*
int main(int argc, char const *argv[]) {
    printf("Podano %d argumentow:\n", argc);
    for(int i = 0; i < argc; i++) {
        printf("Argument #%d\t\t%s\n", i, argv[i]);
    }
    return 0;
}
*/

// ============================================================================
// ALTERNATYWNY PRZYKŁAD 2: Powtarzanie komunikatu N-razy
// ============================================================================
/*
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Sposob uzycia: %s <komunikat> <#powtorzen>\n", argv[0]);
        exit(1);
    }
    int count = atoi(argv[2]);
    printf("Powtarzam %d razy.\n", count);
    for (int i = 0; i < count; i++) {
        printf("%3d - %s\n", i, argv[1]);
    }
    return 0;
}
*/

// ============================================================================
// GŁÓWNY PROGRAM: Zaawansowany Kalkulator CLI
// ============================================================================
int main(int argc, char* argv[]) {
    int number1 = 0;
    int number2 = 0;
    int result = 0;

    if (argc == 4) {
        number1 = atoi(argv[1]);
        number2 = atoi(argv[3]);

        if (!strcmp("add", argv[2])) {
            result = number1 + number2;
            printf("%d + %d= %d\n", number1, number2, result);
        }
        else if (!strcmp("sub", argv[2])) {
            result = number1 - number2;
            printf("%d - %d= %d\n", number1, number2, result);
        }
        else if (!strcmp("mul", argv[2])) {
            result = number1 * number2;
            printf("%d * %d= %d\n", number1, number2, result);
        }
        else if (!strcmp("div", argv[2])) {
            if (number2 != 0) {
                result = number1 / number2;
                printf("%d / %d= %d\n", number1, number2, result);
            } else {
                printf("Error: Division by zero!\n");
            }
        }
        else if (!strcmp("mod", argv[2])) {
            if (number2 != 0) {
                result = number1 % number2;
                printf("%d %% %d= %d\n", number1, number2, result);
            } else {
                printf("Error: Division by zero!\n");
            }
        }
    } else {
        usage(argv[0]);
    }

    return 0;
}