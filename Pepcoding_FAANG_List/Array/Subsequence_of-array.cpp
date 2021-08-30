// https://www.geeksforgeeks.org/power-set/
// https://www.geeksforgeeks.org/recursive-program-to-generate-power-set/

// Time Complexity --> O(n* 2^n)
// Space Complexity --> O(1)

// #include<bits/stdc++.h>

// using namespace std;

// int main() {

// 	string str;
// 	int len = 0 , subset_size;
// 	getline(cin , str);
// 	// cout << str << endl;
// 	for (int i = 0; str[i] != '\0'; i++) {
// 		if (str[i] != ' ')
// 			len++;
// 	}

// 	// cout << len << endl;
// 	// cout << str.size() << endl;
// 	// len = str.length();
// 	subset_size = pow(2 , len);
// 	for (int i = 0; i < subset_size; ++i) {

// 		for (int j = 0; j < len; ++j) {

// 			if (i & (1 << j))
// 				cout << str.at(2 * j);
// 		}
// 		cout << endl;
// 	}

// 	return 0;
// }


// subsequence_using_recursion
// Time Complexity = 2^n
#include<bits/stdc++.h>

using namespace std;

// top to bottom
void ss_gen(string str , string cur) {

	//base case
	if (str.length() == 0) {
		cout << cur << endl;
		return;
	}
	// reject
	ss_gen(str.substr(1) , cur);

	// Backtrack
	// select
	ss_gen(str.substr(1) , cur + str[0]);
}

//bottom to top

void power_set(string str , int i , string cur) {

	if (str.length() == i) {
		cout << cur << endl;
		return;
	}

	// if i am using i++ instead of i + 1 then i will get this runtime error
	// /home/keith/builds/mingw/gcc-9.2.0-mingw32-cross-native/mingw32
	// /libstdc++-v3/include/bits/basic_string.h:1067: std::__cxx11::basic_string
	// <_CharT, _Traits, _Alloc>::reference std::__cxx11::basic_string<_CharT, _Traits,
	// _Alloc>::operator[](std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type)
	// [with _CharT = char; _Traits = std::char_traits<char>; _Alloc = std::allocator<char>;
	// std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::reference = char&;
	// std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type = unsigned int]:
	// Assertion '__pos <= size()' failed.

	power_set(str , i + 1 , cur + str[i]);
	power_set(str , i + 1 , cur);
}

int main() {

	string str , out = "";
	getline(cin , str);

	// input --> abcdef

	// str.erase();// output --> every character removed
	// cout << str << endl;

	// str.erase(2); // output --> ab (Note index start with 0 and the mentioned is
	// also removed that is inclusive)
	// cout << str << endl;

	// str.erase(5); // output --> abcde
	// cout << str << endl;

	// isme confusion hai
	// str.erase(1 , 4);
	// output --> af (Note first argument is from which index you want to start
	// and second argument is how many charaters you want to delete)
	// in above example start with first index and deletes upto 4 characters ahead
	// cout << str << endl;

	// str.erase(str.begin() + 1 , str.begin() + 2);
	// output --> acdef (Note in all above scenario first and last index is inclusive
	// but here in case of iterator last index is exclusive)
	// cout << str << endl;

	// if we work with iterator it removes only single character also

	// str.erase(str.begin() + 4); // output --> abcdf
	// cout << str << endl;

	// ss_gen(str , out);
	power_set(str , 0 , "");

	// detail about substr function
	// cout << str.substr(1 , 4) << endl; // output the substring including passed index upto last index
}
