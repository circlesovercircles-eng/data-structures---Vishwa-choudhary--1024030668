#include <iostream>
using namespace std;

class Diagonal
{
    int *arr, n;

public:
    Diagonal(int size)
    {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = 0;
    }
    void set(int i, int j, int x)
    {
        if (i == j)
            arr[i - 1] = x;
    }
    int get(int i, int j)
    {
        if (i == j)
            return arr[i - 1];
        return 0;
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    cout << arr[i] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Diagonal d(4);
    d.set(1, 1, 5);
    d.set(2, 2, 8);
    d.set(3, 3, 3);
    d.set(4, 4, 6);
    cout << d.get(2,2)<< endl;
    d.display();
    return 0;
}
