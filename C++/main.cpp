#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("in2.txt", "r", stdin);
    int n;
    scanf("%d",&n);
    string s;
    stack<int> st1;
    stack<char> st2;
    for(int i = 0;i < n;i++){
        while(!st1.empty()) st1.pop();
        cin >> s;
//		cout << s;
        int index = 0;
        int sign = 1;
        while(index < 7){
            if(index % 2 == 0) st1.push((s[index++] - '0') * sign);
            else{
                if(s[index] == 'x'){
                    int top = st1.top();
                    st1.pop();
                    st1.push((s[index + 1] - '0') * top);
                    index += 2;
                }
                else if(s[index] == '/'){
                    int top = st1.top();
                    st1.pop();
                    st1.push(top / (s[index + 1] - '0'));
                    index += 2;
                }
                else if(s[index] == '+'){
                    sign = 1;
                    st2.push('+');
                    index++;
                }
                else{
                    sign = -1;
                    st2.push('+');
                    index++;
                }
            }
        }
        while(!st2.empty()){
            char op = st2.top();
            st2.pop();
            int num2 = st1.top();
            st1.pop();
            int num1 = st1.top();
            st1.pop();
            if(op == '+') st1.push(num1 + num2);
            else st1.push(num1 - num2);
        }
        int ans = st1.top();
        st1.pop();
        if(ans == 24) printf("Yes\n");
        else printf("No\n", ans);
    }

    return 0;
}
