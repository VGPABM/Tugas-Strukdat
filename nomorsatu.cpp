#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

bool beginchecker(string temp){
    if ((temp[0] == 'b' || temp[0] == 'B') && (temp[1] == 'e' || temp[1] == 'E') && (temp[2] == 'g' || temp[2] == 'G') && (temp[3] == 'i' || temp[3] == 'I') && (temp[4] == 'n' || temp[4] == 'N')){
        return true;
    } else {
        return false;
    }
}

bool endchecker(string temp){
    if ((temp[0] == 'e' || temp[0] == 'E') && (temp[1] == 'n' || temp[1] == 'N') && (temp[2] == 'd' || temp[2] == 'D')){
        return true;
    } else {
        return false;
    }
}

bool awalchecker(string temp){
    if (temp[0] == '/'  &&  temp[1] == '*'){
        return true;
    } else {
        return false;
    }
}

bool akhirchecker(string temp){
    if (temp[0] == '*'  &&  temp[1] == '/'){
        return true;
    } else {
        return false;
    } 
}
 
// Function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{
    // Declare a stack to hold the previous brackets.
    stack<char> temp;
    bool endvar = false;
    
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] != 'b' && expr[i] != 'B' && expr[i] != 'e' && expr[i] != 'E' && expr[i] != '/' && expr[i] != '*' && expr[i] != '(' && expr[i] != ')' && expr[i] != '{' && expr[i] != '}' && expr[i] != '[' && expr[i] != ']' ){
            cout<<"Inputan ngawur"<<endl;
            return 0;
        }
        if (temp.empty()) {
            // If the stack is empty
            // just push the current bracket
            temp.push(expr[i]);
            if (temp.top() == 'b' || temp.top() == 'B'){
                string sementara;
                for (int o = 0; o<5; o++){
                    sementara = sementara + expr[i+o];
                   // cout << sementara<< endl;
                    } if (beginchecker(sementara) == true){
                        i = i + 4;
                        continue;
                    } else {
                        cout<<"Error Penulisan Begin Salah"<<endl;
                        return 0;
                    }
                }
            if (temp.top() == '/'){
                string sementara;
                for (int o = 0; o<2; o++){
                    sementara = sementara + expr[i+o];
                   // cout << sementara<< endl;
                    } if (awalchecker(sementara) == true){
                        i = i + 1;
                        continue;
                    } else {
                        cout<<"Error Penulisan /* Salah"<<endl;
                        return 0;
                    }
            }
        }
        else if ((temp.top() == '(' && expr[i] == ')')
                 || (temp.top() == '{' && expr[i] == '}')
                 || (temp.top() == '[' && expr[i] == ']')) {
             
            // If we found any complete pair of bracket
            // then pop
            temp.pop();
        } else if (temp.top() == 'b' && (expr[i] == 'e' || expr[i] == 'E')){
            string sementara;
            for (int o = 0; o<3; o++){
                sementara = sementara + expr[i+o];
               // cout << sementara<< endl;
            }
            if (endchecker(sementara) == true){
                temp.pop();
                 i = i + 2;
            } else {
                cout<<"Error Penulisan end Salah"<<endl;
                return 0;
            }
        } else if (temp.top() == '/' && expr[i] == '*'){
            string sementara;
            for (int o = 0; o<2; o++){
                sementara = sementara + expr[i+o];
                //cout << sementara<< endl;
            }
            if (akhirchecker(sementara) == true){
                temp.pop();
                 i = i + 1;
            } else {
                cout<<"Error Penulisan */ Salah"<<endl;
                return 0;
            }
        }
        
        else{
            temp.push(expr[i]);
        }
        
        
    }
    if (temp.empty()) {
         
        // If stack is empty return true
        return true;
    }
    cout<<temp.top();
    return false;
}
 
// Driver code
int main()
{
    string expr;
    cin>> expr;
    // Function call
    if (areBracketsBalanced(expr))
        cout << "Aman Bosque";
    else
        cout << "Lho ga seimbang bosque";
    return 0;
}
