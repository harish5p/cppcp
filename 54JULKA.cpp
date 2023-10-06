#include <bits/stdc++.h>
using namespace std;
void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int plus[101];
    int minus[101];
    int klaud[101];
    int nat[101];
    for(int i = 0; i<10;i++){
        char c;
        int a = 0;        
        while((c = getchar()) != '\n'){
            plus[a++] = c -48;
        }
        for(int j=0; j<a/2;j++){
            swap(plus[j], plus[a-j-1]);
        }
        for(int j=a;j<101;j++){ // add zeros
            plus[j] = 0;
        }

        a = 0;
        while((c = getchar()) != '\n'){
            minus[a++] = c - 48;
        }
        for(int j=0;j<a/2;j++){
            swap(minus[j],minus[a-j-1]);
        }
        for(int j=a; j<101; j++){
            minus[j] = 0;
        }

        a = 0;
        int carry =0;
        while(a<=100){
            plus[a] = plus[a] + minus[a] + carry;
            if(plus[a]>=10){
                plus[a] -= 10;
                carry = 1;
            } else{
                carry = 0;
            }
            a++;
        }

        int remainder  = 0;
        a = 100;
        bool started = false;
        while(a>=0){
            klaud[a] = (plus[a] + remainder) / 2;
            if(klaud[a]){
                started = true;
            }
            if(started){
                putchar(klaud[a]+48);
            }
            if((plus[a]+ remainder) % 2 ==1){
                remainder = 10;
            } else{
                remainder =0;
            }
            a--;
        }
        putchar('\n');

        a = 0;
        int borrow  = 0;
        while(a<=100){
            nat[a] = klaud[a] - minus[a] - borrow;
            if(nat[a]<0){
                nat[a] +=10;
                borrow = 1;
            } else{
                borrow =0;
            }
            a++;
        }

        for(a=100; !nat[a] && a >=0; a--){

        }
        if (a==-1){
            putchar('0');
        }
        for(;a>=0; a--){
            putchar(nat[a]+48);

        }
        putchar('\n');

    }
    return 0;

}