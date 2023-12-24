/*
Problem: Check A Graph Contains a Cycle
Description
Cho đồ thị vô hướng G = (V,E) trong đó V = {1,…,n} là tập đỉnh và E là tập có m cạnh. Hãy kiểm tra xem G có chứa chu trình hay không?
Dữ liệu
· Dòng 1: ghi số nguyên dương n và m (1 <= n,m <= 100000)
· Dòng thứ i+1( i = 1,…,m): ghi 2 số nguyên dương u và v là đầu mút của cạnh thứ i của G.
Kết quả
· Ghi ra 1 nếu G chứa chu trình và ghi ra 0, nếu ngược lại
Ví dụ
Dữ liệu
6 8
1 6
1 3
2 4
2 5
2 6
3 4
3 6
4 5
Kết quả
1
*/
#include <stdio.h>
#include <stdlib.h>

// Cấu trúc cho danh sách liên kết đơn.
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Cấu trúc cho danh sách đỉnh.
typedef struct {
    Node* head;
} List;

// Cấu trúc cho đồ thị.
typedef struct {
    int numVertices;
    List* adjLists;
    int* visited;
} Graph;

// Hàm tạo một nút mới trong danh sách liên kết.
Node* createNode(int v)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Hàm khởi tạo đồ thị.
Graph* createGraph(int vertices)
{
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(List));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i].head = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Hàm thêm cạnh vào đồ thị.
void addEdge(Graph* graph, int src, int dest)
{
    // Thêm cạnh từ src đến dest.
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src].head;
    graph->adjLists[src].head = newNode;

    // Thêm cạnh từ dest đến src, vì đồ thị vô hướng.
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest].head;
    graph->adjLists[dest].head = newNode;
}

// Hàm DFS để kiểm tra chu trình trong đồ thị.
int dfs(Graph* graph, int vertex, int parent)
{
    graph->visited[vertex] = 1;
    Node* temp = graph->adjLists[vertex].head;

    while (temp) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            if (dfs(graph, connectedVertex, vertex))
                return 1;
        } else if (connectedVertex != parent) {
            // Tìm thấy chu trình.
            return 1;
        }

        temp = temp->next;
    }
    return 0;
}

// Hàm chính.
int main()
{
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);
    Graph* graph = createGraph(vertices);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src - 1, dest - 1); // Đánh số đỉnh từ 0.
    }

    for (int i = 0; i < vertices; i++) {
        if (!graph->visited[i]) {
            if (dfs(graph, i, -1)) {
                printf("1\n");
                return 0;
            }
        }
    }

    printf("0\n");
    return 0;
}
