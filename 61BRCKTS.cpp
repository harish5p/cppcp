// https://chat.openai.com/c/e222b37b-12c4-4aad-b91e-7bba2b87aa32
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int left,right;
        Node(int left, int right){
            this->left = left;
            this->right = right;
        }
        Node(){}
};

int getSize(int n){
    int sze = 1;
    while(sze<n){
        sze<<=1;
    }
    return sze<<1;
}

void build(Node seg[], string &str, int p, int i, int j){
    if(i>=j){
        if(str[i]=='('){
            seg[p] = Node(1,0);
        }else{
            seg[p] = Node(0,1);
        }
        return;
    }
    int mid = (i+j)/2;
    build(seg,str,2*p+1,i,mid);
    build(seg,str,2*p+2,mid+1,j);

    int mn = min(seg[2*p+1].left, seg[2*p+2].right);

    seg[p] = Node(seg[2*p+1].left + seg[2*p+2].left - mn, seg[2*p+2].right+seg[2*p+1].right-mn);
}

void update(Node seg[], int p, int i, int j, int s, int e){
    if (i==s && j==e){
        seg[p].left = seg[p].left ?0:1;
        seg[p].right = seg[p].right ?0:1;
        return ;
    }
    int mid = (i+j)/2;
    if(e<=mid){
        update(seg,2*p+1,i,mid,s,e);
    } else if(s>mid){
        update(seg, 2*p+2, mid+1, j,s,e);
    } else{
        update(seg, 2*p+1, i, mid, s,mid);
        update(seg, 2*p+2, mid+1, j, mid+1, j);
    }
    int mn = min(seg[2*p+1].left, seg[2*p+2].right);
    seg[p] = Node(seg[2*p+1].left + seg[2*p+2].left - mn, seg[2*p+2].right+seg[2*p+1].right-mn);
}

int main(){
    int N = 10;
    int n,m,q;
    int k=1;
    string str;
    while(N--){
        cin >> n>> str>>m;
        cout << "Test "<< k<<":"<<'\n';
        int sze = getSize(n);
        Node seg[sze+1];
        build(seg, str, 0,0,n-1);

        int q;
        for(int i=0; i<m; i++){
            cin>>q;
            if(q==0){
                if(seg[0].left==0 && seg[0].right==0){
                    cout <<"YES"<<'\n';
                }else{
                    cout <<"NO"<<'\n';
                }
            }else{
                update(seg,0,0,n-1,q-1,q-1);
            }
        }
        k++;
    }

}