#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<float> race;
    float fl , sl , tl ,temp;

    cin >> temp;
    int i = 0;
    while(temp != 'q'){
        if(temp > 0)
            race[i++] = temp;

        cin >> temp;
    }

    fl = 0;
    sl = 0;
    tl = 0;

    for(i = 0 ; i < race.size() ; i++){
        if(race[i] > fl && race[i] != 42.195)
            fl = race[i];
    }

    for(i = 0 ; i < race.size() ; i++){
        if(race[i] > sl && race[i] != 42.195 && fl != race[i])
            sl = race[i];
    }

    for(i = 0 ; i < race.size() ; i++){
        if(race[i] > fl && race[i] != 42.195 && sl != race[i] && fl != race[i])
            tl = race[i];
    }

    cout << "[" << fl << "," << sl << "," << tl << "]" ;
}