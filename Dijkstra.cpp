// # c++ implementation -> https://www.youtube.com/watch?v=t2d-XYuPfg0
//  https://gist.github.com/SuryaPratapK/531ec1fd8efdaeb0c098b89a7a1a9d3e
#include <bits/stdc++.h>
using namespace std;

const int V = 6;

int selectMinVertex(vector<int> &value, vector<bool> &processed){
    int minimum = INT_MAX;
    int vertex;
    for (int i=0; i<V; ++i ){
        if(processed[i]==false && value[i]<minimum){
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

void dj(int graph[V][V]){
    int parent[V];
    vector<int> value(V, INT_MAX);
    vector<bool> processed(V, false);

    parent[0]= -1;
    value[0]=0;

    for(int i=0;i<V-1;++i){
        int U = selectMinVertex(value,processed);
        processed[U]= true;

        for (int j=0; j<V;++j){
            if(graph[U][j]!=0 && processed[j]==false && value[U]!=INT_MAX && (value[U]+graph[U][j] <value[j])){
                value[j] = value[U]+graph[U][j];
                parent[j]= U;
            }
        }
    }
    for (int i=1;i<V; ++i){
        cout<<"U->V: " << parent[i] <<"->" <<i << " wt = "<< graph[parent[i]][i] << '\n';
    }

}

int main(){
    int graph[V][V] = { {0, 1, 4, 0, 0, 0},
						{1, 0, 4, 2, 7, 0},
						{4, 4, 0, 3, 5, 0},
						{0, 2, 3, 0, 4, 6},
						{0, 7, 5, 4, 0, 7},
						{0, 0, 0, 6, 7, 0} };
    dj(graph);
    return 0;
}