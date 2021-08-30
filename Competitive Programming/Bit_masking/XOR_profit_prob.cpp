#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int x , y , max = INT_MIN , max_temp;
    cin >> x >> y;
    
    //Wrong Algo doesn't cover ALL cases
    // while(i < j){

    //     temp1 = i ^ j;
        
    //     if((i + 1) != j){
    //         a = i + 1;
    //         temp2 = a ^ j;
    //     }

    //     if((j - 1) != i){
    //         b = j - 1;
    //         max_temp = i ^ b;
    //     }

    //     temp1 = temp1 > temp2 ? temp1 : temp2;
    //     max_temp = max_temp > temp1 ? max_temp : temp1;

    //     if(max_temp > max)
    //         max = max_temp;

    //     i++;
    //     j--;
    // }

    // for(int i = x ; i <= y ;  i++){

    //     for(int j = i + 1 ; j <= y ; j++){

    //         max_temp = i ^ j;

    //         if(max_temp > max)
    //             max = max_temp;
    //     }

    // }

    //Optimized one by utilizing the sorting 
// this is for finding minimumXOR only not right for maximum result in mistake
    // int arr[] = {2 , 3 , 5 , 8 , 10 , 25};
    // pair<int , int> p;
    // int min = INT_MAX , min_temp;
    // for(int i = 0 ; i < 5 ; i++){

    //     min_temp = arr[i] ^ arr[i + 1];
    //     if(min_temp < min){
    //         min = min_temp;
    //         p.first = arr[i];
    //         p.second = arr[i + 1];
    //     }
    // }    
    // cout << p.first  << " ^ "<< p.second << " = " << max;

// one more optimized solution in O(log n)
    // int x_fin = 0 , y_fin = 0 , temp_x = x , temp_y = y , count_x = 0 , count_y = 0 , mask = 1 , count , s_res;

    // while(temp_x > 0){
    //     temp_x >>= 1;
    //     count_x++;
    // }

    // while(temp_y > 0){
    //     temp_y >>= 1;
    //     count_y++;
    // }

    // count = count_y - count_x;
    // mask <<= (count_y - 1);

    // s_res = mask & x;   
    // s_res = s_res ^ y;

    int temp , msbPos = 0 , maxXOR = 0 , two = 1 , num1 = 1 , num2 = 1 , temp_x , temp_y , fin_x = x , fin_y = y;
    temp = x ^ y;

    while(temp){

        msbPos++;
        temp >>= 1;
    }

    
    int pos = msbPos - 1;
    while(pos){
        
        temp_x = ((x & (1 << (pos - 1))) >> (pos - 1));
        temp_y = ((y & (1 << (pos - 1))) >> (pos - 1));

        if(!(temp_x ^ temp_y)){
            
            if(temp_x == 0){
                fin_x |= (1 << (pos - 1));
            }

            else if(temp_y == 1){
                fin_y &= (~(1 << (pos - 1))); 
            }
        }
        // maxXOR += two;
        // two <<= 1;
        pos--;
    }

    cout << fin_x << " ^ "<< fin_y << " = " << (fin_x ^ fin_y);
}