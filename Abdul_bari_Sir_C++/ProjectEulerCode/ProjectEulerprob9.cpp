// #include<bits/stdc++.h>

// using namespace std;


// int main(){

//these both below approches find triplets not generate so thats why some cases are missing
    //Generate Pythgorean Triples but not all here main triplets also not multiples of it also not generating
    // int a = 0;
    // int b = 0;
    // int c = 0;

    // for(int m = 1 ; m <= MAX ; m++){
    //     a = 2 * m;
    //     b = (m * m) - 1;
    //     c = (m * m) + 1;

    //     cout<<"("<<a<<","<<b<<","<<c<<")"<<" ";
    // }

    //Best Approach to generaete so but still multiple are not generating
    // int MAX,c=0,a,b;
    // cout<<"Enter Last no to limit so";
    // cin >> MAX;
    
    // int m=2;

    // while(c < MAX){
    //     for(int n=1 ; n < m ; n++){
    //         a = m*m-n*n;
    //         b = 2*m*n;
    //         c = m*m+n*n;

    //         if(c > MAX)
    //             break;
                
    //         cout<<"("<<a<<","<<b<<","<<c<<")"<<" ";
    //     }m++;
    // }

//     int a,b,c,m,n,final=100,initial=1;
//     for(int m=1 ; m <= final ; m++){
//         for(int n=1 ; n <= final ; n++){
//             a=m*m-n*n;
//             b=2*m*n;
//             c=m*m+n*n;

//             if(c > final)
//                 break;

//             if(a <= final && b <= final && c <= final && a >= initial && b >= initial && c >= initial)
//                 cout<<"("<<a<<","<<b<<","<<c<<")"<<" ";
//         }
//     }
// }


//Very Fast solution


// Time to return solution:

// real	0m0.011s
// user	0m0.003s
// sys	0m0.000s

// Intel(R) Core(TM)2 Duo CPU T6400 @ 2.00GHz

// Currently revisiting older problems in an effort to tidy them up and find better solutions than my original efforts.

// So far as this problem is concerned, there is one major improvement I discovered. We know that, when generating primitive Pythagorean triplets, a, b, c, we can find all other triplets by including a constant, k, such that the new triplet is ka, kb, kc. With this in mind it is possible to rework this problem so that, instead of generating and checking Pythagorean triplets until their sum is 1,000, we can terminate our search as soon as we find a smaller primitive triple whose sum evenly divides 1,000. By dividing 1,000 by a + b + c we can then calculate k and use that in order to solve this problem.

// Code wise, I made a simple queue struct, with basic functionality (push_back and pop) [code not include]. Three functions are used to generate 'child' triplets and each 'child' is pushed back onto the queue. Once a, b, and c, are popped from the top of the queue such that ka + kb + kc = 1,000, we break out of the loop and print the required result.

// *Wikipedia article outlining the generation of 'child' triplets: Parent/child relationships

#include <stdio.h>
#include <stdlib.h>

// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
//             a^2 + b^2 = c^2
//
// For example, 32 + 42 = 9 + 16 = 25 = 52.
//
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

#include <queue>

node_t *new_node1(int, int, int);
node_t *new_node2(int, int, int);
node_t *new_node3(int, int, int);

void printf_comma (int);
void print_triplet(int, int, int);
void solution     (int);

int main(int argc, char **argv) {

  printf("TEST:\n");
  solution(12);

  printf("\nSOLUTION:\n");
  solution(1000);

  return 0;
}

node_t *new_node1(int a, int b, int c) {

  return node_constructor(a - (b << 1) + (c << 1),
                          (a << 1) - b + (c << 1),
                          (a << 1) - (b << 1) + c + (c << 1));
}

node_t *new_node2(int a, int b, int c) {

  return node_constructor(a + (b << 1) + (c << 1),
                          (a << 1) + b + (c << 1),
                          (a << 1) + (b << 1) + c + (c << 1));
}

node_t *new_node3(int a, int b, int c) {

  return node_constructor(-a + (b << 1) + (c << 1),
                          -(a << 1) + b + (c << 1),
                          -(a << 1) + (b << 1) + c + (c << 1));
}

void printf_comma(int n) {

  if(n < 1000) {

    printf("%d", n);
    return;
  }

  printf_comma(n / 1000);
  printf(",%03d", n % 1000);
}

void print_triplet(int a, int b, int c) {

  if(a > b) {

    int temp = a;
    a = b;
    b = temp;
  }

  printf("(%d, %d, %d)", a, b, c);
}

void solution(int target) {

  queue_t *triples = NULL;
  push_back(&triples, node_constructor(3, 4, 5));

  int a = 0;
  int b = 0;
  int c = 0;
  int x = 0;

  while(1) {

    a = triples->head->a;
    b = triples->head->b;
    c = triples->head->c;

    pop_front(triples);

    if(!(target % (a + b + c))) {

      x = target / (a + b + c);
      a *= x;
      b *= x;
      c *= x;
      break;
    }

    push_back(&triples, new_node1(a, b, c));
    push_back(&triples, new_node2(a, b, c));
    push_back(&triples, new_node3(a, b, c));
  }

  printf("The triplet which sums to %d is ", target);
  print_triplet(a, b, c);
  printf(" and its product is ");
  printf_comma(a * b * c);
  printf("\n");

  queue_destructor(&triples);
}


//JAVA code

// public class Main
// {
// 	public static void main(String[] args) {
// 		System.out.println(Main.pythagoreanTriplet());
// 	}
	
// 	public static int pythagoreanTriplet(){
//         int c = 0;
//         for(int a = 1; a < 1000; a++){
//             for(int b = a + 1; b < 1000 ; b++) {
//                 if (a + b + Math.sqrt((a*a)+(b*b)) == 1000){
//                     c = (int)(Math.sqrt((a*a)+(b*b)));
//                     System.out.println(a + " " + b + " " + c);
//                     return a * b * c;
//                 }
//             }
//         }
    
//         return -1;
//     }
// }
