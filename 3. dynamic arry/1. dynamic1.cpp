#include <iostream>
using namespace std;

int main()
{
    int* ptr = new int[3] {};
    ptr[0] = 10;
    ptr[1] = 20;

    delete [] ptr;
    ptr = nullptr;
}