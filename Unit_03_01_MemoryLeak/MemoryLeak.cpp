#include <iostream>
#include <thread>
#include <chrono>
#include <vector>


using namespace std;

int main()
{
    cout << "Demo: Memory Leak vs Fix" << endl;
    vector<char *> leakStorage; // Only used in the LEAK version

    int counter = 0;
    while (true)
    {
        // Memory Leak
        // char* data = new char[1024 * 1024]; // Allocate ~1 MB
        // leakStorage.push_back(data);        // Keep it -> never freed

        // using delete[]
         char *data = new char[1024 * 1024];   // Allocate ~1 MB
         delete[] data;                        // Free memory immediately -> no leak


        cout << "Allocated ~1 MB, iteration " << ++counter << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
