#include <iostream>
#define  SIZE 10

void Array_print(int *numbers, int size) {
    for (int i = 0; i < size; i++) {
        printf("number[%d]=%d\n", i, *(numbers+i));
    }
}

int max_array(int *numbers, int size) {
    int max = *numbers;
    for (int i = 0; i < size; i++) {
        if  (max < *(numbers+i )) {
            max = *(numbers+i );
        }
    }
    return max;
}

int min_array(int *numbers, int size) {
    int min = *numbers;
    for (int i = 0; i < size; i++) {
        if (min > *(numbers+i)) {
            min = *(numbers+i);
        }
    }
    return min;
}

int sum(int *numbers, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(numbers+i);
    }
    return sum;
}

float average(int *numbers, int size) {
    float avg = (float)sum(numbers, size) / size;
    return avg;
}

void sort_array(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void copy_array(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

double median(int *numbers, int size) {
    int temp_array[size];
    copy_array(numbers, temp_array, size);
    sort_array(temp_array, size);
    double median;
    if (size % 2 != 0) {
        median = (double)temp_array[size / 2];
        printf("median=%.2f\n", median);
    } else {
        median = (temp_array[size / 2 - 1] + temp_array[size / 2]) / 2.0;
        printf("median=%.2f\n", median);
    }
    return median;
}

void menu() {
    printf("\nMenu\n");
    printf("Type 1. to show numbers\n");
    printf("Type 2. to show max numbers\n");
    printf("Type 3. to show min number\n");
    printf("Type 4. to show sum number\n");
    printf("Type 5 to show average number\n");
    printf("Type 6 to show median number\n");
    printf("Type 0 to exit\n");
}

int main() {
    int numbers[SIZE] = {1, 2, 3, 40, -5, 6, 7, 8, 9, 10};
    int option;
    do {
        menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                Array_print(numbers, SIZE);
                break;
            case 2:
                printf("max=%d\n", max_array(numbers, SIZE));
                break;
            case 3:
                printf("min=%d\n", min_array(numbers, SIZE));
                break;
            case 4:
                printf("sum=%d\n", sum(numbers, SIZE));
                break;
            case 5:
                printf("average=%.2f\n", average(numbers, SIZE));
                break;
            case 6:
                printf("median=%.2f\n", median(numbers, SIZE));
                break;
            case 0:
                printf("Goodbye!\n");
                break;
        }
        if (option > 6 || option < 0) {
            printf("Type correct number!\n");
        }
    } while (option != 0);

    return 0;
}