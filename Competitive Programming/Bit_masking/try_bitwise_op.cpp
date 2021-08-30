#include<bits/stdc++.h>

using namespace std;

// DATA                   TYPE	SIZE (IN BYTES)	RANGE
// SHORT INT	            2	-32,768 TO 32,767
// UNSIGNED SHORT INT	    2	0 TO 65,535
// UNSIGNED INT	            4	0 TO 4,294,967,295
// INT	                    4	-2,147,483,648 TO 2,147,483,647
// LONG INT	                8	-2,147,483,648 TO 2,147,483,647
// UNSIGNED LONG INT	    8	0 TO 4,294,967,295
// LONG LONG INT	        8	-(2^63) TO (2^63)-1
// UNSIGNED LONG LONG INT	8	0 TO 18,446,744,073,709,551,615
// SIGNED CHAR	            1	-128 TO 127
// UNSIGNED CHAR	        1	0 TO 255
// FLOAT	                4	 
// DOUBLE	                8	 
// LONG DOUBLE	            12	 
// WCHAR_T	                2 OR 4

int main(){

    int n = 10 , i = 1;

    n = ~(1 << i);

    // cout << n << " " << (!8);

    // long long x = (1 << 31) - 2;
    // cout << x;

    // cout << (~10);

    int x = 5, y = 2, z = 5;
    // cout << ( z&x<<y ) << endl;

    cout << !(-100000) << endl;
}

// Which one line function can be used to get index of the least significant bit that is on (first 1 from right to left in binary representation of an integer) ?

// log2( N ^ -N ) + 1

// log2( N | -N ) + 1

// log2( N & -N ) + 1

// log2( N ~ -N ) + 1