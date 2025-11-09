#include <stdio.h>
void sum(int a[], int n, int sum_even, int sum_odd) {
    int i;
    sum_even = 0;
    sum_odd = 0;
    for (i = 0; i < n; i++) {
        if (i % 2 == 0)
            sum_even += a[i];
        else
            sum_odd += a[i];
    }
}
int main() {
    int a[100], i, n;
    int sum_even, sum_odd;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]); 
    }
    sum(a, n, &sum_even, &sum_odd);
    printf("\nSum of even position elements: %d", sum_even);
    printf("\nSum of odd position elements: %d", sum_odd);
    return 0;
}
