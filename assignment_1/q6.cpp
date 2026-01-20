#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
    double x, y;
};

double dist(Point a, Point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool cmpX(Point a, Point b)
{
    return a.x < b.x;
}

bool cmpY(Point a, Point b)
{
    return a.y < b.y;
}

double bruteForce(vector<Point> &p, int l, int r)
{
    double mn = 1e18;
    for(int i = l; i <= r; i++)
        for(int j = i + 1; j <= r; j++)
            mn = min(mn, dist(p[i], p[j]));
    return mn;
}

double closestUtil(vector<Point> &p, int l, int r)
{
    if(r - l <= 3)
        return bruteForce(p, l, r);

    int mid = (l + r) / 2;
    double dl = closestUtil(p, l, mid);
    double dr = closestUtil(p, mid + 1, r);

    double d = min(dl, dr);

    vector<Point> strip;
    double midx = p[mid].x;

    for(int i = l; i <= r; i++)
        if(abs(p[i].x - midx) < d)
            strip.push_back(p[i]);

    sort(strip.begin(), strip.end(), cmpY);

    for(int i = 0; i < strip.size(); i++)
        for(int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; j++)
            d = min(d, dist(strip[i], strip[j]));

    return d;
}

int main()
{
    vector<Point> points = {
        {9,3}, {2,6}, {15,3}, {5,1}, {1,2}, {12,4}, {7,2}, {4,7},
        {16,5}, {3,3}, {10,5}, {6,4}, {14,6}, {8,6}, {11,1}, {13,2}
    };

    sort(points.begin(), points.end(), cmpX);

    double answer = closestUtil(points, 0, points.size() - 1);

    cout << "Minimum distance = " << answer << endl;

    return 0;
}
