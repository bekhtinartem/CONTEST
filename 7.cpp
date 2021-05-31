#include <iostream>
#include <vector>

using namespace std;



int main()
{
    int n, start=0, end;
    cin >> n ;

    vector<vector<int > > matrix(n, vector<int>(n)), matrix_m(n, vector<int>(n)), new1(n, vector<int>(n));
    int k;
    cin >> end>> k ;
    end--;
    for(int i=0;i<k;i++){
        int a, b, l, m;
        cin >> a >> b >> l >>m;
        a--;\
        b--;
        matrix[a][b]=l;
        matrix[b][a]=l;
        matrix_m[a][b]=m;
        matrix_m[b][a]=m;
    }
    new1=matrix;
    int m1, m2;
    cin >> m1 >> m2;
    int m=m1+m2;
    int min_m=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k1=0;k1<n;k1++){
                if(new1[i][k1]!=0 && new1[k1][j]!=0){
                    if((new1[i][j]>new1[i][k1]+new1[k1][j] || (new1[i][j]==0) && (matrix_m[i][k1]>m && matrix[k1][j]>m))){


                        new1[i][j]=new1[i][k1]+new1[k1][j];
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << new1[i][j] << " ";
        }
        cout << endl;
    }
    if(new1[start][end]){
        cout << new1[start][end];
    }else{
        cout << -1;
    }
    return 0;
}

