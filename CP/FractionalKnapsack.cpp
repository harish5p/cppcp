#include <bits/stdc++.h>
using namespace std;

class Item{
    public:
    int value, weight;
    Item(){
        value=0; 
        weight=0;
    }
};

bool comp(Item, Item);
float solveFrKnapSack(Item*, int, int);

int main(){
    int n,w;
    cout << "Enter the number of Items" << '\n';
    cin >> n;
    cout << "Enter capacity of knapsack" << '\n';
    cin >> w;
    Item* arr = new Item[n];
    cout << "Enter value of each item respectively" << '\n';
    for (int i=0; i<n;i++){
        cin >> arr[i].value;
    }
    cout << "Enter weight of each item respectively" << '\n';
    for (int i=0; i<n;i++){
        cin >> arr[i].weight;
    }

    cout << "You have entered the following objects" <<'\n';
    cout << "Value"<< '\t' << "Weight" << '\n';
    for (int i=0; i<n; i++){
        cout << arr[i].value << '\t' << arr[i].weight << '\n';
    }
    cout << "Maximum profit allowed is " << solveFrKnapSack(arr, w, n);
    return 0;
}

bool comp(Item a, Item b){
    float ratio1 = (float)a.value / (float)a.weight;
    float ratio2 = (float)b.value / (float)b.weight;
    return (ratio1 > ratio2);
}

float solveFrKnapSack(Item* arr, int w, int n){

    sort(arr, arr+n, comp);

    int capacity_left = w;
    float max_profit = 0;

    for (int i=0; i<n; i++){
        if(capacity_left ==0){
            break;
        }
        if (arr[i].weight > capacity_left){ //fractions
            max_profit += ((float)arr[i].value/ (float)arr[i].weight) * (float)capacity_left;
            capacity_left =0;

        } else{  // full item
            max_profit +=arr[i].value;
            capacity_left -= arr[i].weight;
        }
    }

    return (max_profit);

}