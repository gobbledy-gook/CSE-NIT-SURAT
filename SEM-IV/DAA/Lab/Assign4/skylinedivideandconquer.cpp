#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<pair<int, int> > findSkyline(vector<vector<int>>& buildings, int left, int right) {
    if (left == right) {
        return {{buildings[left][0], buildings[left][2]}, {buildings[left][1], 0}};
    }
    int mid = (left + right) / 2;
    vector<pair<int, int> > leftSkyline = findSkyline(buildings, left, mid);
    vector<pair<int, int> > rightSkyline = findSkyline(buildings, mid + 1, right);
    vector<pair<int, int> > skyline;
    int leftHeight = 0, rightHeight = 0;
    int i = 0, j = 0;
    while (i < leftSkyline.size() && j < rightSkyline.size()) {
        if (leftSkyline[i].first < rightSkyline[j].first) {
            int x = leftSkyline[i].first;
            int height = max(leftSkyline[i].second, rightHeight);
            if (height != leftHeight) {
                skyline.push_back({x, height});
                leftHeight = height;
            }
            i++;
        } else if (leftSkyline[i].first > rightSkyline[j].first) {
            int x = rightSkyline[j].first;
            int height = max(rightSkyline[j].second, leftHeight);
            if (height != rightHeight) {
                skyline.push_back({x, height});
                rightHeight = height;
            }
            j++;
        } else {
            int x = leftSkyline[i].first;
            int height = max(leftSkyline[i].second, rightSkyline[j].second);
            if (height != leftHeight || height != rightHeight) {
                skyline.push_back({x, height});
                leftHeight = height;
                rightHeight = height;
            }
            i++;
            j++;
        }
    }
    while (i < leftSkyline.size()) {
        skyline.push_back(leftSkyline[i++]);
    }
    while (j < rightSkyline.size()) {
        skyline.push_back(rightSkyline[j++]);
    }
    return skyline;
}

int main() {
    vector<vector<int> > buildings = {{33, 41, 5},{4, 9, 21},{30, 36, 9},{14, 18, 11},{2, 12, 14},{34, 43, 19},{23, 25, 8},{14, 21, 16},{32, 37, 12},{7, 16, 7},{24, 27, 10}};
    auto skyline = findSkyline(buildings, 0, buildings.size() - 1);
    for (int i=0;i<skyline.size(); i++) {
        cout << "(" << skyline[i].first << ", " << skyline[i].second << ") ";
    }
    cout << endl;
    return 0;
}
