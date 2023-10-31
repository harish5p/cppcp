#include <bits/stdc++.h>
using namespace std;

int extended_euclid(int a, int b, int &x, int &y){
    if(a==0){
        x=0;
        y=1;
        return b;
    }
    int x2, y2;
    const int result = extended_euclid(b%a, a, x2, y2);

    y= x2;
    x = y2- (b/a) *x2;
    return result;
}

int main(){
    for(int i=0;i<10;i++){
        int a,b,c,d;
        cin >>a>>b>>c>>d;
        if(a==0 && c==0){
            swap(a,b);
            swap(c,d);
        }
        if(a<0){
            a *=-1;
            b *=-1;
        }
        if(c<0){
            c *=-1;
            d*=-1;
        }
        int p0,q0;
        const int GCD = extended_euclid(a, c, p0, q0);
        const int m = abs(a) + abs(b);
        int result = m;

        for (int target = m - (m% GCD); target >-m; target -= GCD){
            long long p = p0, q = q0;
            p *= (target/GCD);
            q *= (target/GCD);

            auto cur =  b*p + d*q;
            auto increment = ((long long)a*d - (long long)b*c)/GCD;
            if(increment){
                increment = abs(increment);
                cur = ((cur%increment)+increment)%increment;
                if(abs(cur-increment)<cur){
                    cur -= increment;
                }
            }
            if(target == 0 && cur ==0){
                if (increment ==0){
                    continue;
                }
                cur+= increment;
            }
            result = min<long long>(result, abs(target)+abs(cur));
        }
        cout << result <<'\n';
    }
}