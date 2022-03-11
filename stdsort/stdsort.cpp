#include <bits/stdc++.h>
#define data_type double

using namespace std;

const int MAXN = 1e6 + 7;

int n;
data_type a[MAXN];

void input()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];    
}

void stdsort(data_type arr[], int n)
{
    sort(arr, arr + n);
}

void check()
{
    for (int i = 1; i < n; ++i)
        if (a[i] < a[i - 1])
        {
            cout << "[!] Bug in stdsort";
            exit(0);
        }
}

int main()
{
    cout << "stdsort.cpp\n";
    freopen("./input", "r", stdin);
    double sum = 0;
    for (int i = 0; i < 10; ++i)
    {
        cout << "Test " << i << ": ";
        input();
        clock_t start = clock();
        stdsort(a, n);
        double time = (double)(clock() - start) * 1000 / CLOCKS_PER_SEC;
        check();
        cout << setprecision(3) << fixed << time << "ms\n";
        sum += time;
    }
    cout << setprecision(3) << fixed << "Average: " << sum/10 << "ms\n";
    cout << "\n\n";
    return 0;
}