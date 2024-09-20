#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

int T, n;
class Task {
public:
    int ddl;
    long long price;
    bool operator< (const Task& t) const {
        return ddl > t.ddl;
    }
};
Task tasks[N];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d%lld", &tasks[i].ddl, &tasks[i].price);
        sort(tasks + 1, tasks + n + 1);
        priority_queue<int> pq;
        long long ans = 0;
        int i = 1;
        int tmp = tasks[1].ddl;
        tasks[n + 1].ddl = -1;
        while (tmp > 0) {
            while (tasks[i].ddl == tmp && i <= n)
                pq.push(tasks[i++].price);
            while (!pq.empty() && tmp) {
                ans += pq.top();
                pq.pop();
                --tmp;
                if (tmp == tasks[i].ddl) break;
            }
            tmp = tasks[i].ddl;
        }
        printf("%lld\n", ans);
    }
    return 0;
}