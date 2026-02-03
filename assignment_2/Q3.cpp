// You are given N items, where each item has a value and a weight. You are also given a knapsack with a maximum capacity W. Unlike the 0/1 Knapsack problem, you are allowed to take fractions of an item. Write a program to maximize the total value in the knapsack without exceeding its capacity.
// E.g.:
// Input:
// N = 3
// value = [100, 60, 120]
// weight = [20, 10, 40]
// W = 50
// Output:
// Maximum value = 220

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure for item
struct Item {
    int value;
    int weight;
    double ratio;
};

// Comparator: sort by value/weight ratio (descending)
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {

    int N = 3;

    int value[] = {100, 60, 120};
    int weight[] = {20, 10, 40};

    int W = 50;   // Capacity

    vector<Item> items;

    // Store items with ratio
    for (int i = 0; i < N; i++) {
        Item it;
        it.value = value[i];
        it.weight = weight[i];
        it.ratio = (double)value[i] / weight[i];

        items.push_back(it);
    }

    // Sort by ratio
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;
    int capacity = W;

    // Fill knapsack
    for (int i = 0; i < N; i++) {

        // If full item fits
        if (items[i].weight <= capacity) {

            maxValue += items[i].value;
            capacity -= items[i].weight;
        }
        // Take fraction
        else {

            double fraction =
                (double)capacity / items[i].weight;

            maxValue += items[i].value * fraction;
            break;
        }
    }

    cout << "Maximum value = " << maxValue << endl;

    return 0;
}
