#include <bits/stdc++.h>
using namespace std;

void magic_sq(vector<vector<int>> &v, int n)
{
    int i = n / 2;
    int j = n - 1;
    for (int k = 1; k <= n * n;)
    {
        if (v[i][j] == 0)
        {
            v[i][j] = k;
            k++;
            i--;
            j++;
        }
        if (i < 0 && j < n)
            i = n - 1;
        else if (i >= 0 && j == n)
            j = 0;
        else if (i < 0 || j == n)
        {
            i = 0;
            j = n - 2;
        }
        if (v[i][j] != 0)
        {
            i++;
            j = j - 2;
        }
    }
}

int main()
{
    for (int i = 3; i <= 30; i = i + 2)
    {
        ofstream file("data7.txt", ios::app);
        vector<vector<int>> mat(i, vector<int>(i, 0));
        double total_time = 0;
        for (int m = 1; m <=10; m++)
        {
            clock_t start = clock();
            magic_sq(mat, i);
            clock_t end = clock();
            total_time += end - start;

        }
        double duration = double(total_time) * (1000) / double(CLOCKS_PER_SEC);
        cout<<duration<<endl;
        if (file.is_open())
        {
            file << i << " " << duration / 10 << endl;
        }
    }
    return 0;
}
