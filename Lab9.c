#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the graph
struct Node {
    char data[20];
    struct Node** neighbors;
    int num_neighbors;
    int visited;
};

// Function to create a new node
struct Node* createNode(char data[20]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->num_neighbors = 0;
    newNode->visited = 0;
    newNode->neighbors = NULL;
    return newNode;
}

// Function to add an edge between two nodes
void addEdge(struct Node* node1, struct Node* node2) {
    node1->neighbors = realloc(node1->neighbors, (node1->num_neighbors + 1) * sizeof(struct Node*));
    node1->neighbors[node1->num_neighbors++] = node2;

    node2->neighbors = realloc(node2->neighbors, (node2->num_neighbors + 1) * sizeof(struct Node*));
    node2->neighbors[node2->num_neighbors++] = node1;
}

// Breadth-First Traversal
void breadthFirstTraversal(struct Node* startNode) {
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = startNode;
    startNode->visited = 1;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%s ", current->data);

        for (int i = 0; i < current->num_neighbors; i++) {
            struct Node* neighbor = current->neighbors[i];
            if (!neighbor->visited) {
                queue[rear++] = neighbor;
                neighbor->visited = 1;
            }
        }
    }
}

// Depth-First Traversal
void depthFirstTraversal(struct Node* startNode) {
    printf("%s ", startNode->data);
    startNode->visited = 1;

    for (int i = 0; i < startNode->num_neighbors; i++) {
        struct Node* neighbor = startNode->neighbors[i];
        if (!neighbor->visited) {
            depthFirstTraversal(neighbor);
        }
    }
}

// Example usage
int main() {
    struct Node* employeeA = createNode("Annmary");
    struct Node* employeeB = createNode("Sona");
    struct Node* employeeC = createNode("Rojal");
    struct Node* employeeD = createNode("Abin");
    struct Node* employeeE = createNode("Aaron");
    struct Node* employeeF = createNode("Ashwin");

    addEdge(employeeA, employeeB);
    addEdge(employeeA, employeeC);
    addEdge(employeeB, employeeD);
    addEdge(employeeB, employeeE);
    addEdge(employeeC, employeeF);

    printf("Breadth-First Traversal: ");
    breadthFirstTraversal(employeeA);
    printf("\n");

    // Reset visited flags
    employeeA->visited = 0;
    employeeB->visited = 0;
    employeeC->visited = 0;
    employeeD->visited = 0;
    employeeE->visited = 0;
    employeeF->visited = 0;

    printf("Depth-First Traversal: ");
    depthFirstTraversal(employeeA);
    printf("\n");

    // Free allocated memory
    free(employeeA->neighbors);
    free(employeeB->neighbors);
    free(employeeC->neighbors);
    free(employeeD->neighbors);
    free(employeeE->neighbors);
    free(employeeF->neighbors);
    free(employeeA);
    free(employeeB);
    free(employeeC);
    free(employeeD);
    free(employeeE);
    free(employeeF);

    return 0;
}
