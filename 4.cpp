#include <iostream>
#include <vector>

using namespace std;
vector<string> out;

bool check(string s, int m){

    int count=0;
    for(int i =0;i<s.size();i++){
        if(s[i]=='A' || s[i] =='I'){
            count++;
            if(count>=m){
                return 1;
            }
        }
    }
    return 0;
}

void f(int n, int m, string abc,string s="", int height=0){
    if(height==n){
        if(check(s, m)){
            ::out.push_back(s);
        }
        return;
    }
    for(int i=0;i<abc.size();i++){
        string e=abc;
        //e.erase(i, 1);
        string k=s+abc[i];
        f(n,m, e, k, height+1);

    }
}


int main()
{
    string s="AFIN";
    int n, m, k;
    cin >>n >> m >> k;
    f(n, m, s);


    if(k<= ::out.size()){
        cout << ::out.size() << " " << ::out[k-1] << endl;
    }else{
        cout << "ERROR" << endl;
    }
    return 0;
}
