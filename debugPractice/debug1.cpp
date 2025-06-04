#include <iostream>
using namespace std;
int *fun1(int *xptr, int *yptr, int *min);

int main()
{
    int x = 0, y = 0;
    cin >> x >> y;
    int *min = NULL;
    fun1(&x, &y, min);
    cout << *min << endl;
}

int *fun1(int *xptr, int *yptr, int *min)
{
    if (*xptr < *yptr)
    {
        min = xptr;
    }
    else
    {
        min = yptr;
    }
    return min;
}
