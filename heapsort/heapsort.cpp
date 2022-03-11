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

void heapify(data_type arr[], int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(data_type arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void check()
{
    for (int i = 1; i < n; ++i)
        if (a[i] < a[i - 1])
        {
            cout << "[!] Bug in heapsort";
            exit(0);
        }
}

int main()
{
    cout << "heapsort.cpp\n";
    freopen("./input", "r", stdin);
    double sum = 0;
    for (int i = 0; i < 10; ++i)
    {
        cout << "Test " << i << ": ";
        input();
        clock_t start = clock();
        heapsort(a, n);
        double time = (double)(clock() - start) * 1000 / CLOCKS_PER_SEC;
        check();
        cout << setprecision(3) << fixed << time << "ms\n";
        sum += time;
    }
    cout << setprecision(3) << fixed << "Average: " << sum / 10 << "ms\n";
    cout << "\n\n";
    return 0;
}