#include<iostream>
#include <string.h>
#include <vector>
#include<sstream>
#include <iomanip>
#include <math.h>
#include<map>
#define ll long long int

using namespace std;

struct page1{
    int key;
    int time;
    int R;
};

int wsclock(int cap, vector<int> token){
    vector<struct page1> pg1;
    int hand = 0;
    ll l = token.size();
    int thresh = cap;
    int miss=0;
    for(ll i=0;i<l;i++){
        int flag =0;
        int key1 = token[i];
        int t =i;
        ll l2 = pg1.size();
        for(ll j=0;j<l2;j++){
            if(pg1[j].key == key1){
                flag =1;
                pg1[j].R =1;
                pg1[j].time =i;
                hand = j;
                break;
            }
        }
        if(flag ==0 && l2<cap){
            struct page1 temp;
            temp.key = key1;
            temp.time = i;
            temp.R = 0;
            pg1.push_back(temp);
            miss++;
            hand = pg1.size()-1;
        }
        else if(flag ==0 && l2==cap){
            ll l2 = pg1.size();
            int j = hand;
            while(1){
                if(pg1[j].R == 1){
                    pg1[j].R =0;
                    continue;
                }
                else if((i-pg1[j].time)>=thresh){
                    pg1[j].key = key1;
                    pg1[j].time = i;
                    pg1[j].R = 0;
                    miss++;
                    break;
                }
                j = (j+1)%cap;
            }
            hand =j;
        }
    }
    return miss;
}
