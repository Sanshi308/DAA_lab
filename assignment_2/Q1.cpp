// You are given N activities, each having a start time and a finish time. A single person (or machine) can perform only one activity at a time. Two activities are said to be compatible if the start time of one activity is greater than or equal to the finish time of the other activity. Write a program using greedy strategy to select the maximum number of non-overlapping activities that can be performed by the person.
// E.g.:
// Input:
// N = 6
// start = [1, 3, 0, 5, 8, 5]
// finish = [2, 4, 6, 7, 9, 9]
// Output:
// Maximum number of activities = 4
// Selected activities: (1, 2), (3, 4), (5, 7), (8, 9)


Ans:-

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store activity
struct Activity {
    int start;
    int finish;
};

// Comparator: sort by finish time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int N = 6;

    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    vector<Activity> activities;

    // Store activities
    for (int i = 0; i < N; i++) {
        activities.push_back({start[i], finish[i]});
    }

    // Sort by finish time
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected activities: ";

    // First activity is always selected
    int count = 1;
    int lastFinish = activities[0].finish;

    cout << "(" << activities[0].start << ", "
         << activities[0].finish << ") ";

    // Select remaining activities
    for (int i = 1; i < N; i++) {

        if (activities[i].start >= lastFinish) {

            cout << "(" << activities[i].start << ", "
                 << activities[i].finish << ") ";

            lastFinish = activities[i].finish;
            count++;
        }
    }

    cout << endl;
    cout << "Maximum number of activities = " << count << endl;

    return 0;
}
