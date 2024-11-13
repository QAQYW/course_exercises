#include <bits/stdc++.h>
using namespace std;

const int MAX_VER_NUM = 50;

int T;

class Order {
public:
    Order() {}
    Order(int s, int d, int e, int l): st(s), des(d), ear(e), lst(l) {}
    int get_st() const;
    int get_des() const;
    int get_ear() const;
    int get_lst() const;
private:
    int st;  // 取餐地点
    int des; // 送达地点
    int ear; // 最早时间
    int lst; // 最晚时间
};

class Problem {
public:
    Problem() {}
    int get_stVer() const;
    int get_verNum() const;
    int get_stafNum() const;
    vector<Order> get_orders() const;
    vector< vector<double> > get_dis() const;
    void read_init();
    void shortest_path();
    // void data_clean();

private:
    int stVer; // initial vertex of staff
    int verNum;  // number of vertices
    int edgeNum; // number of edges
    int ordNum;  // number of orders
    int stafNum; // number of staff
    vector< vector<int> > dis; // distance
    vector<Order> orders; // order list
};

typedef vector<int> Individual;
typedef vector<Individual> Population;

class GA {
public:
    GA(int psz): popSize(psz), mutateRate(0.2) {};
    void set_popSize(int sz);
    void set_indSize(int sz);
    void solve(int iterNum, const Problem &problem) const;
private:
    int popSize; // need to be even
    int indSize;
    double mutateRate;
    Population generate_offspring(const Population &parent, int geneMax) const;
};

class ACO {
public:
    ACO(int na);
    vector<int> solve(int iterNum, const vector<Order> &orders, const vector< vector<int> > &dis);
    int generate(const vector<Order> &orders, const vector< vector<int> > &dis, vector<int> &path) const;
private:
    int antNum; // number of ants
    // int colNum; // number of colonies
    double initPh; // initial pheromone value
    double evapCoef; // ecaporate coefficient
    double incPh; // increment pheromone
    double alpha, beta;
    vector< vector<double> > pheromone; // pheromone matrix
};

void floyd(int verNum, vector< vector<int> > &dis);
int roulette(const vector<int> &keys, const vector<double> &values);
int count_served_order(const vector<Order> &orders, const vector< vector<int> > &dis, const vector<int> &path);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    srand((unsigned) time(NULL));

    cin >> T;
    while (T--) {
        Problem p;
        p.read_init();
        p.shortest_path();
    }

    return 0;
}

/* ------------------------------ class: Order ------------------------------ */

int Order::get_st() const {
    return st;
}

int Order::get_ear() const {
    return ear;
}

int Order::get_lst() const {
    return lst;
}

/* ----------------------------- class: Problem ----------------------------- */

void Problem::read_init() {
    cin >> verNum >> edgeNum >> ordNum >> stafNum;
    dis = vector< vector<int> > (verNum + 1, vector<int> (verNum + 1, -1));
    for (int i = 1; i <= verNum; i++) {
        dis[i][i] = 0;
    }
    for (int i = 1, u, v, w; i <= edgeNum; i++) {
        cin >> u >> v >> w;
        if (dis[u][v] == -1) {
            dis[u][v] = dis[v][u] = w;
        } else {
            dis[u][v] = min(dis[u][v], w);
            dis[v][u] = dis[u][v];
        }
    }
    // ????????????????????????
    orders.push_back(Order(0, 0, 0, 0));
    for (int i = 1, s, d, e, l; i <= ordNum; i++) {
        cin >> s >> d >> e >> l;
        orders.push_back(Order(s, d, e, l));
    }
    stVer = orders[0].get_st();
}

void Problem::shortest_path() {
    floyd(verNum, dis);
}

/* -------------------------------- class: GA ------------------------------- */

void GA::set_popSize(int sz) {
    popSize = sz;
}

void GA::set_indSize(int sz) {
    indSize = sz;
}

void GA::solve(int iterNum, const Problem &problem) const {
    // i-th gene of individual <=> (i+1)-th order
    int stafNum = problem.get_stafNum();
    Population parent = Population (popSize, Individual (indSize));
    vector<int> values(popSize); 
    for (int i = 0; i < popSize; i++) {
        for (int j = 0; j < indSize; j++) {
            parent[i][j] = rand() % stafNum + 1;
        }
        // todo calculate the utility value of an individual
        // values[i] = count_served_order()
    }
    while (iterNum--) {
        Population offspring = generate_offspring(parent, stafNum);
    }
}

Population GA::generate_offspring(const Population &parent, int geneMax) const {
    Population offspring = Population (popSize, Individual (indSize));
    vector<int> indices(popSize);
    for (int i = 0; i < popSize; i++) {
        indices[i] = i;
    }
    random_shuffle(indices.begin(), indices.end());
    // crossover
    for (int i = 0, p1, p2; i < popSize; i += 2) {
        p1 = indices[i];
        p2 = indices[i + 1];
        int crossPoint = rand() % (indSize - 1);
        for (int j = 0; j <= crossPoint; j++) {
            offspring[i][j] = parent[p1][j];
            offsprint[i + 1][j] = parent[p2][j];
        }
        for (int j = crossPoint + 1; j < indSize; j++) {
            offspring[i][j] = parent[p2][j];
            offspring[i + 1][j] = parent[p1][j];
        }
    }
    // mutation
    for (int i = 0; i < popSize; i++) {
        double rd = (double) rand() / (double) RAND_MAX;
        if (rd < mutateRate) {
            int j = rand() % indSize;
            offspring[i][j] = rand() % geneMax + 1;
        }
    }
    // todo calculate the utility value of individuals in offspring
    for (int i = 0; i < popSize; i++) {
        arrange_path(offspring[i], geneMax);
    }
    // selection

}

void GA::arrange_path(const Problem &problem, const Individual &ind, int geneMax) const {
    int stVer = problem.get_stVer();
    vector< vector<double> > dis = problem.get_dis();
    vector<Order> orders = problem.get_orders();
    vector< vector<int> > assignments(geneMax + 1);
    for (int i = 0; i < indSize; i++) {
        assignments[ind[i]].push_back(i + 1);
    }
    int stafNum = problem.get_stafNum();
    for (int i = 1; i <= stafNum; i++) {
        arrange_path(orders, dis, stVer, assignments[i]);
    }
}

void GA::arrange_path(const vector<Order> &orders, const vector< vector<double> > &dis, int stVer, const vector<int> assign) const {
    int tmpOrdNum = assign.size();
    vector< vector<double> > tmpDis = vector< vector<double> > (tmpOrdNum + 1, vector<double> (tmpOrdNum + 1, -1));
    vector<Order> tmpOrders;
    // for (int j = orders[assign[j]])
    tmpDis[0][0] = 0;
    for (int i = 0; i < tmpOrdNum; i++) {
        tmpDis[0][i + 1] = dis[stVer][orders[assign[i]].get_st()] + dis[orders[assign[i]].get_st()][orders[assign[i]].get_des()];
        tmpDis[i + 1][0] = dis[orders[assign[i]].get_des()][stVer];
    }
    for (int i = 0; i < tmpOrdNum; i++) {
        tmpDis[i + 1][i + 1] = 0;
    }
    for (int i = 0; i < tmpOrdNum; i++) {
        for (int j = 0; j < tmpOrdNum; j++) {
            if (i == j) continue;
            tmpDis[i + 1][j + 1] = dis[orders[assign[i]].get_des][orders[assign[j]].get_st()] + dis[orders[assign[j]].get_st()][orders[assign[j]].get_des()];
        }
    }
    // todo tmpOrders
}

/* ------------------------------- class: ACO ------------------------------- */

ACO::ACO(int na): antNum(na) {
    initPh = 1;
    pheromone = vector< vector<double> > (na, vector<double> (na, initPh));
}

vector<int> ACO::solve(int iterNum, const vector<Order> &orders, const vector< vector<int> > &dis) {
    // initial vertex is: 0
    int ordNum = orders.size() - 1;
    int pathLen = ordNum;
    vector<int> gOptPath(pathLen);
    for (int i = 0; i < pathLen; i++) {
        gOptPath[i] = i + 1;
    }
    int gOptServedNum = count_served_order(orders, dis, gOptPath);
    while (iterNum--) {
        vector<int> optPath;
        int optServedNum = 0;
        for (int i = 0; i < antNum; i++) {
            vector<int> path;
            int servedNum = 0;
            servedNum = generate(orders, dis, path);
            if (servedNum > optServedNum) {
                optPath = path;
                optServedNum = servedNum;
            }
        }
        // evaporate
        for (int i = 0; i < antNum; i++) {
            for (int j = 0; j < antNum; j++) {
                pheromone[i][j] *= evapCoef;
            }
        }
        // enhance
        pheromone[0][gOptPath[0]] += incPh;
        for (int i = 1; i < pathLen; i++) {
            pheromone[gOptPath[i - 1]][gOptPath[i]] += incPh;
        }
    }
    return gOptPath;
}

int ACO::generate(const vector<Order> &orders, const vector< vector<int> > &dis, vector<int> &path) const {
    // initial vertex is: 0
    int currVer = 0, currTime = 0;
    int ordNum = orders.size() - 1;
    int pathLen = ordNum;
    vector<bool> vis(ordNum + 1, false);
    int countVis = 0;
    while (countVis < ordNum) {
        vector<int> orderList;
        vector<double> possList;
        for (int i = 1; i <= ordNum; i++) {
            if (vis[i]) continue;
            orderList.push_back(i);
            double tau = pheromone[currVer][i];
            double eta = max(orders[i].get_ear() - currTime, dis[currVer][i]);
            possList.push_back(pow(tau, alpha) * pow(eta, beta));
        }
        int nextVer = roulette(orderList, possList);
        path.push_back(nextVer);
        currTime = max(currTime + dis[currVer][nextVer], orders[nextVer].get_ear());
        currVer = nextVer;
        vis[nextVer] = true;
    }
    int served = count_served_order(orders, dis, path);
}

/* -------------------------------- functions ------------------------------- */

void floyd(int verNum, vector< vector<int> > &dis) {
    for (int k = 1; k <= verNum; k++) {
        for (int i = 1; i <= verNum; i++) {
            if (dis[i][k] == -1) continue;
            for (int j = 1; j <= verNum; j++) {
                if (dis[k][j] == -1) continue;
                if (dis[i][j] == -1 || dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int roulette(const vector<int> &keys, const vector<double> &values) {
    int num = keys.size();
    for (int i = 1; i < num; i++) {
        values[i] += values[i - 1];
    }
    double sum = values[num - 1];
    for (int i = 0; i < num; i++) {
        values[i] /= sum;
    }
    double rd = (double) rand() / (double) RAND_MAX;
    for (int i = 0; i < num; i++) {
        if (rd <= values[i]) return i;
    }
    return num - 1;
}

int count_served_order(const vector<Order> &orders, const vector< vector<int> > &dis, const vector<int> &path) {
    int currVer = 0;
    int currTime = 0;
    int servedNum = 0;
    for (int nextVer : path) {
        if (currTime + dis[currVer][nextVer] <= orders[nextVer].get_lst()) {
            servedNum++;
            currTime = max(currTime + dis[currVer][nextVer], orders[nextVer].get_ear());
        }
    }
    return servedNum;
}

// int count_served_order(const Individual &ind, int geneMax, const vector< vector<double> > &dis) {
//     vector< vector<int> > assignments(geneMax + 1);
//     int indSize = ind.size();
//     for (int i = 0; i < indSize; i++) {
//         assignments[ind[i]].push_back(i + 1);
//     }
//     for (int i = 1; i <= geneMax; i++) {
//         count_served_order(assignments);
//     }
// }

// int count_served_order() {

// }