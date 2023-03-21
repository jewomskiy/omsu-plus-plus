#include <iostream>

using namespace std;

class Array
{
private:
    float *arr;
    int N;
public:
    Array() //default
    {
        N = 1;
        arr = new float[N];
        for (int i = 0; i<N; i++) arr[i] = 0;
    }
    Array(int n) //by size
    {
        N = n;
        arr = new float[N];
        for (int i = 0; i<N; i++) arr[i] = 0;
    }

    Array(int size, int n) //by size
    {
        N = n;
        arr = new float[N];
        for (int i = 0; i<N; i++) arr[i] = n;
    }

    Array (const Array & source) //copy
    {
        N = source.N;
        arr = new float[N];
        for (int i = 0; i<N; i++)
            arr[i] = source.arr[i];
    }

    ~Array()
    {
        delete[]arr;
    }
    int getsize()
    {
        return N;
    }

    void print()
    {
        for (int i = 0; i<N; i++)
            cout << arr[i] << "  ";
        cout << endl;
    }

    void set()
    {
        srand(time(0));
        for (int i = 0; i<N; i++)
            arr[i] = rand() % 100;
    }


    void sort()
    {
        int temp;
        for (int i = 0; i<N; i++)
        {
            temp = arr[i];
            for (int j = i; j<N; j++)
                if (temp>arr[j])
                {
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
        }
    }
    int max()
    {
        sort();
        return arr[N - 1];
    }
    int min()
    {
        sort();
        return arr[0];
    }
};