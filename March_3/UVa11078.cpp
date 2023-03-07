#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m, large, ans, next;
    scanf("%d", &n);
    while (n--){
        scanf("%d", &m);
        scanf("%d", &large);
        ans = -1;
        for(int i = 1; i < m; i++){
            scanf("%d", &next);
            if(large > next){
                ans = max(ans, large - next);
            }
            large = max(large, next);
        }
        printf("%d\n", ans);   
    }
    return 0;    
}

/*

int main() {
	ios::sync_with_stdio(false);
	int n, t, large, ans, next;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> large;
		ans = -1;
		for (int i = 1; i < n; i++) {
			cin >> next;
			if (large > next) ans = max(ans, large - next);
			large = max(large, next);
		}
		cout << ans << endl;
	}
}

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

cin 慢是有原因的，默认情况下，cin 与 stdin 总是保持同步的，也就是说这两种方法可以混用，不必担心文件指针混乱，
同时 cout 和 stdout 也一样，两者混用不会输出顺序错乱。正是为了这个兼容的特性，导致 cin 有许多额外的开销，
如何禁用这个特性呢？只需一个语句 std::ios::sync_with_stdio(false); ，这样就可以取消 cin 和 stdin 的同步了。

std::ios::sync_with_stdio(); 是一个“是否兼容stdio”的开关，C++为了兼容C，
保证程序在使用了std::printf和std::cout的时候不发生混乱，将输出流绑到了一起。
也就是 C++标准streams(cin,cout,cerr…) 与相应的C标准程序库文件(stdin,stdout,stderr)同步，
使用相同的 stream 缓冲区。
默认是同步的，但由于同步会带来某些不必要的负担，因此该函数作用是使得用户可以自行取消同步。

cin.tie(NULL) 取消 cin 和 cout 的绑定。


*/