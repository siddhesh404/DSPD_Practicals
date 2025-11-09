#include <stdio.h>
#include <stdlib.h>
#define N 9
struct node {
    int vertex;
    struct node *next;
};
struct node *adj[N + 1];
int visited[N + 1];
struct node *createNewNode(int v) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}
void add(int u, int v) {
    struct node *newnode = createNewNode(v);
    newnode->next = adj[u];
    adj[u] = newnode;

    newnode = createNewNode(u);
    newnode->next = adj[v];
    adj[v] = newnode;
}
void createGraph() {
    add(1, 2);
    add(1, 4);
    add(2, 3);
    add(2, 5);
    add(3, 6);
    add(4, 5);
    add(4, 7);
    add(5, 6);
    add(5, 8);
    add(6, 9);
    add(7, 8);
    add(8, 9);
}
void BFS(int start) {
    int queue[20], front = 0, rear = -1;
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
    visited[start] = 1;
    queue[++rear] = start;
    printf("\nBFS Traversal: ");
    while (front <= rear) {
        int node = queue[front++];
        printf("%d ", node);
        struct node *temp = adj[node];
        while (temp) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[++rear] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}
void DFS(int start) {
    visited[start] = 1;
    printf("%d ", start);
    struct node *temp = adj[start];
    while (temp) {
        if (!visited[temp->vertex])
            DFS(temp->vertex);
        temp = temp->next;
    }
}
int main() {
    printf("Creating a graph...\n");
    for (int i = 0; i <= N; i++)
        adj[i] = NULL;
    createGraph();
    BFS(1);
    printf("\n");
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
    printf("\nDFS Traversal: ");
    DFS(1);
    return 0;
}