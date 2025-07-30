#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include<bits/stdc++.h> 
using namespace std;

const double PI = 3.1415926;
const double RADIUS = 50.0;

int main() {
    int T;
    cin >> T;
    cin.ignore(); 
    
    cout << fixed << setprecision(10); 
    
    for (int i = 0; i < T; i++) {
        string input;
        getline(cin, input);
        
        int x = input[0] - '0';
        char op = input[1];
        int y = input[2] - '0';
        
        double length;
        
        if (op == 'v') {
           
            length = 2 * RADIUS;
        } else if (op == '-') { 
            int delta = abs(x - y);
            delta = min(delta, 8 - delta); 
            double angle = delta * PI / 4.0; 
            length = 2 * RADIUS * sin(angle / 2);
        } else if (op == '>') {
            
            int delta = (y - x + 8) % 8;
            double angle = delta * PI / 4.0;
            length = RADIUS * angle;
        } else if (op == '<') {
           
            int delta = (x - y + 8) % 8;
            double angle = delta * PI / 4.0;
            length = RADIUS * angle;
        }
        
        cout << length << endl;
    }
    
    return 0;
}
