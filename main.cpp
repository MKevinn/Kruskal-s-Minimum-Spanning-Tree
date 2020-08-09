//
//  main.cpp
//  Kruskal's MST
//
//  Created by Kevinn on 2020/6/2.
//  Copyright © 2020 Kevinn. All rights reserved.
//

#include <iostream>
#define I 65535
using namespace std;

int edges[3][9] = {         // all edges and cost in third row
    {1, 1,2, 2, 3,4, 4, 5, 5},
    {2, 6,3, 7, 4,5, 7, 6, 7},
    {25,5,12,10,8,16,14,20,18}
};
int set[8] = {-1};     // for each point's parent
int included[9] = {0};  // is each edge being considered, 0 or 1
int t[2][6];

void MyUnion(int u, int v) {        // union two sets, increase one's number of children; conform one to the other one's index
    if (set[u] < set[v]) {
        set[u] += set[v];
        set[v] = u;
    } else {
        set[v] += set[u];
        set[u] = v;
    }
}

int find(int u) {       // return root parent's index
    int x=u, v=0;
    while (set[x] > 0) {        // if value at that index is bigger than 0, there's a parent, x is the root parent's index
        x = set[x];
    }
    while (u != x) {      // if u does have parent, change u's parent directly to root parent
        v = set[u];     // v is the first level parent, change all u's superficial parents' parent to root parent x
        set[u] = x;
        u = v;
    }
    return x;
}


int main(int argc, const char * argv[]) {
    
    int i=0,j,k,u,v,min=I,n=7,e=9;
    
    while (i < n-1) {       // outer loop fills in t -- result order
        min = I;
        
        for (j=0; j<e; j++) {
            if (included[j]==0 && edges[2][j] < min) {
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;          // k is the index of the edge with minimum cost
            }
        }
        
        if (find(u) != find(v)) {       // if u's and v's root parent is different
            t[0][i] = u;
            t[1][i] = v;
            MyUnion(find(u), find(v));
            i++;
        }
        
        included[k] = 1;        // edge k has been considered
    }
    
    for (i=0; i<n-1; i++)
        cout << "(" << t[0][i] << "," << t[1][i] << ")\n";
    
    return 0;
}
