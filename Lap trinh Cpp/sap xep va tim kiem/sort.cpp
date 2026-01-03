#include <bits/stdc++.h>
using namespace std;

// selection sort
void selection_sort(vector<int>& a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                min_pos = j;
        }
        swap(a[i], a[min_pos]);
    }
}
// bubble sort
void bubble_sort(vector<int>& a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}
// insertion sort
void insertion_sort(vector<int>& a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int pos = i - 1, val = a[i];
        while (pos >= 0 && a[pos] > val)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = val;
    }
}
// counting sort
void counting_sort(vector<int>& a)
{
    int k = *max_element(a.begin(), a.end());
    int n = a.size();
    vector<int> cnt(k + 1, 0);
    for (int i = 0; i < n; i++)
        cnt[a[i]]++;
    int idx = 0;
    for (int i = 0; i <= k; i++)
    {
        while (cnt[i]--)
            a[idx++] = i;
    }
}
// merge sort
void merge(vector<int>& a, int l, int m, int r)
{
    vector<int> x(m - l + 1), y(r - m);
    for (int i = 0; i < m - l + 1; i++)
        x[i] = a[l + i];
    for (int i = 0; i < r - m; i++)
        y[i] = a[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < m - l + 1 && j < r - m)
    {
        if (x[i] <= y[j])
        {
            a[k++] = x[i++];
        }
        else
        {
            a[k++] = y[j++];
        }
    }
    while (i < m - l + 1)
        a[k++] = x[i++];
    while (j < r - m)
        a[k++] = y[j++];
}

void merge2(vector<int>& a, int l, int m, int r)
{
    vector<int> temp;
    int i = l, j = m + 1;
    while (i <= m && j <= r)
        temp.push_back(a[i] <= a[j] ? a[i++] : a[j++]);
    while (i <= m) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);
    for (int k = 0; k < temp.size(); k++)
        a[l + k] = temp[k];
}

void merge_sort(vector<int>& a, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

bool naturalMergeSort(vector<int>& a)
{
    int n = a.size();
    bool sorted = true;
    int l = 0;
    while (l < n)
    {
        int m = l;
        while (m < n - 1 && a[m] <= a[m + 1])
            m++;
        if (m == n - 1)
            break;

        int r = m + 1;
        while (r < n - 1 && a[r] <= a[r + 1])
            r++;
        merge2(a, l, m, r);
        sorted = false;
        l = r + 1;
    }
    return sorted;
}

void natural_merge_sort(vector<int>& a)
{
    while (!naturalMergeSort(a));
}
// quick sort
int partition_lomuto(vector<int>& a, int l, int r)
{
    int random_pivot_idx = l + rand() % (r - l + 1);
    swap(a[r], a[random_pivot_idx]);
    int i = l - 1, j = l, pivot = a[r];
    while (j < r)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[j], a[i]);
        }
        j++;
    }
    i++;
    swap(a[r], a[i]);
    return i;
}

void quick_sort_lomuto(vector<int>& a, int l, int r)
{
    if (l < r)
    {
        int pos = partition_lomuto(a, l, r);
        quick_sort_lomuto(a, l, pos - 1);
        quick_sort_lomuto(a, pos + 1, r);
    }
}

int partiton_hoare(vector<int>& a, int l, int r)
{
    int i = l - 1, j = r + 1, pivot = a[(l + r) / 2];
    while (true)
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
            swap(a[i], a[j]);
        else 
            return j;
    }
}

void quick_sort_hoare(vector<int>& a, int l, int r)
{
    if (l < r)
    {
        int pos = partiton_hoare(a, l, r);
        quick_sort_hoare(a, l, pos);
        quick_sort_hoare(a, pos + 1, r);
    }
}
// heap sort
void heapify(vector<int>& a, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

void heap_sort(vector<int>& a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    srand(time(NULL));
    int n = rand() % 1000;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 1000 + 1;
        a[i] = x;
    }
    // selection_sort(a);
    // bubble_sort(a);
    // insertion_sort(a);
    // counting_sort(a);
    // merge_sort(a, 0, n - 1);
    // natural_merge_sort(a);
    // quick_sort_lomuto(a, 0, n - 1);
    quick_sort_hoare(a, 0, n - 1);
    // heap_sort(a, n);
    for (int x : a)
        cout << x << " ";
    return 0;
}