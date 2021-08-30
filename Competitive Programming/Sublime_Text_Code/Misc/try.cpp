#include<bits/stdc++.h>

using namespace std;



int main() {

#ifdef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("inputf.in" , "r", stdin);
	//for wrtiting output to output.txt
	freopen("outputf.in" , "w" , stdout);
#endif
	// set<int> s;
	// int i = 0 ;
	// size_t found = - 1;
	// string str;
	// getline(cin , str);
	// while (i < str.length()) {
	// 	found = str.find(str.at(0) , found + 1);
	// 	if (found != string::npos)
	// 		s.insert(found);
	// 	i++;
	// }
	// cout << s.size() << endl;
	// for (auto x : s)
	// 	cout << x << " ";

	int x;
	cin >> x;

	cout << ((log(x)) / (log2)) << endl;

}