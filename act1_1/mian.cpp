#include <iostream>
#include <vector>
using namespace std;

void merge(vector<double>& arr, int left, int mid, int right) {
    vector<double> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] >= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
}

void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);

        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int N;
    cout << "Ingrese el número de valores a ordenar (N): ";
    cin >> N;

    if (N <= 0) {
        cout << "Debe ingresar un número mayor a 0." << endl;
        return 1;
    }

    vector<double> arr(N);
    cout << "Ingrese " << N << " valores (reales o enteros), uno por línea:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Número " << i + 1 << ": ";
        cin >> arr[i];
    }

    mergeSort(arr, 0, N - 1);

    cout << "Valores ordenados de mayor a menor:" << endl;
    for (double num : arr) {
        cout << num << endl;
    }

    return 0;
}