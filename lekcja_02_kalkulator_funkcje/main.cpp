#include <iostream>

int not_zero(int num) {
    if (num == 0) {
        return 0;
    }
    return 1;
}

int sum(int *num1, int *num2) {
    int n1 = *num1;
    int n2 = *num2;
    int r = n1 + n2;
    return r;
}

int mult(int *num1, int *num2) {
    int n1 = *num1;
    int n2 = *num2;
    int r = n1 * n2;
    return r;
}

int divide(int *num1, int *num2) {
    int n1 = *num1;
    int n2 = *num2;
    int r = n1 / n2;
    return r;
}

int subtract(int *num1, int *num2) {
    int n1 = *num1;
    int n2 = *num2;
    int r = n1 - n2;
    return r;
}

int main() {
    while (true) {
        printf("Simple calculator\n");
        int num1 = 0;
        not_zero(num1);
        int num2 = 0;
        not_zero(num2);

        printf("Enter number no.1\n");
        scanf("%d", &num1);
        printf("Enter number no.2\n");
        scanf("%d", &num2);

        int r = sum(&num1, &num2);
        int r1 = mult(&num1, &num2);
        int r2 = divide(&num1, &num2);
        int r3 = subtract(&num1, &num2);

        printf("sum= %d \n", r);
        printf("mult= %d \n", r1);
        printf("divide= %d \n", r2);
        printf("subtract= %d \n", r3);
    }
    return 0;
}