// PKP
#include <bits/stdc++.h>
#include <iomanip>
#define ll long long
#define rep(i, n) for(i=0;i<n;i++)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deba(i, a, n) for(i=0;i<n;i++){cout << a[i] << " ";}
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define N 9
using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;





bool isSafe(int puzzle[N][N], int row, int col, int num)
{
   for (ll i = 0; i <= 8; i++)
      if (puzzle[row][i] == num)
         return false;

   for (ll x = 0; x <= 8; x++)
      if (puzzle[x][col] == num)
         return false;

   int startRow = row - row % 3,
       startCol = col - col % 3;

   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
         if (puzzle[i + startRow][j +
                                  startCol] == num)
            return false;

   return true;
}


bool solve(int puzzle[N][N], int row, int col)
{

   if (row == N - 1 && col == N)
      return true;


   if (col == N) {
      row++;
      col = 0;
   }

   if (puzzle[row][col] > 0)
      return solve(puzzle, row, col + 1);

   for (int num = 1; num <= N; num++)
   {


      if (isSafe(puzzle, row, col, num))
      {

         puzzle[row][col] = num;
         if (solve(puzzle, row, col + 1))
            return true;
      }

      puzzle[row][col] = 0;
   }
   return false;
}

// Driver Code
int main()
{
   int puzzle[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
      { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
      { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
      { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
      { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
      { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
      { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
   };

   if (solve(puzzle, 0, 0))
      for (int i = 0; i < N; i++)
      {
         for (int j = 0; j < N; j++)
            cout << puzzle[i][j] << " ";
         cout << endl;
      }

   else
      cout << "error " << endl;

   return 0;

}
