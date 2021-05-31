#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int f(int a){
    a=abs(a);
    while(a/100!=0){
        a/=10;
    }
    return a;
}

int main()
{
    long long int a, b, count=0, max=0;
    cin >> a >> b;
    //cout << a << " " << b << endl;
    for(a;a<=b;a++){
        //cout << 1 << endl;
        int e=abs(a);
        int past=e%100;
        int end=f(a);
        int r=abs(end-past);
        if(r!=0){
            if(a%r==0){
                count++;
                max=a;
            }
        }
    }
    cout << count <<" " << max;
    return 0;
}
