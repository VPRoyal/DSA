#include <iostream>
#include <chrono>

using namespace std;

int main() {
    // Record the start time before code execution
    auto start = chrono::high_resolution_clock::now();

    // Code block whose execution time you want to measure
    long long sum = 0;
    for (int i = 2; i < 10000000; i*=i) {
        sum += i;
        cout<<sum<<endl;
    }

    // Record the end time after code execution
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration in milliseconds
    chrono::duration<double, milli> duration_ms = end - start;

    // Output the execution time in milliseconds
    cout << "Time taken: " << duration_ms.count() << " milliseconds." << endl;

    return 0;
}
