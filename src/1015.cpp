#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

int n;
class Building {
public:
    int left, right, height;
    // bool operator< (const Building &b) const;
    bool operator> (const Building &b) const;
    Building();
    Building(int l, int r, int h);
};

priority_queue<Building, vector<Building>, greater<Building> > pq;

int main() {
    cin >> n;
    for (int i = 1, l, r, h; i <= n; i++) {
        // cin >> buildings[i].left >> buildings[i].right >> buildings[i].height;
        cin >> l >> r >> h;
        pq.push(Building(l, r, h));
    }
    // while (!pq.empty()) {
    //     cout << pq.top().left << "  " << pq.top().right << "\n";
    //     pq.pop();
    // }
    vector<Building> answer;
    Building curr = pq.top();
    pq.pop();
    while (!pq.empty()) {
        Building tmp = pq.top();
        pq.pop();
        if (tmp.left >= curr.right) {
            answer.push_back(Building(curr));
            if (tmp.left > curr.right) {
                answer.push_back(Building(curr.right, tmp.left, 0));
            }
            curr = tmp;
            continue;
        }
        if (tmp.right <= curr.right) {
            if (tmp.height <= curr.height) continue;
            // case: tmp.height > curr.height
            answer.push_back(Building(curr.left, tmp.left, curr.height));
            if (tmp.right < curr.right) {
                answer.push_back(Building(tmp));
                curr.left = tmp.right;
            } else {
                curr = tmp;
            }
            continue;
        }
        // case (partial overlap): tmp.left < curr.left && tmp.right > curr.right
        if (tmp.height == curr.height) {
            curr.right = tmp.right;
        } else if (tmp.height > curr.height) {
            answer.push_back(Building(curr.left, tmp.left, curr.height));
            curr = tmp;
        } else {
            pq.push(Building(curr.right, tmp.right, tmp.height));
        }
    }
    answer.push_back(curr);
    answer.push_back(Building(curr.right, curr.right + 1, 0));
    for (Building b : answer) {
        cout << b.left << " " << b.height << "\n";
    }
    return 0;
}

// bool Building::operator< (const Building &b) const {
//     if (left == b.left) {
//         return height > b.height;
//     }
//     return left < b.left;
// }

bool Building::operator> (const Building &b) const {
    if (left == b.left) {
        return height < b.height;
    }
    return left > b.left;
}

Building::Building() : left(-1), right(-1), height(0) {};
Building::Building(int l, int r, int h) : left(l), right(r), height(h) {};
