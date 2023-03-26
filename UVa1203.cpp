#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

class Item{
    public:

    int Q_num, Period, Time;

    bool operator < (const Item& a) const{
        return (Time > a.Time || Time == a.Time && Q_num > a.Q_num);
        // 如果我傳進來的時間(a.Time), 比在裡面的時間(Time)小, 就輸出 => 傳進來的(a.Time)比較小, 就輸出
        // 如果要傳進來的大輸出, 就改成 Time < a.Time => 傳進來的(a.Time)比較大, 就輸出
        // 時間一樣, 號碼比較小的先輸出
    }
};

int main(){
    priority_queue<Item> pq;
    char s[20];

    while(scanf("%s", s) && s[0] != '#'){
        Item item;
        scanf("%d%d", &item.Q_num, &item.Period);
        item.Time = item.Period;
        pq.push(item);
    }

    int K;
    scanf("%d", &K);

    while(K--){
        Item r = pq.top(); // 優先等級最高的, copy 到 r 這個變數內
        pq.pop(); // copy 過去, 值並不會消失, 要 pop 才會消失
        printf("%d\n", r.Q_num);
        r.Time += r.Period;
        pq.push(r);
    }
    return 0;
}