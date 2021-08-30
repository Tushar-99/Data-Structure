//formula based simple question

#include<bits/stdc++.h>

using namespace std;

int totVeh(int nod , char *aph , int *digit){
	
  	// int alpha = 1;
  	// int digi = 1;
  
    if(nod == 0 || digit[1] == 0)
      return 0;
  
    // int range = int((aph[1] - 65) - (aph[0] - 65)) + 1;
	// int range1 = digit[1] - digit[0] + 1;

    // alpha = range * range;
    // digi = range1 * range1 * range1 * range1;

    //return nod * alpha * digi;

    return nod * (int((aph[1] - 65) - (aph[0] - 65)) + 1) * (int((aph[1] - 65) - (aph[0] - 65)) + 1) * (digit[1] - digit[0] + 1) * (digit[1] - digit[0] + 1) * (digit[1] - digit[0] + 1) * (digit[1] - digit[0] + 1);
} 

int main(){
    
    int nod;
    char aph[2];
    int digit[2];

    cin >> nod;
    cin >> aph[0];
    cin >> aph[1];
    cin >> digit[0];
    cin >> digit[1];
    
    cout<<totVeh(nod,aph,digit);
}	