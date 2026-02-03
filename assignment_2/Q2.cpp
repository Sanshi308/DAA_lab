// Given the arrival and departure times of all trains reaching a railway station on the same day, write a program to determine the minimum number of platforms required so that no train has to wait for a platform. For each train, the arrival time is always different from its departure time, but the arrival time of one train may be equal to the departure time of another train. At any given instant, a single platform cannot be used simultaneously for the departure of one train and the arrival of another train; therefore, in such cases, separate platforms must be allocated. [Minimum Platforms | Practice Problems]
// Input:
// Train = [T1, T2, T3, T4, T5]
// AT = [09:00, 09:10, 09:20, 11:00, 11:20]
// DT = [09:40, 12:00, 09:50, 11:30, 11:40]
// Output:
// Minimum number of platforms required = 3

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Convert HH:MM to minutes
int toMinutes(string time) {
    int hour = stoi(time.substr(0, 2));
    int min = stoi(time.substr(3, 2));

    return hour * 60 + min;
}

int main() {

    int N = 5;

    vector<string> AT = {"09:00", "09:10", "09:20", "11:00", "11:20"};
    vector<string> DT = {"09:40", "12:00", "09:50", "11:30", "11:40"};

    vector<int> arr(N), dep(N);

    // Convert to minutes
    for (int i = 0; i < N; i++) {
        arr[i] = toMinutes(AT[i]);
        dep[i] = toMinutes(DT[i]);
    }

    // Sort arrival and departure
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platforms = 1;      // Current platforms
    int maxPlatforms = 1;   // Maximum platforms

    int i = 1;  // arrival pointer
    int j = 0;  // departure pointer

    while (i < N && j < N) {

  
        if (arr[i] <= dep[j]) {
            platforms++;
            i++;
        }
        
        else {
            platforms--;
            j++;
        }

        maxPlatforms = max(maxPlatforms, platforms);
    }

    cout << "Minimum number of platforms required = "
         << maxPlatforms << endl;

    return 0;
}
