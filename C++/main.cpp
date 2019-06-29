#include <bits/stdc++.h>
using namespace std;


int main(){
    for (int i = 9; i < 80; ++i) {
        cout << "<part>\n"
                "        <a href=\"fig/" << i << ".jpg\">\n"
                "            <img src=\"fig/" << i <<
                ".jpg\" alt=\"img\" >\n"
                "            </a>\n"
                "            <figcaption>\n"
                "                2016 原图 by \n"
                "            </figcaption>\n"
                "        </part>" << endl;
    }
    return 0;
}