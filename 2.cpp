#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int max=0;
int ke=0;
bool check1(int a){
    for(int i=2;i*i-1<a;i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}

bool check(int a){
    if(a%3==0 || a%7==0){
        if(a%3==0){
            int t=a/3;
            for(int y=13;y<100;y+=10){
                if(check1(y)){
                    if(t%y==0){

                        t/=y;
                        if(t%10==3){
                            if(check1(t)){

                                if(t-3>::max){
                                    ::max=(a/y)/3-3;
                                    ::ke=a;
                                }
                                return 1;
                            }
                        }
                    }
                    break;
                }

            }
        }else{
            int t=a/7;
            for(int y=17;y<100;y+=10){
                if(check1(y)){
                    if(t%y==0){

                        t/=y;
                        if(t%10==7){
                            if(check1(t)){

                                if(t-7>::max){
                                    ::max=(a/y)/7-7;
                                    ::ke=a;
                                }
                                return 1;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }else{
        return 0;
    }
    return 0;
}

int main()
{
    long long int a, b, count=0, max=0;
    cin >> a >> b;
    if(a%2==0){
        a+=1;
    }
    for(a;a<=b;a+=2){
        if(check(a)){
            count++;
            max=a;
        }
    }
    cout << count <<" " << ::ke;//536792 604298
    return 0;
}
