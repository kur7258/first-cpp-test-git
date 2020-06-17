#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int x = 0;
    int y = 0;

    for (x = -3; x <= 3; ++x) {
        int fx = x * x + 1;
        for (y = 0; y < fx; ++y)
            cout << " ";
        cout << "*" << endl;
    }
    return 0;
}