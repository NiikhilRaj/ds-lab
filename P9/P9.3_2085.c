#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void createGraph(int adjMatrix[MAX][MAX], int vertices);
void displayDegrees(int adjMatrix[MAX][MAX], int vertices);
void DFS(int adjMatrix[MAX][MAX], int vertices, int startVertex, int visited[]);
void BFS(int adjMatrix[MAX][MAX], int vertices, int startVertex);

int main() {
    int vertices;
    int adjMatrix[MAX][MAX] = {0};
    int visited[MAX] = {0};
    int startVertex;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    createGraph(adjMatrix, vertices);
    displayDegrees(adjMatrix, vertices);

    printf("Enter start vertex: ");
    scanf("%d", &startVertex);

    printf("Depth First Search: ");
    DFS(adjMatrix, vertices, startVertex, visited);
    printf("\n");

    printf("Breadth First Search: ");
    BFS(adjMatrix, vertices, startVertex);
    printf("\n");

    return 0;
}

void createGraph(int adjMatrix[MAX][MAX], int vertices) {
    char response;
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            printf("Vertices %d & %d are Adjacent? (Y/N): ", i + 1, j + 1);
            scanf(" %c", &response);
            if (response == 'Y' || response == 'y') {
                adjMatrix[i][j] = 1;
                adjMatrix[j][i] = 1;
            }
        }
    }
}

void displayDegrees(int adjMatrix[MAX][MAX], int vertices) {
    printf("Vertex Degree\n");
    for (int i = 0; i < vertices; i++) {
        int degree = 0;
        for (int j = 0; j < vertices; j++) {
            if (adjMatrix[i][j] == 1) {
                degree++;
            }
        }
        printf(" %d %d\n", i + 1, degree);
    }
}

void DFS(int adjMatrix[MAX][MAX], int vertices, int startVertex, int visited[]) {
    printf("%d ", startVertex);
    visited[startVertex] = 1;

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[startVertex][i] == 1 && !visited[i]) {
            DFS(adjMatrix, vertices, i, visited);
        }
    }
}

void BFS(int adjMatrix[MAX][MAX], int vertices, int startVertex) {
    int queue[MAX], front = 0, rear = 0;
    int visited[MAX] = {0};

    queue[rear++] = startVertex;
    visited[startVertex] = 1;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}