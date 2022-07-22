#include<stdio.h>
#include<stdlib.h>

struct Edge 
{
    int s, d, w; // Source node, destination node, weight
};

// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // Find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else 
    {
        // If ranks are same, then make one as root and increment its rank by one
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights, Used in qsort() for sorting an array of edges
int edgeComparison(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->w > b1->w;
}

int main() 
{
    int V, E;
    scanf("%d %d",&V,&E);
    // Initialize array containing all of our edges
    struct Edge* edge = (struct Edge*) malloc( E * sizeof( struct Edge ) );

    // Insert E edges
    for (int i = 0; i < E; ++i)
    {
        int s, d, w;
        scanf("%d %d %d",&s,&d,&w);
        edge[i].s = s;
        edge[i].d = d;
        edge[i].w = w;
    }

    // Sort the edges
    qsort(edge, E, sizeof(edge[0]), edgeComparison);

    // Initialize a set to store the resultant MST
    // (E = V-1 in a tree)
    struct Edge mst[V-1];
    int mstSize = 0;

    // Create V subsets with single elements (this represents our spanning tree)
    struct subset *subsets = (struct subset*) malloc( V * sizeof(struct subset) );
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Perform Kruskal's Algorithm
    for(int i = 0; i < E; i++) {
        // Get the minimum edge in E
        struct Edge minEdge = edge[i];
        // Use the Union-Find algorithm to check if E causes a cycle
        int x = find(subsets, minEdge.s-1);
        int y = find(subsets, minEdge.d-1);
        // If including this edge does't cause cycle, include it in the MST
        if (x != y) {
            mst[mstSize++] = minEdge;
            Union(subsets, x, y);
        }
        if(mstSize == V-1) {
            break; // MST is complete
        }
    }
    // // Compute total weight
    int totalWeight = 0;
    for(int i = 0; i < V-1; i++) {
        totalWeight += mst[i].w;
    }
    printf("%d\n",totalWeight);
    return 0;
}
