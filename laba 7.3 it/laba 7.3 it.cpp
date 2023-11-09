#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void New(int** a, int n);
int Sum(int** a, int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -30;
    int High = -1;
    int n;
    cout << "n = "; cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    Create(a, n, Low, High);
    Print(a, n);

    New(a, n);
    Print(a, n);

    int s = Sum(a, n);

    cout << "Sum = " << s << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = static_cast<double>(Low + rand() % (High - Low + 1));
}
void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void New(int** a, int n)
{
    int** Matrix = new int* [n];
    for (int i = 0; i < n; i++)
        Matrix[i] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0;
            int count = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int newRow = i + x;
                    int newCol = j + y;

                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n)
                    {
                        sum += a[newRow][newCol];
                        count++;
                    }
                }
            }
            Matrix[i][j] = sum / count;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Matrix[i][j];

    for (int i = 0; i < n; i++)
        delete[] Matrix[i];
    delete[] Matrix;
}

int Sum(int** a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i > j)
                sum += fabs(a[i][j]);
    return sum;
}
