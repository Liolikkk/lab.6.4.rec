#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

static void Init(double* b, const int n, int i = 0) {
    if (i < n) {
        b[i] = -10 + rand() % 21;
        Init(b, n, i + 1);
    }
}

static void Print(const double* const b, const int n, int i = 0) {
    if (i == 0) cout << "{ ";
    if (i < n) {
        cout << fixed << setprecision(0) << b[i] << " ";
        Print(b, n, i + 1);
    }
    else {
        cout << "}" << endl;
    }
}

// нулі
static int CountZeros(const double* const b, const int n, int i = 0, int count = 0) {
    if (i < n) {
        if (b[i] == 0) count++;
        return CountZeros(b, n, i + 1, count);
    }
    return count;
}

//після мінімального
static double SumAfterMin(const double* const b, const int n, int i = 0, int minIndex = 0) {
    if (i < n) {
        if (b[i] < b[minIndex]) minIndex = i;
        return SumAfterMin(b, n, i + 1, minIndex);
    }
    double sum = 0;
    for (int j = minIndex + 1; j < n; j++) {
        sum += b[j];
    }
    return sum;
}

// за зростанням
static void SortOddIndexedElements(double* b, const int n, int i = 1, vector<double>* oddElements = nullptr) {
    if (oddElements == nullptr) {
        oddElements = new vector<double>();
    }

    // непарнi
    if (i < n) {
        oddElements->push_back(b[i]);
        SortOddIndexedElements(b, n, i + 2, oddElements);
    }
    else {
        
        (oddElements->begin(), oddElements->end(), [](double a, double b) {
            return abs(a) < abs(b);
            });

        
        int j = 0;
        for (int k = 1; k < n; k += 2) {
            b[k] = (*oddElements)[j++];
        }

        delete oddElements; 
    }
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter the size of the array n = "; cin >> n;
    double* arr = new double[n];
    Init(arr, n);

    cout << "Initial array:" << endl;
    Print(arr, n);

    cout << "Number of zero elements: " << CountZeros(arr, n) << endl;

    cout << "Sum of elements after minimum element: " << SumAfterMin(arr, n) << endl;

    SortOddIndexedElements(arr, n);
    cout << "Array after sorting odd indexed elements by modulus:" << endl;
    Print(arr, n);

    delete[] arr;
    arr = nullptr;
    return 0;
}
