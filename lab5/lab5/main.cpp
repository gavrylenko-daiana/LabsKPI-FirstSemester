#include <iostream>

using namespace std;

int main()
{
    for (int i = 22200; i <= 22299; i++)
    {
        if (i % 15 == 0)
        {
            cout << i << endl;
        }
    }
    
    return 0;
}
