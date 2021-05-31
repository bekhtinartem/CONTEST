#include <iostream>
#include <vector>

using namespace std;
void gorizontal(vector<vector<int> > matrix, vector<vector<int> > &out, int x, int y, int m, int n, int k, int p);
void vertical(vector<vector<int> > matrix, vector<vector<int> > &out, int x, int y, int m, int n, int k, int p){
    out[y][x]=p;
    for(int i=x+1;i<m;i++){
        if(matrix[y][i]==k){
            out[y][i]=p;
            gorizontal(matrix, out, i, y, m, n, k, p);
        }else{
            break;
        }
    }
    for(int i=x-1;i>=0;i--){
        if(matrix[y][i]==k){
            out[y][i]=p;
            gorizontal(matrix, out, i, y, m, n, k, p);
        }else{
            break;
        }
    }
}

void gorizontal(vector<vector<int> > matrix, vector<vector<int> > &out, int x, int y, int m, int n, int k, int p){
    out[y][x]=p;
    for(int i=y+1;i<n;i++){
        if(matrix[i][x]==k){
            out[i][x]=p;
            vertical(matrix, out, x, i, m, n, k, p);
        }else{
            break;
        }
    }
    for(int i=y-1;i>=0;i--){
        if(matrix[i][x]==k){
            out[i][x]=p;
            vertical(matrix, out, x, i, m, n, k, p);
        }else{
            break;
        }
    }
}

int main()
{
    int n, m;
    cin >>n >> m;
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    int p;
    cin >> p;
    vector<vector<int> > matrix(n, vector<int>(m)), out;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> matrix[i][j];
        }
    }
    out=matrix;
    out[y][x]=p;
    int k=matrix[y][x];
    vertical( matrix, out,  x,  y,  m,  n,  k,  p);
    gorizontal( matrix, out,  x,  y,  m,  n,  k,  p);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

