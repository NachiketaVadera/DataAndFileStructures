#include <stdio.h>
#include <stdbool.h>
#define SIZE 8

bool visited[SIZE];
int graph[SIZE][SIZE];
int n;

void initVisited();
bool dfs(int);

int main() {
	initVisited();
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	printf("Enter the adjecency matrix of the graph: ");
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			scanf("%d",&graph[i][j]);
	dfs(1);
	return 0;
}

void initVisited() {
	for(int i = 0;i < SIZE;i++)
		visited[i] = false;
}

bool dfs(int vertex) {
        bool flag = false;
	visited[vertex] = true;
	printf("\n%d\n", vertex);
	for(int adj = 0;adj < n;adj++)
		if(!visited[adj] && graph[vertex][adj])
			flag = dfs(adj);
	if(flag)
		return true;
}
