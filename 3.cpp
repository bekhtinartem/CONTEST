#include <iostream>
#include <vector>
#include <fstream>
using namespace std;



int main()
{
    ifstream fin;
    fin.open("input.txt");
    string s;
    fin >> s;
    int max=-1;
    int k=0;
    vector<int> min_simbols(30, -1), max_simbols(30);
    for(int i=0;i<s.size();i++){
        if(min_simbols[int(s[i])-65]==-1){
            min_simbols[int(s[i])-65]=i;
        }else{
            max_simbols[int(s[i])-65]=i;
            if(i-min_simbols[int(s[i])-65]>=max){
                if(i-min_simbols[int(s[i])-65]==max){
                    if(int(s[i])-65<k){
                        max=i-min_simbols[int(s[i])-65];//>max;
                        k=int(s[i])-65;
                    }
                }else{
                    max=i-min_simbols[int(s[i])-65];//>max;
                    k=int(s[i])-65;
                }



            }
        }

    }
    if(max!=-1){
        cout << char(k+65) << " " << max-1 << endl;
    }else{
        cout << 0<< endl;
    }
    fin.close();
    return 0;
}


