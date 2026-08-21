#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_vec(vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

void s_sort(vector<int>& a, int& n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }

        if (min != i) {
            swap(a[i], a[min]);
        }
    }

    print_vec(a);
}

// ---------------- MERGE SORT ----------------

void merge(vector<int>& a, int low, int mid, int high) {
    vector<int> temp;

    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(a[i]);
        i++;
    }

    while (j <= high) {
        temp.push_back(a[j]);
        j++;
    }


    for (int k = 0; k < temp.size(); k++) {
        a[low + k] = temp[k];
    }
}

void merge_sort(vector<int>& a, int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = low + (high - low) / 2;

    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);

    merge(a, low, mid, high);
}

void m_sort(vector<int>& a, int& n) {
    merge_sort(a, 0, n - 1);
    print_vec(a);
}

// ---------------- QUICK SORT ----------------

int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);

    return i + 1;
}

void quick_sort(vector<int>& a, int low, int high) {
    if (low >= high) {
        return;
    }

    int pivotIndex = partition(a, low, high);

    quick_sort(a, low, pivotIndex - 1);
    quick_sort(a, pivotIndex + 1, high);
}

void q_sort(vector<int>& a, int& n) {
    quick_sort(a, 0, n - 1);
    print_vec(a);
}


int main() {

    vector<int> v = {42, 23, 52, 32, 65, 6454};
    int n = v.size();

    cout << "Selection Sort: ";
    s_sort(v, n);

    vector<int> v2 = {42, 23, 52, 32, 65, 6454};
    int n2 = v2.size();

    cout << "Merge Sort: ";
    m_sort(v2, n2);

    vector<int> v3 = {42, 23, 52, 32, 65, 6454};
    int n3 = v3.size();

    cout << "Quick Sort: ";
    q_sort(v3, n3);

    return 0;
}
