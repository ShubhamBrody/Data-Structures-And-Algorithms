#include<bits/stdc++.h>
using namespace std;

vector<int> A{5,4,3,2,1,0,-4,-1,-6,12};
int n = A.size()-1;

void bubblesort()
{
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++)
            if(A[i] > A[j])
            swap(A[i], A[j]);
    }
}

void selectionsort()
{
    int min;
    for(int i = 0; i < n-1; i++){
        min = i;
        for(int j = i+1; j < n; j++)
            if(A[min] > A[j])
            min = j;
        swap(A[min], A[i]);
    }
}

void insertionsort()
{
    for(int i = 0; i < n; i++)
    {
        int temp = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > temp)
        {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = temp;
    }
}

void merger(int l, int mid, int h)
{
    vector<int> L, R;
    for(int i = l; i <= mid; i++){
        L.push_back(A[i]);
    }

    for(int i = mid+1; i <= h; i++){
        R.push_back(A[i]);
    }

    int i = 0, j = 0;
    int k = l;

    while(i < L.size() && j < R.size())
    {
        if(L[i] < R[j])
        {
            A[k++] = L[i++];
        }
        else
        {
            A[k++] = R[j++];
        }
    }
    
    while(i < L.size())
    A[k++] = L[i++];

    while(j < R.size())
    A[k++] = R[i++];
}
void mergesort(int l = 0, int h = n-1)
{
    if(l >= h)
    return;
    
    int mid = (h+l)/2;

    mergesort(l, mid);
    mergesort(mid+1, h);
    merger(l, mid, h);
}

int partition(int l, int r)
{
    // int pivot = A[r];
    int i = l-1;

    for(int j = l; j < r; j++)
    {
        if(A[j] < A[r])
        {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i+1], A[r]);
    return i+1;
}
void quicksort(int l = 0, int h = n-1)
{
    if(l>=h)
    return;
    int pivot = partition(l, h);
    quicksort(l, pivot-1);
    quicksort(pivot+1, h);
}

void heapify(int l, int i)
{
    int c1 = 2*i+2, c2 = 2*i+1;
    int max = i;
    if(c1 < l && A[c1] > A[max])
    {
        max = c1;
    }
    if(c2 < l && A[c2] > A[max])
    {
        max = c2;
    }
    if(max != i)
    {
        swap(A[max], A[i]);
        heapify(l, max);
    }
}

void insertinheap(int i)
{
    int par = i/2;
    if(par >= 0 && A[par] < A[i])
    {
        swap(A[i], A[par]);
        insertinheap(par);
    }
}

void buildheap(int l)
{
    for(int i = l/2-1; i >= 0; i--)
    {
        heapify(l, i);
    }
}

void extract(int l)
{
    swap(A[0], A[l]);
    heapify(l, 0);
}

void heapsort()
{
    buildheap(n);
    // int k = n-1;
    // while(k)
    // {
    //     extract(k);
    //     k--;
    // }
}

int main()
{
    // bubblesort();
    // selectionsort();
    // insertionsort();
    // mergesort();
    // quicksort();
    heapsort();
    for(int &k : A) cout << k << " ";
    n++;
    insertinheap(n-1);
    for(int &k : A) cout << k << " ";
}