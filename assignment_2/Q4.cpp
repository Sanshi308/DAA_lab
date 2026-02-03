// Given two arrays deadline[ ] and profit[ ], where deadline[i] represents the last time unit by which the i-th job must be completed, and profit[i] represents the profit earned from completing it. Each job takes exactly 1 unit of time, and only one job can be scheduled at a time. Write a program to schedule the jobs in such a way that the total profit is maximized while ensuring that each selected job is completed on or before its deadline. Find the number of jobs completed and maximum profit.
// E.g.:
// Input:
// N = 5
// Jobs = [J1, J2, J3, J4, J5]
// deadline = [2, 1, 2, 1, 3]
// profit = [100, 19, 27, 25, 15]
// Output:
// Selected Jobs: [J1, J3, J5]
// Maximum Profit = 142

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure for Job
struct Job {
    string id;
    int deadline;
    int profit;
};

// Comparator: sort by profit (descending)
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {

    int N = 5;

    vector<string> jobs = {"J1", "J2", "J3", "J4", "J5"};
    int deadline[] = {2, 1, 2, 1, 3};
    int profit[]   = {100, 19, 27, 25, 15};

    vector<Job> arr;

    // Store job info
    for (int i = 0; i < N; i++) {
        arr.push_back({jobs[i], deadline[i], profit[i]});
    }

    // Sort by profit
    sort(arr.begin(), arr.end(), compare);

    // Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < N; i++) {
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }

    // Slot array
    vector<string> slot(maxDeadline + 1, "");

    int totalProfit = 0;
    int count = 0;

    // Schedule jobs
    for (int i = 0; i < N; i++) {

        // Try to find free slot from deadline to 1
        for (int j = arr[i].deadline; j > 0; j--) {

            if (slot[j] == "") {

                slot[j] = arr[i].id;
                totalProfit += arr[i].profit;
                count++;
                break;
            }
        }
    }

    // Print selected jobs
    cout << "Selected Jobs: [";

    bool first = true;
    for (int i = 1; i <= maxDeadline; i++) {

        if (slot[i] != "") {

            if (!first) cout << ", ";
            cout << slot[i];
            first = false;
        }
    }

    cout << "]" << endl;

    cout << "Maximum Profit = " << totalProfit << endl;

    return 0;
}
