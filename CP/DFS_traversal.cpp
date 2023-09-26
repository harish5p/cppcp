#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        map<int, bool> visited;
        map<int, vector<int>> adj_list;

        void dfsPrint(int v){
            visited[v] =  true;
            cout << v << " ";

            for (auto i =adj_list.begin(); i !=adj_list.end(); i++){
                if (visited[i->first] != true){
                    dfsPrint(i->first);
                }
            }
        }

        void addEdge(int a, int b){
            adj_list[a].push_back(b);
        }
};

int main(){
    Graph a_g;
    a_g.addEdge(0,1);
    a_g.addEdge(0,2);
    a_g.addEdge(1,2 );
    a_g.addEdge(1,3 );
    a_g.addEdge(2,0);
    a_g.addEdge(2,1);
    a_g.addEdge(2,3);
    a_g.addEdge(3,0);
    a_g.dfsPrint(1);

}