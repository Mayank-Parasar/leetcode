//
// Created by Mayank Parasar on 2020-03-29.
//

/*
Given a list of points, an interger k, and a point p, find the k closest points to p.

Here's an example and some starter code:

class Point:
  def __init__(self, x=0, y=0):
    self.x = x
    self.y = y

  def __repr__(self):
    return f"({self.x}, {self.y})"

def closest_points(points, k, p):
  # Fill this in.

points = [
    Point(0, 0),
    Point(1, 1),
    Point(2, 2),
    Point(3, 3),
]
print(closest_points(points, 2, Point(0, 2)))
# [(0, 0), (1, 1)]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myfunction(pair<int, pair<int, int>> a,
                pair<int, pair<int, int>> b) {
    return a.first < b.first;
}

vector<pair<int, int>> closest_points(vector<pair<int,int>> points,
                                      int num_points, pair<int, int> point) {
    vector<pair<int, int>> closest_pts;
    vector<int> distances;
    int x_distance;
    int y_distance;

    for(int ii=0; ii < points.size(); ii++) {
        x_distance = (point.first - points[ii].first) * (point.first - points[ii].first);
        y_distance = (point.second - points[ii].second) * (point.second - points[ii].second);
        distances.push_back(x_distance + y_distance);
    }

    // distance vector is in same order as order of points...
    // find the k smallest elements along with their indeces...

    // instead of map use pair...
    vector<pair<int, pair<int, int>>> distance_points_pair;
    for(int ii = 0; ii < distances.size(); ii++) {
        distance_points_pair.push_back(make_pair(distances[ii], points[ii]));
    }

    sort(distance_points_pair.begin(), distance_points_pair.end(), myfunction);

    for(int ii = 0; ii < num_points; ii++) {
        closest_pts.push_back(distance_points_pair[ii].second);
    }

    return closest_pts;
}


int main() {

    vector<pair<int,int>> points;

    points.push_back(make_pair(0, 0));
    points.push_back(make_pair(1, 1));
    points.push_back(make_pair(2, 2));
    points.push_back(make_pair(3, 3));

    pair<int, int> point;
    point = pair<int, int>(0, 2);

    int num_points = 3;

    vector<pair<int, int>> result =
            closest_points(points, num_points, point);

    for(int ii = 0; ii < result.size(); ii++) {
        cout << "(" << result[ii].first <<", "
             << result[ii].second << ")" << endl;
    }


    return 0;
}