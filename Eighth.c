#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

struct Edge {
    int v, w;
    struct Edge* next;
};

void addEdge(struct Edge* adj[], int u, int v, int w) {
    struct Edge* new1 = (struct Edge*)malloc(sizeof(struct Edge));
    new1->v = v;
    new1->w = w;
    new1->next = adj[u];
    adj[u] = new1;

    struct Edge* new2 = (struct Edge*)malloc(sizeof(struct Edge));
    new2->v = u;
    new2->w = w;
    new2->next = adj[v];
    adj[v] = new2;
}

int extractMin(int dist[], int visited[], int n) {
    int min = INF, minIndex = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int n, e, u, v, w, start;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    struct Edge* adj[n + 1];
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }
    printf("Enter starting node: ");
    scanf("%d", &start);
    int dist[n + 1], visited[n + 1], parent[n + 1];
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[start] = 0;
    for (int i = 1; i <= n; i++) {
        int u = extractMin(dist, visited, n);
        if (u == -1) break;
        visited[u] = 1;
        struct Edge* temp = adj[u];
        while (temp != NULL) {
            int v = temp->v, w = temp->w;
            if (!visited[v] && dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }
    printf("\nShortest distances from node %d:\n", start);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            printf("Node %d : -1\n", i);
        else
            printf("Node %d : %d\n", i, dist[i]);
    }
    printf("\nShortest Path Tree (parent array):\n");
    for (int i = 1; i <= n; i++) {
        printf("Node %d <- %d\n", i, parent[i]);
    }
    return 0;
}
