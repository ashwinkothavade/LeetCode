#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Point {
        double x, y;
        bool operator<(const Point& p) const {
            return x < p.x || (x == p.x && y < p.y);
        }
    };

    // Cross product
    double cross(const Point& O, const Point& A, const Point& B) {
        return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    }

    // Convex hull (Monotone Chain)
    vector<Point> convexHull(vector<Point>& pts) {
        sort(pts.begin(), pts.end());
        int n = pts.size(), k = 0;
        vector<Point> hull(2*n);
        for (int i = 0; i < n; i++) {
            while (k >= 2 && cross(hull[k-2], hull[k-1], pts[i]) <= 0) k--;
            hull[k++] = pts[i];
        }
        for (int i = n-2, t = k+1; i >= 0; i--) {
            while (k >= t && cross(hull[k-2], hull[k-1], pts[i]) <= 0) k--;
            hull[k++] = pts[i];
        }
        hull.resize(k-1);
        return hull;
    }

    // Shoelace formula for triangle area
    double area(const Point& a, const Point& b, const Point& c) {
        return fabs((a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y)) / 2.0);
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        vector<Point> pts;
        for (auto &p : points) pts.push_back({(double)p[0], (double)p[1]});

        vector<Point> hull = convexHull(pts);
        int h = hull.size();
        double ans = 0.0;

        // Rotating calipers O(h^2)
        for (int i = 0; i < h; i++) {
            for (int j = i+1; j < h; j++) {
                int k = (j+1) % h;
                while (true) {
                    int nxt = (k+1) % h;
                    double cur = area(hull[i], hull[j], hull[k]);
                    double nxtArea = area(hull[i], hull[j], hull[nxt]);
                    if (nxtArea > cur) k = nxt;
                    else break;
                }
                ans = max(ans, area(hull[i], hull[j], hull[k]));
            }
        }

        return ans;
    }
};
