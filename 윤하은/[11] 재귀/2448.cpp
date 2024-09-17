//240105
//BOJ 2448 별 찍기 - 11
//GOLD 4
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<vector<bool>> triangle;
void drawTriangle(int &n, pair<int, int>& vertex)
{
    int row = vertex.first;
    int col = vertex.second;

    if(n == 3)
    {
        //cout << "(" << row << ", " << col << ")\n";
        triangle[row][col] = true;
        triangle[row+1][col-1] = true;
        triangle[row+1][col+1] = true;
        for(int i = -2; i<3; i++)
            triangle[row+2][col+i] = true;
        return;
    }
    else
    {
        int childN = n/2;
        pair<int, int> newPos = make_pair(row, col);
        drawTriangle(childN, newPos);

        newPos = make_pair(row + childN, col - childN);
        drawTriangle(childN, newPos);

        newPos.second = col + childN;
        drawTriangle(childN, newPos);
    }
}
void printTriangle(int& n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n*2; j++)
        {
            if(triangle[i][j]) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    triangle = vector<vector<bool>>(n+10, vector<bool>(n*2+10, false));
    pair<int, int> startPos = make_pair(0, n-1);
    
    drawTriangle(n, startPos);
    printTriangle(n);
}