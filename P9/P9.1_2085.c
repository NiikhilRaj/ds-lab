#include <stdio.h>

#define MAX 100

void createGraph(int adjMatrix[MAX][MAX], int vertices);
void displayDegrees(int adjMatrix[MAX][MAX], int vertices);

int main() {
    int vertices;
    int adjMatrix[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    createGraph(adjMatrix, vertices);
    displayDegrees(adjMatrix, vertices);

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