#include <iostream>

void to_lowercase(char *str) {
    while (*str) {
        if ('A' <= *str && *str <= 'Z') {
            *str += ('a' - 'A');
        }
        str++;
    }
}

void to_uppercase(char *str) {
    while (*str) {
        if ('a' <= *str && *str <= 'z') {
            *str += ('A' - 'a');
        }
        str++;
    }
}

int size_text(char *str) {
    int size = 0;
    while (*str) {
        size++;
        str++;
    }
    return size;
}

void change(char *str) {
    int len = size_text(str);
    if (len > 0) {
        str[len - 1] = 0;
    }
}

int main() {
    char str[80];
    while (true) {
        printf("Enter a text: ");
        fgets(str, 80, stdin);
        if (str[0] == '\n') {
            break;
        }
        change(str);
        printf("%s\n", str);
        to_lowercase(str);
        printf("%s\n", str);
        to_uppercase(str);
        printf("%s\n", str);
        printf("text size=%d\n", size_text(str));
    }
    return 0;
}