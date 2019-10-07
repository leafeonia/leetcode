#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitcount(int a){
        int ret = 0;
        while(a){
            if(a & 1) ret++;
            a >>= 1;
        }
        return ret;
    }
    int flipLights(int n, int m) {
        set<int> s;
        n = min(n, 6);
        for (int i = 0; i < 16; ++i) {
            int light = 0;
            if(bitcount(i) % 2 == m % 2 && bitcount(i) <= m){
                if(i & 1) light ^= 0b001001;
                if(i & 2) light ^= 0b101010;
                if(i & 4) light ^= 0b010101;
                if(i & 8) light ^= 0b111111;
                s.insert(light & ((1 << n) - 1));
            }
        }
        return s.size();
    }
};
//
// Created by maoym on 2019/10/7.
//

