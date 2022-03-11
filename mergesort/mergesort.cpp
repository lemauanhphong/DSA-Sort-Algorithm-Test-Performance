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

void merge(data_type arr[], int left, int mid, int right)
{
    int nleft = mid - left + 1, nright = right - mid;
    data_type *leftArr = new data_type[nleft], *rightArr = new data_type[nright];

    for (int i = 0; i < nleft; i++) leftArr[i] = arr[left + i];
    for (int  j = 0; j < nright; j++) rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left; 
    while (i < nleft && j < nright) 
    {
        if (leftArr[i] <= rightArr[j]) arr[k] = leftArr[i++];
        else arr[k] = rightArr[j++];
        k++;
    }
    
    while (i < nleft) 
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < nright) 
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergesort(data_type arr[], int begin, int end)
{
    if (begin >= end) return; 
    auto mid = begin + (end - begin) / 2;
    mergesort(arr, begin, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

void check()
{
    for (int i = 1; i < n; ++i)
        if (a[i] < a[i - 1])
        {
            cout << "[!] Bug in mergesort";
            exit(0);
        }
}

int main()
{
    cout << "mergesort.cpp\n";
    freopen("./input", "r", stdin);
    double sum = 0;
    for (int i = 0; i < 10; ++i)
    {
        cout << "Test " << i << ": ";
        input();
        clock_t start = clock();
        mergesort(a, 0, n - 1);
        double time = (double)(clock() - start) * 1000 / CLOCKS_PER_SEC;
        check();
        cout << setprecision(3) << fixed << time << "ms\n";
        sum += time;
    }
    cout << setprecision(3) << fixed << "Average: " << sum / 10 << "ms\n";
    cout << "\n\n";
    return 0;
}