#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

/* Print Macros */
	#define ARRAY_LENGTH(array) (sizeof((array))/sizeof((array)[0]))
	#define _printarv(array){  size_t _sz = ARRAY_LENGTH(array);   	               \
	cerr << "[ "; for (size_t _j = 0; _j < _sz; ++_j) {cerr << array[_j] <<" "; }  \
	cerr <<"],\n"; }
	#define _printar(array) {  size_t _sz = ARRAY_LENGTH(array);   	               \
	cerr << #array <<"=[ ";                                                        \
	for (size_t _j = 0; _j < _sz; ++_j) {cerr << array[_j] <<" "; }                \
	cerr <<"]\n"; }
	#define _print(d) cerr << #d << "=[" << d << "] "
	#define _print2d(_arrayd) { size_t _sz_2d = ARRAY_LENGTH(_arrayd);             \
		cerr << #_arrayd << "=[\n";                                                  \
		for (size_t _i = 0; _i < _sz_2d; ++_i)                                       \
		{                                                                            \
			_printarv(_arrayd[_i]);                                                    \
		}                                                                            \
		cerr << "]\n";                                                               \
	}

	// #define _printv(v, type) cerr << #v <<"="; printv<type>(v)
	#define _printv(type, v) { cerr << #v <<"="; printv<type>(v); }
	#define _printvv(type, v) { cerr << #v <<"=";                                  \
            cerr << "["; for (auto &t : vv) printv<type>(t); cerr <<"]" } ;
	#define _printmp(t1, t2, mp) { cerr << #mp << "=";  printmp<t1,t2>(mp); };

/* Print Function Templates */
	template<class T1, class T2> void printmp(const map<T1,T2>& mp){
		cerr << "[ ";
    for(const auto& i : mp)
      cerr << "[" << i.first << "," << i.second <<"] ";
    cerr << "]\n";}

	template <class T> void printv(vector<T>& v) {
		cerr<<"[ ";
		for(const T &i : v)
			cerr << i <<" ";
		cerr<<"]\n"; }

/* Code Initialization */
	void init() {
		ios_base::sync_with_stdio(false); 
		cin.tie(NULL);
		#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
		#endif
	}

int solve() {
	int test  = 1;
	while(cin>>test)
		_print(test);
	return 0;
}

int main() {
	init();
	int arr[2][4] = {{1,0,3},{2,2,3}};
	_print2d(arr);
	return solve();
}
