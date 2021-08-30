#include<unordered_set>
#include<iostream>
#include<math.h>
#include<cstring>
#include<iomanip>
#include<algorithm>

using namespace std;

#define MAX_SIZE 2000000

#define ISLP(y) ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)

int findPrime(int nth){

    int num = 2 , count = 0;
    bool prime[MAX_SIZE + 1];
    memset(prime , true , sizeof(prime));

    for(int i = 4 ;  i <= MAX_SIZE ; i += 2)
        prime[i] = false;

    for(int i = 3 ; i * i <= MAX_SIZE ; i += 2){
        
        if(prime[i])
            for(int j = i * i ; j <= MAX_SIZE ; j += i)
                prime[j] = false;
    }   

    for(int i = 2 ; i <= MAX_SIZE ; i++){
        
        if(prime[i]){
            num = i;
            count++;
        }

        if(count == nth)
            break;
    }
    
    return num;
}

// limit is that it is only work upto 5 precision

float sqRoot(int num , int pre){

    int l = 0 , h = num , mid ;
    float ans;
    while(l < h){
        mid = l + (h - l / 2);
        
        if(mid * mid == num){
            ans = mid;
            break;
        }

        else if(mid * mid < num){
            ans = mid;
            l = mid + 1;
        }

        else{
            ans = mid;
            h = mid - 1;
        }
    }

    float inc = 0.1;
    for(int i = 0 ; i < pre ; i++){

        while(ans*ans <= num){
            ans += inc;
        }
        ans -= inc;
        inc /= 10;
    }

    return ans;
}

int main(){

    // unordered_set<string> s;
    // string st;
    // s = {"break", "case", "continue", "default", "defer", "else", "for", "func", "goto", "if", "map", "range", "return", "struct", "type", "var"};

    // cin >> st;

    // if(s.find(st) != s.end())
    //     cout << st <<" is a keyword";

    // else
    //     cout << st <<" is not a keyword";

    // int no , res = 0 , i = 0;
    // string s;
    // cin >> s;
    // int len = s.length();
    // //cout << len << endl; 
    // while(len--) {

    //     no = (int)s.at(len);
    //     cout << no << endl;

    //     if(no >= 65 && no <= 71)
    //         no -= 55;

    //     if(no >= 48 && no <= 57)
    //         no -= 48;

    //     cout << no << endl;
    //     res += no * pow(17 , i);
    //     i++;
    // }
    // cout << res;
    // int oddN = 0 , evenN = 0;
    // string s;
    // cin >> s;
    // int len = s.length();

    // while(len--){

    //     if(len % 2 == 0)
    //         oddN += (int)s.at(len) - 48;

    //     else
    //         evenN += (int)s.at(len) - 48;
    // }

    // cout << abs(oddN - evenN);

    // int year = 2019;
    // cout << ISLP(year);
    // int no;
    // bool isPrime = true;
    // cin >> no;

    // if(no < 0)
    //     cout << "negative no";

    // else{

    //     for(int i = 2 ; i * i <= no ; i++){
            
    //         if(no % i == 0){
    //             isPrime = false;
    //             break;
    //         }
    //     }
    //     if(isPrime)
    //         cout << no << " is Prime";

    //     else
    //         cout << no << " is not Prime";
    // }

//     int arr[4] = {0 , 0 , 7 , 6};
//     int i = 4 , n;
//     cin >> n;
    
//     if(n < 5)
//         cout << arr[n - 1];

//     else{
    
//         while(i < n) {

//             if(i % 2 == 0)
//                 arr[2] = arr[2] + 7;
            
//             else
//                 arr[3] = arr[3] + 6;
            
//             i++;
//         }

//         if(n % 2 == 1)
//             cout << arr[2];
        
//         else
//             cout << arr[3];
        
//     }    

    // int n , gp , num;

    // cin >> n;

    // if(n % 2){
    //     num = (n / 2) + 1;
    //     gp = pow(2 , num - 1);
    //     cout << gp;
    // }

    // else{
    //     num = n / 2;
    //     gp = pow(3 , num - 1);
    //     cout << gp;
       // }
    
    // char c1[5];
    // char c2[5];
    // char c3[5];

    // cin >> c1;
    // cin >> c2;
    // cin >> c3;

    // for(int i = 0 ; c1[i] != '\0' ; i++){
        
    //     if(c1[i] == 'a' || c1[i] == 'e' || c1[i] == 'i' || c1[i] == 'o' || c1[i] == 'u' || c1[i] == 'A' || c1[i] == 'E' || c1[i] == 'I' || c1[i] == 'O' || c1[i] == 'U')
    //         c1[i] = '*';
    // }

    // for(int i = 0 ; c2[i] != '\0' ; i++){
        
    //     if((c2[i] >= 'a' && c2[i] <= 'z') || c2[i] >= 'A' && c2[i] <= 'Z')
    //         if(!(c2[i] == 'a' || c2[i] == 'e' || c2[i] == 'i' || c2[i] == 'o' || c2[i] == 'u' || c1[i] == 'A' || c1[i] == 'E' || c1[i] == 'I' || c1[i] == 'O' || c1[i] == 'U'))
    //             c2[i] = '@';
    // }

    // for(int i = 0 ; c3[i] != '\0' ; i++){
    //     if(c3[i] >= 'a' && c3[i] <= 'z')
    //         c3[i] -= 32;
    // }
    // cout << c1 << c2 << c3;

    // int n1 = 0 , n;

    // cin >> n;
    // if(n <= 2)
    //     cout << n1;
    
    // else if(n > 2 && n % 2){
    //     n1 = (n / 2)  * 2;
    //     cout << n1;
    // }

    // else{
    //     n1 = (n / 2) - 1;
    //     cout << n1;
    // }

    // int n , n1 = 1 , n2 = 1 , res , num;
    // cin >> n;    
    // if(n <= 4 && n % 2)
    //     cout << n1;

    // else if(n > 4 && n % 2){
    //     num = n / 2 - 1;
    //     while (num--) {
    //         res = n1 + n2;
    //         n2 = res;
    //         n1 = n2;
    //     }  
    //     cout << res;      
    // }

    // else if(n % 2 == 0){
    //     res = findPrime(n / 2);
    //     cout << res;
    // }

    // int x;
    // float y;

    // cin >> x;
    // cin >> y;
    // if(isnan(x) || isnan(y))
    //     cout << "Error" ;
    
    // else{
    //     cout << 0.2f << (x + y) ;
    // }

    // long long bin_num , base = 1 , res = 0;
    // cin >> bin_num;

    // while(bin_num > 0){

    //     res += base * (bin_num % 10);
    //     bin_num /= 10;
    //     base *= 2;
    // }

    // cout << res;

    // long long decimal , base = 1 , rem , bin = 0;
    // string res;
    // cin >> decimal;

    // while(decimal > 0){
    //     rem = decimal % 2;
    //     res += to_string(rem);

    //     bin += base * (decimal % 2);
    //     decimal /= 2;
    //     base *= 10;
    // }

    // reverse(res.begin() , res.end());
    // cout << res << endl;
    // cout << bin << endl;

    // cout << 3.14 * 25.99 * 25.99 << endl;

    // long long decimal , octal[100] , base = 1 , res = 0;
    // int i = 0;
    // cin >> decimal;

    // while(decimal != 0){
        
    //     // octal[i++] = decimal % 8;
    //     res += base * (decimal % 8);
    //     decimal /= 8;
    //     base *= 10;
    // }

    // for(int j = i - 1 ; j >= 0 ; j--)
    //     cout << octal[j];
    // cout << res << endl;
    // long long octal , base = 1 , res = 0;

    // cin >> octal;

    // while(octal){

    //     res += base * (octal % 10);        
    //     base *= 8;
    //     octal /= 10;
     // }

    // cout << res << endl;

//Binary to octal --> first binary to decimal
//     long long bin_num , base = 1 , res = 0;
//     cin >> bin_num;

//     while(bin_num > 0){

//         res += base * (bin_num % 10);
//         bin_num /= 10;
//         base *= 2;
//     }

//     cout << res << endl;   
// // second --> decimal to octal
//     long long decimal , octal[100] , oct = 0;
//     int i = 0;
//     base = 1;
//     while(res != 0){
        
//         // octal[i++] = decimal % 8;
//         oct += base * (res % 8);
//         res /= 8;
//         base *= 10;
//     }

//     // for(int j = i - 1 ; j >= 0 ; j--)
//     //     cout << octal[j];
    
//     cout << oct << endl;    

    int x , p ;
    cin >> x >> p;
    cout << sqRoot(x , p);
}

#include<iostream>
#include<limits.h>

using namespace std;

int main(){
    
    int arr[9] , temp; 
    int avg1 , avg2 , avg3;
    
    for(int i = 0 ; i < 9 ; i++){
        cin >> temp;
    
        if(temp > 0 && temp < 100)
            arr[i] = temp;
            
        else
            arr[i] = 0;
    }
    avg1 = arr[0] + arr[3] + arr[6] / 3;
    avg2 = arr[1] + arr[4] + arr[7] / 3;
    avg3 = arr[2] + arr[5] + arr[8] / 3;
    
    if(avg1 < 70 && avg2 < 70 && avg3 < 70)
        cout << "All trainees are unfit";
    
    else if(avg1 == avg2 == avg3){
        cout << "All trainees are fit";
    }
    
    else if(avg1 == avg2){
        cout << "Trainee Number: 1" << endl;
        cout << "Trainee NUmber: 2";
    }
    else if(avg2 == avg3){
        cout << "Trainee Number: 2" << endl;
        cout << "Trainee Number: 3";
    }
    else if(avg3 == avg1){
        cout << "Trainee Number: 1" << endl;
        cout << "Trainee Number: 3";
    }
    
    else if(avg1 > avg2 && avg1 > avg3){
        
        cout << "Trainee Number: 1";
    }
    else if(avg2 > avg1 && avg2 > avg3){
        cout << "Trainee Number: 2";
    }
    else if(avg3 > avg1 && avg3 > avg1){
        cout << "Trainee Number: 3";
    }
}

#include <iostream>

using namespace std;

int main() {
  int N = 10 , k = 5 , noc;
  
  cin >> noc;
  
  if(noc > 0 && noc <= N){
    cout << "Number of CANDIES SOLD: "<< noc << endl;
    
    if(N - noc < k)
    	cout << "NUMBER OF CANDIES AVAILABLE: " << N;
    
    else
      cout << "NUMBER OF CANDIES AVAILABLE: " << N - noc;
  }
  
  else{
    cout << "INVALID INPUT" << endl;
    cout << "NUMBER OF CNADIES LEFT: " << N;
  }
}





#include<iostream>

using namespace std;

int main()
{
	int mw;
	cin >> mw;
	
	if(mw == 0)
		cout << "Time Estimated : 0 Minutes" << endl;

	else if(mw > 0 && mw <= 2000)
		cout << "Machine Weight is: 25 Minutes";
	
	else if(mw > 2000 && mw <= 4000)
		cout << "Machine Weight is: 35 Minutes";

	else if(mw > 4000 && mw <= 7000)
		cout << "Time Estimated is: 45 Minutes";

	else
		cout << "INVALID INPUT";
	
	int i = 0 , j = 0;
	char str[100];
	cin >> str;
	
	while(str[i]){
		if(str[i] != ' ')
			str[j++] = str[i];
		
		i++;
	}
	str[j] = '\0'; 	
}

