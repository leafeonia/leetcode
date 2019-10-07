#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int flipLights(int n, int m) {
        if(m == 0) return 1;
        n = min(n, 3);
        if(m == 1) return n == 1 ? 2 : n == 2 ? 3 : 4;
        if(m == 2) return n == 1 ? 2 : n == 2 ? 4 : 7;
        return n == 1 ? 2 : n == 2 ? 4 : 8; // 000 -> 010 101 100 111 -> 000 101 110 111 001 010 011
    }
    //light1 = a + b + d
    //light2 = a + c
    //light3 = a + b
    //light4 = a + c + d = light2 + light1 - light3
    //light5 = a + b = light3
    //light6 = a + c = light2
    //light7 = a + b + d = light1
};//
// Created by maoym on 2019/10/7.
//

