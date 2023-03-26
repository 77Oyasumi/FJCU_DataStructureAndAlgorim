/*
想法：
    我們可以先將第一行和第二行求出前K小的和，因此兩行數字就變成了一行數字，
    這一行數字再和第三行求出前K小的和，兩行又合併成一行，
    一直重複將兩行合併成一行，最後就是答案。

Priority Queue :
    假設第一行數字陣列為L1，第二行數字陣列為L2，
    要丟進priority queue(底下簡稱PQ)裡的structure裡面含有兩個元素，
    第一個為val: 表示L1某個數+L2某個數的和，
    第二個為pos: 表示L2某個數在L2的位置(index)。

1.  將L1遞增排序
2.  將L2遞增排序。
3.  然後把L1裡面每個數字和L2[0]加起來，val=L1[i]+L2[0]和pos=0放到PQ裡面。
4.  L1的數字就不會用到了
5.  之後每次從PQ裡面拿出第一個(最小的val)，將這個val放入L1(覆蓋以重複利用L1)，
    然後將這個val=(val-L2[pos]+L2[pos+1])和pos=pos+1丟回PQ裡
6.  重複步驟5 K次，L1裡面就有K個數字，表示這兩行已經合併成功
7.  讀入下一個L2，並重複步驟2~7，直到將K行合併成一行
8.  輸出L1
*/

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct custom_type {
    int val;
    int pos;

    bool operator < (const custom_type &B) const {
        return val > B.val; // min heap
    }
};
int main()
{
    int K, L1[800], L2[800];
    while (scanf("%d", &K) != EOF) {
        for (int i = 0; i < K; ++i) scanf("%d", &L1[i]);
        sort(L1, L1 + K);

        for (int k = 1; k < K; ++k) {
            for (int i = 0; i < K; ++i) scanf("%d", &L2[i]);
            sort(L2, L2 + K);
            
            priority_queue<custom_type> PQ;
            for (int i = 0; i < K; ++i) 
                PQ.push({L1[i] + L2[0], 0});
            
            for (int i = 0; i < K; ++i) {
                custom_type tmp = PQ.top();
                PQ.pop();
                L1[i] = tmp.val;
                if (tmp.pos+1 < K)
                    PQ.push({tmp.val - L2[tmp.pos] + L2[tmp.pos+1], tmp.pos + 1});
            }
        }
        for (int i = 0; i < K - 1; ++i)
            printf("%d ", L1[i]);
        printf("%d\n", L1[K-1]);
    }
    return 0;
}