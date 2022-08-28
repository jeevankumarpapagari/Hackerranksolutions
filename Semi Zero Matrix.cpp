#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> const &mat)
{
    for (auto &row: mat) {
        for (auto &i: row) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}
 

void changeRowColumn(vector<vector<int>> &mat, int x, int y)
{

    int M = mat.size();
    int N = mat[0].size();
 
    for (int j = 0; j < N; j++)
    {
        if (mat[x][j] != 0) {
            mat[x][j] = -1;
        }
    }
 
    for (int i = 0; i < M; i++)
    {
        if (mat[i][y] != 0) {
            mat[i][y] = -1;
        }
    }
}
 
void convert(vector<vector<int>> &mat)
{
    if (mat.size() == 0) {
        return;
    }
 
    int M = mat.size();
    int N = mat[0].size();
 
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j] == 0)            
            {
                changeRowColumn(mat, i, j);
            }
        }
    }
 

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j] == -1) {
                mat[i][j] = 0;
            }
        }
    }
}
 
int main()
{
    int r,c;
    cin >> r >> c;
    vector<vector<int>> mat;
    for (int i = 0; i < r; i++)
    {
 
        vector<int> v;
        for (int j = 0; j < c; j++) 
        {
            int value;
            cin >> value;
            v.push_back(value);
        }
  
        mat.push_back(v);
    }
    
 
    // convert the matrix
    convert(mat);
 
    // print matrix
    printMatrix(mat);
 
    return 0;
}
