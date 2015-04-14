/*
 * 城市的环路有n个加油站，第i个加油站的油量用gas[i]表示，你有如下的一辆车：
 *      它的油缸是无限的，初始为空
 *      它从第i个加油站到第i+1个加油站消耗的油量为cost[i]
 *
 * 现在你可以从任意一个加油站开始，通过加油站可以不断的加油，问是否能够走完环形路。如果可以返回开始加油站的编号，如果不可以返回-1
 */

#include <iostream>

using namespace std;
/*
 * 是否能完成环形路，暴力求解发
 * n 总共加油站个数，例如n=6 加油站编号 0, 1, 2, 3, 4, 5
 */
int FinishRingRoadViolence(int n, double gas[], double cost[])
{
    int i, j, flag;
    double total;
    for (i = 0; i < n; i++) {
        j = i;
        total = 0;
        flag = 1;
        do {
            total += (gas[j] - cost[j]);
            if (total < 0) {
                flag = 0;
                break;
            }
            j = (j + 1) % n;
        } while (j != i);
        if (flag) {
            break;
        }
    }
    if (flag) {
        return i;
    } else {
        return -1;
    }
}

/**
 * 1. 从第0个站开始，tank += gas[0] - cost[0]，只要tank>=0，我们就继续到下一个加油站
 *
 * 2. 当不满足tank>=0，顺着环路试验从前一个站开始，比如，n-1: tank += gas[n-1] - cost[n-1]，如果还小于0，继续试验再前一个。
 *
 * 3. 直到满足 tank>=0，再进行第1步，依次类推
 *
 * 4. 当一前一后这两个相遇了，算法也就结束了，tank>=0，就成功，返回相遇的位置；否则，失败，返回-1
 *
 *
 *
 */
int FinishRingRoadDP(int n, double gas[], double cost[])
{
    int bt, ed;
    double total;
    total = gas[0] - cost[0];
    for (bt = 0, ed = 1; bt != ed;) {
        if (total >= 0) {
            total += gas[ed] - cost[ed];
            ed = (ed + 1) % n;
        } else {
            bt = (bt - 1 + n) % n;
            total += gas[bt] - cost[bt];
        }
    }
    if (total >= 0) {
        return bt;
    } else {
        return -1;
    }
}

int main()
{
    int n = 6;
    double cost[] = {1, 2, 3, 4, 5, 6};
    double gas[] = {1, 1, 1, 10, 7, 1};
    int stationNum = FinishRingRoadViolence(n, gas, cost);
    cout << "FinishRingRoadViolence stationNum="<<stationNum<<endl;
    stationNum = FinishRingRoadDP(n, gas, cost);
    cout << "FinishRingRoadDP stationNum="<<stationNum<<endl;
    //stationNum=3
    return 0;
}
