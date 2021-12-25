#include <bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &A)
{
    int N = A.size();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                A[j] ^= A[j + 1];
                A[j + 1] ^= A[j];
                A[j] ^= A[j + 1];
            }
        }
    }
}

void selectionsort(vector<int> &A)
{
    int N = A.size(), min;

    for (int i = 0; i < N - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < N; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        if (min == i)
            continue;
        A[i] ^= A[min];
        A[min] ^= A[i];
        A[i] ^= A[min];
    }
}

void insertionsort(vector<int> &A)//wrong
{
    int N = A.size();

    for (int i = 1; i < N; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (A[j] < A[j - 1])
            {
                A[j] ^= A[j - 1];
                A[j - 1] ^= A[j];
                A[j] ^= A[j - 1];
            }
        }
    }
}

//helper function for mergesort
void merger(vector<int> &A, int l, int mid, int r)
{
    vector<int> L, R;
    for (int i = l; i <= mid; i++)
    {
        L.push_back(A[i]);
    }

    for (int j = mid + 1; j <= r; j++)
    {
        R.push_back(A[j]);
    }

    int i = 0, j = 0, k = l;

    while (i < L.size() && j < R.size())
    {
        if (L[i] <= R[i])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < L.size())
    {
        A[k++] = L[i++];
    }

    while (j < R.size())
    {
        A[k++] = R[j++];
    }
}

void mergesort(vector<int> &A, int l, int r)
{
    if (l >= r)
        return;

    int mid = (r + l) / 2;

    mergesort(A, l, mid);
    mergesort(A, mid + 1, r);
    merger(A, l, mid, r);
}

//Helper function for quicksort
int partition(vector<int> &A, int l, int r)
{
    int pivot = A[l];
    int i = l, j = r;

    while (i < j)
    {
        do
        {
            i++;
        } while (A[i] <= pivot);

        do
        {
            j--;
        } while (A[j] > pivot);

        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    A[l] += A[j];
    A[j] = A[l] - A[j];
    A[l] -= A[j];

    for (auto i : A)
    {
        cout << i << " ";
    }
    cout << endl << endl;

    return j;
}

void quicksort(vector<int> &A, int l, int r)
{
    if (l < r)
    {
        int p = partition(A, l, r);
        quicksort(A, l, p);
        quicksort(A, p + 1, r);
    }
}

void heapify(vector<int> &A)
{
}

void heapsort(vector<int> &A)
{
}

int main()
{
    int N;
    cout << "\t*****IMPLEMENTATION OF ALL SORTING ALGORITHMS*****" << endl;
    cout << "Enter the number of elements : ";
    cin >> N;

    vector<int> A;
    cout << "Enter the elements : \n";
    for (int i = 0; i < N; i++)
    {
        cout << i << " - ";
        int t;
        cin >> t;
        A.push_back(t);
        cout << endl;
    }

    // bubblesort(A);
    // selectionsort(A);
    // insertionsort(A);
    // mergesort(A, 0, A.size() - 1);
    // quicksort(A, 0, A.size());
    // heapsort(A);

    cout << "Converted Array : \n";

    for (auto i : A)
    {
        cout << i << endl;
    }
}