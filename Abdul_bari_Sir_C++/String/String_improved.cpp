#include<bits/stdc++.h>

using namespace std;

int strLength(char const A[]){

    int i;
    for(i = 0 ; A[i] != '\0' ; i++){
    }
    return i;
}
// jo pointer aaya hai uski value ko constant rakho
int strCountSpaces(char const *A){

    int count = 0;
    for(int i = 0 ; A[i] != '\0' ; i++){
        if(A[i] == 32)
            count++;
    }
    return count;
}

int strCountCharOnly(char const *A){
    int count = 0;
    for(int i = 0 ; A[i] != '\0' ; i++){
        if(A[i] != 32){
            count++;
        }
    }
    return count;
}

int countWords(char const *A){
    int count = 1;
    for(int i = 1 ; A[i] != '\0' ; i++){
        // if(A[i] == ' '){//correct if single space is there b/w words 
        //     count++;
        // }

        if(A[i] == ' ' && A[i-1] != ' '){//correct if multiple space is between words
            count++;
        }
    }
    return count;
}

char* toUpper(char A[]){

    for(int i = 0 ; A[i] != '\0' ;i++){
        if(A[i] >= 97 && A[i] <= 122){
            A[i] = A[i]-32;
        }
    }
    return A;
}

char* toLower(char A[]){
    
    for(int i = 0 ; A[i] != '\0' ; i++){
        if(A[i] >= 65 && A[i] <= 90){
            A[i] += 32;
        }
    }
    
    return A;
}

char* toggle(char A[]){

    for(int i = 0 ; A[i] != '\0' ; i++){
        if(A[i] >= 65 && A[i] <= 90)
            A[i] += 32;

        //yaha pae garbar ho rahi hai ki if ki wajah se ye dono chala raha hai jabki hume ek hi chalana hai
        // if(A[i] >= 97 && A[i] <= 122)//else if ki importance
        //     A[i] -= 32;

        else if(A[i] >= 97 && A[i] <= 122)//else if ki importance
            A[i] -= 32;
    }

    return A;
}

int consVow(char A[]){

    int vow = 0;
    int con = 0;
    for(int i = 0 ; A[i] != '\0' ; i++){
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i'|| A[i] == 'o' || A[i] == 'u' ||
           A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
            vow++;
        
        else if((A[i] >= 65 && A[i] == 90) || (A[i] >= 97 && A[i] <= 122)){
            con++;
        }
    }
    return vow;
}

bool valid(char *A){

    int i ,count = 0;
    //for(count = 0 ; A[count] != '\0' ; count++)

    // for(i = 0 ; A[i] != '\0' ; i++){
    //     if(!(A[i] >= 65 && A[i] <= 90) && !(A[i] >= 97 && A[i] <= 122) && !(A[i] >= 48 && A[i] <= 57)){
    //         return false;
    //     }
    // }

    for(i = 0 ; A[i] != '\0' ; i++){
        if((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z') || (A[i] >= '0' && A[i] <= '9') || A[i] == ' '){
            count++;
        }

        else{
            return false;
        }

    }

    if(i == count)
        return true;

    return false;
}

char* appendPro(char A[],char B[]){

    int i = 0 , j = 0 ,k = 0;
    for(;A[i] != '\0' ; i++){} 
    //int ilen = i;
    //for(;B[j] != '\0' ; j++){}
    //int jlen = j;
    //char ch[i+j];
    // while(i-- > 0){
    //     ch[l] = A[l];
    //     l++;
    // }
    A[i++] = ' ';
    while(B[k] != '\0'){
        A[i++] = B[k++];
    }
    
    return A;
}

void Reverse(char *A){

    int i = 0 , j = 0;
    char temp;
    while(A[j] != '\0')
        j++;
    
    j--;
    
    while(i < j){
        temp = A[i];
        A[i++] = A[j];
        A[j--] = temp;
    }
}

bool comp(char A[],char B[]){

    int i = 0 , j = 0;
    for(;A[i] != '\0' ; i++){} 
    for(;B[j] != '\0' ; j++){}
    if(i < j || j < i)
        return false;

    for(i = 0; A[i] != 0 && B[i] != 0 ; i++ ){

        if(A[i] == B[i])
            continue;
        else
            return false;
    }
    if(i == j)
        return true;

    return false;
}

void duplicate(char *A,int len){

//this method has problem
    int i = 0 ,count, j;
    for(;i < len;i++){
        count = 0;
        for(j = i+1 ; j < len ; j++){
            if(A[i] == A[j]){
                count++;
                A[j] = '\0';
            }
        }
        if(count >= 1)
            cout<<A[i]<<" repeats "<<count<<endl;
    }
}

void dupPro(char *A){

    //map<int,int> mpp;
    int H[62] = {0} , i;
    for(int i = 0 ; A[i] != '\0' ; i++){
        if(A[i] >= 'a' && A[i] <= 'z'){
            H[A[i]-97]++;
        }
        else if(A[i] >= 'A' && A[i] <= 'Z'){
            //H[(A[i]-67)+26]++;
            H[A[i]-39]++;
        }
        else if(A[i] >= '0' && A[i] <= '9'){
            H[A[i]+4]++;
        }
        else{
            continue;
        }
    }

    int k;
    for(k = 0 ; k < 62 ; k++){
        if((H[k] > 1) && (k >= 0 && k < 26)){
            cout<<(char)(k+97)<<" repeats "<<H[k]<<endl;
        }
        else if((H[k] > 1) && (k >= 26 && k < 52)){
            cout<<(char)(k+39)<<" repeats "<<H[k]<<endl;
        }
        else if(H[k] > 1 &&(k >= 52 && k < 62)){
            cout<<(char)(k-4)<<" repeats "<<H[k]<<endl;
        }
        else{
            continue;
        }
    }   
}

//don't forget to initialize the array
//proper knowledge of typecasting
//

// void dupPro(char A[]){

//     int i, H[26] = {0};
//     for(i = 0 ; A[i] != '\0' ; i++){
//         H[A[i]-97]++;
//     }
//     for(i = 0 ; i < 26 ; i++){
//         if(H[i] > 1){
//             cout<<(char)(i+97)<<" repeats "<<H[i]-1<<endl;
//         }
//     }
// }

//doesn't work need help
void dupBit(char *A){

    long long int H = 0, x = 0;
    for(int i =0 ; A[i] != '\0' ; i++){
        x = 1;
        // y = 1;
        // z = 1;
        // x = x << A[i]-97;
        // y = y << A[i]-65;
        // z = z << A[i]-48;
        //if(A[i] >= 'a' && A[i] <= 'z'){

            x = x << A[i]-97;
            //cout<<x<<endl;
            if(H & x > 0){
                cout <<" Duplicates"<< A[i]<<endl;
            }
            else{
                H = H | x;
            }
        //}
        // else if(A[i] >= 'A' && A[i] <= 'Z'){
        //     x = x << A[i]-39;
        //     cout<<x<<endl;
        //     if(x & H > 0){
        //         cout <<" Duplicates"<< A[i]<<endl;
        //     }
        //     else{
        //         H = H | x;
        //     }
        // }
        // else if(A[i] >= '0' && A[i] <= '9'){
        //     x = x << A[i]+4;
        //     cout<<x<<endl;
        //     if(x & H > 0){
        //         cout <<" Duplicates"<< A[i]<<endl;
        //     }
        //     else{
        //         H = H | x;
        //     }
        // }
        // else{
        //     cout<<"stupid";
        // }
    }
}

bool checkAnagram(char A[],char B[]){

    int count = 0;
    int i = 0 , j = 0;
    for(;A[i] != '\0' ; i++){} 
    for(;B[j] != '\0' ; j++){}
    if(i < j || j < i)
        return false;
    
    else{
        for(i = 0 ; A[i] != '\0' ; i++){
            for(j = 0 ; B[j] != '\0' ; j++){
                if(A[i] == B[j]){
                    count++;
                    B[j] = ' ';
                    break;
                }
            }
        }

        if(A[i] == '\0')
            return true;
        else
            return false;
                
    }
    return false;
}

bool anaHash(char A[],char B[]){

    int count = 0;
    int i = 0 , j = 0;
    for(;A[i] != '\0' ; i++){} 
    for(;B[j] != '\0' ; j++){}
    if(i < j || j < i)
        return false;
    
    else{
        int H[26] = {0};
        for(i = 0 ; A[i] != '\0' ; i++)
            H[A[i]-97]++; 

        for(j = 0 ; B[j] != '\0' ; j++){
            H[B[j]-97]--;
            if(H[B[j]-97] < 0){
                cout<<"Not Anagram"<<endl;
                return false;
                break;
            }
        }
        if(B[j] == '\0'){
            cout<<"Anagram"<<endl;
            return true;
        }
    }
    return false;
}

void strPerm(char str[],int l){

    static int A[3] = {0};
    static char Res[3];

    if(str[l] == '\0'){
        Res[l] = '\0';
        cout<<Res<<endl;
    }
    else{

        for(int i = 0 ; str[i] != '\0' ; i++){
            if(A[i] == 0){
                Res[l] = str[i];
                A[i] = 1;
                strPerm(str,l+1);
                A[i] = 0;
            }
        }
    }
}

void swap(char *A,char *B){

    char temp;
    temp = *A;
    *A = *B;
    *B = temp;
}

void Perm(char A[],int l ,int h){

    if(l == h)
        cout<<A<<endl;
    
    else{
        for(int i = l ; i < h ; i++){
            swap(A[l],A[i]);
            Perm(A,l+1,h);
            swap(A[l],A[i]);
        }
    }
}

int main(){

    char const *A = "Ram Ram ji";//now ok it becomes mutable
    const char B[] = "Ram Ram ji";
    // char *C = "Ram Ram ji";
    // gives Warning because char * is immutable
    // warning: ISO C++ forbids converting a string constant to 'char *' [-Wwrite-strings]
    char D[] = "Tushar";//mutable
    //char* const E = "Aniket"; char *C = "Ram Ram ji"; //these both are same 
    //cout<<strLength(D)<<endl;
    //cout<<E;
    //C = "Tushar";//gives Warning
    const int u = 5;//in java we use final instead of const
    //u = 6;//expression must be a modifiable lvalue
    A = "TAniket";
    A = D;
    //cout<<A;
    //cout<<C;

    // const char* is a pointer to a const char here value being pointed at can't be changed i.e. this maintain the property of string immutable which this is made for but the pointer can be changed
    // char* const is a constant pointer to a char value being pointed at can change but this char* is made for string immutable which doesn't follwed(immutability) now i.e. now we try to mutate(change value) it which is against rule so this throw warning now here pointer cannot be changed(similar to reference).

    const char *const L = "NANA JI";//Constant pointer to a constant char
    //here neither value changed nor pointer changed
    //L = A;//Constant pointer to a constant char

    //expression must be a modifiable lvalue
    //L = "Tushar";

    //and also const char* is same as char const*

    //Rule of thumb read the defination from right to left

    // int       *      mutable_pointer_to_mutable_int;
    // int const *      mutable_pointer_to_constant_int;
    // int       *const constant_pointer_to_mutable_int;
    // int const *const constant_pointer_to_constant_int;

    // int *const i3 = (int*) 0x12345678;
    // defines a const pointer to an integer and initializes it to point at memory location 12345678. You can change the int value at address 12345678, but you can't change the address that i3 points to.

    // const int *foo;
    // Means "foo points (*) to an int that cannot change (const)".
    // To the programmer this means "I will not change the value of what foo points to".

    // *foo = 123; or foo[0] = 123; would be invalid.
    // foo = &bar; is allowed.
    // int *const foo;
    // Means "foo cannot change (const) and points (*) to an int".
    // To the programmer this means "I will not change the memory address that foo refers to".

    // *foo = 123; or foo[0] = 123; is allowed.
    // foo = &bar; would be invalid.
    // const int *const foo;
    // Means "foo cannot change (const) and points (*) to an int that cannot change (const)".
    // To the programmer this means "I will not change the value of what foo points to, nor will I change the address that foo refers to".

    // *foo = 123; or foo[0] = 123; would be invalid.
    // foo = &bar; would be invalid.

    // char const* ch = "Tushar Chaturvedi";
    // cout<<strLength(ch)<<endl;
    // ch = "Ram Ram ji";
    // cout<<strLength(ch)<<endl;
    // cout<<strCountSpaces(ch)<<endl;
    // cout<<strCountCharOnly(ch)<<endl;
    // cout<<countWords(ch)<<endl;
    //cout<<countWords("Tushar   Chatruvedi")<<endl;
    //char kd[] = "Krishan D?v Tiwari";
    // cout<<toUpper(kd)<<endl;
    // cout<<toLower(kd)<<endl;
    // cout<<toggle(kd)<<endl;
    // cout<<consVow(kd)<<endl;
    // cout<<strLength(kd)-strCountSpaces(kd)-consVow(kd)<<endl;
    // cout<<countLetters(kd)<<endl;
    // if(valid(kd))
    //     cout << "Valid String"<<endl;

    // else
    //     cout << "Invalid String"<<endl;

    //char h[] = "Tushar";
    //char r[] = "Tushar";
    //char k[] = "Aniket";
    //cout<<appendPro(h,k)<<endl;
    //below statement show warning and doesnot work because these strings are by default of char const* or char* (immutable)type such that it is non-modifiable 
    //cout<<appendPro("Tushar","Aniket")<<endl;
    //Reverse(h);
    //cout<<h;
    //cout<<comp(h,k);
    //char check1[] = "madam";
    //char check2[] = "madam";
    //char check1[] = "aniket";
    //char check2[] = "aniket";
    // Reverse(check1);
    // cout<<comp(check1,check2);
    char fin[] = "finding111118989898madamjiij";
    //duplicate(fin,7);
    //char para[] ="Paragraphs are a very important part of English composition to master. They generally consist of 3 parts";
    //dupPro(para);
    // int x = 1;
    // cout << (x<<0) <<endl;//1
    // cout << (x<<1) <<endl;//2
    // cout << (x<<2) <<endl;//4
    // cout << (x<<3) <<endl;//8
    // cout << (x<<4) <<endl;//16
    // char bit[] = "finding";
    // dupBit(bit);
    // cout<<sizeof(int)<<endl;                    //4 bytes
    // cout<<sizeof(long int)<<endl;               //4 bytes
    // cout<<sizeof(signed long int)<<endl;        //4 bytes
    // cout<<sizeof(unsigned long int)<<endl;      //4 bytes
    // cout<<sizeof(long long int)<<endl;          //8 bytes
    // cout<<sizeof(signed long long int)<<endl;   //8 bytes
    // cout<<sizeof(unsigned long long int)<<endl; //8 bytes
    //cout<< (1 >> 5) <<endl;
    char ana1[] = "decimal";
    char ana2[] = "medical";
    //cout<<checkAnagram(ana1,ana2)<<endl;
    //cout<<anaHash(ana1,ana2);
    char str[] = "abcde";
    //strPerm(str,0);
    Perm(str,0,5);
    return 0;
}