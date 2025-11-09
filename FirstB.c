#include <stdio.h>
void search(int a[], int n, int b[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        int first = 0, last = n - 1, mid, found = 0;

        while (first <= last) {
            mid = (first + last) / 2;

            if (a[mid] == b[i]) {
                printf("\nElement %d found at position %d", b[i], mid + 1);
                found = 1;
                break;
            } else if (a[mid] < b[i]) {
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }

        if (!found) {
            printf("\nElement %d not found", b[i]);
        }
    }
}
int main() {
    int n, size, i, j;
    int flag1 = 0, flag2 = 0;

    printf("Enter the size of array: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid array size!");
        return 0;
    }
    int a[n];
    printf("Enter elements (sorted): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the number of search elements: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid search size!");
        return 0;
    }
    int b[size];
    printf("Enter search elements: ");
    for (j = 0; j < size; j++) {
        scanf("%d", &b[j]);
    }
    for (i = 0; i < n; i++) {
        if (a[i] != 0) {
            flag1 = 1;
            break;
        }
    }
    if (flag1 == 0) {
        printf("Array is empty.");
        return 0;
    }
    for (j = 0; j < size; j++) {
        if (b[j] != 0) {
            flag2 = 1;
            break;
        }
    }
    if (flag2 == 0) {
        printf("\nSearch elements are empty.");
        return 0;
    }
    search(a, n, b, size);
    return 0;
}
