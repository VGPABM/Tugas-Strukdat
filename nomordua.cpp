#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;


bool digitchecr(char c){
    return (c >= '0'&& c<='9');
}

bool operatorchecr(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' );
}

int kepentingan(char c){
    switch (c){
        case '+':
        case '-': return 1;
        case '*':
        case '/':return 2;
        case '(':
        case ')':return 3;
        default: return -1;
    }
}

int operasi(int val1, int val2, int val3){
    if (val3 == '+') return val1 + val2;
    if (val3 == '-') return val1 - val2;
    if (val3 == '*') return val1 * val2;
    return val1 / val2;
}

int evaluasi (string s){
    stack<int> vals;
    stack<char> ops;
    
    int val = 0;
    int pos = 0;
    
    while (pos < s.length()){
        char spot = s[pos];
        if (digitchecr(spot)){
            val = (val*10) + (int)(spot-'0');
        } else if (operatorchecr(spot)){
            if(spot == '('){
                ops.push(spot);
                val = 0;
            } 
            if (vals.empty()){
                vals.push(val);
                ops.push(spot);
                val = 0;
            } else if (spot == ')'){
                vals.push(val);
                while (ops.top() != '('){
                    spot = ops.pop();
                    val = vals.pop();
                    int prev = vals.pop();
                    val = operasi(prev, val, spot);
                    vals.push(val);
                }
                ops.pop();
                vals.pop();
            }
            else {
                char prev = ops.top();
                if(kepentingan(spot) > kepentingan(prev)) {
                    vals.push(val);
                    ops.push(spot);
                    val = 0;
                } else {
                    int prevval = vals.pop();
                    int prevop = ops.pop();
                    prevval = operasi(prevval,val,prevop);
                    vals.push(prevval);
                    ops.push(spot);
                    val = 0;
                }
                    
            }
        }
        pos++;
    }
    
    while (!ops.empty()){
        int prev = vals.pop();
        char spot = ops.pop();
        val = operasi (prev,val,spot);
    }
    return val;
}

int main() {
    // Write C++ code here
    cout << evaluasi("(2+3)*3-(10/5)") << endl;
    
    return 0;
}
