#include <stdio.h>
#include <string.h>

struct student {
    int roll_no;
    char name[50];
    char subject[50];
    float avg_marks;
};

int main() {
    int n, i, j;
    struct student s[100], temp;

    printf("Enter number of students: ");
    scanf("%d", &n);
    getchar(); 
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Roll no: ");
        scanf("%d", &s[i].roll_no);
        getchar(); 

        printf("Name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = 0; 

        printf("Subject: ");
        fgets(s[i].subject, sizeof(s[i].subject), stdin);
        s[i].subject[strcspn(s[i].subject, "\n")] = 0;

        printf("Average marks: ");
        scanf("%f", &s[i].avg_marks);
        getchar(); 
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (s[i].avg_marks < s[j].avg_marks) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    printf("\n--- Students Sorted by Average Marks (Descending Order) ---\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No   : %d\n", s[i].roll_no);
        printf("Name      : %s\n", s[i].name);
        printf("Subject   : %s\n", s[i].subject);
        printf("Avg Marks : %.2f\n", s[i].avg_marks);
    }

    return 0;
}
