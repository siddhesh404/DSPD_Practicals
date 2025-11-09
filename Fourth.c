#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newnode;
    int num, count = 0;

    printf("Enter the elements to add to the linked list (enter 0 to stop):\n");

    while(1) {
        printf("Enter data: ");
        scanf("%d", &num);

        if(num == 0)
            break;

        newnode = (struct node*)malloc(sizeof(struct node));  
        newnode->data = num;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
        count++;
    }

    printf("\nLinked list elements:\n");
    temp = head;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;  
    }
    printf("NULL\n");

    printf("\nTotal number of nodes: %d\n", count);

    return 0;
}
