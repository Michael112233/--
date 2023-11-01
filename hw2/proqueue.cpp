#include<cstdio>
#include<iostream>
#include<queue>
#include<string>

using namespace std;

struct Patient {
    int level, num;
    friend bool operator < (Patient p1, Patient p2) {
        if (p1.level == p2.level) 
            return p1.num > p2.num;
        return p1.level < p2.level;
    }
};

int main() {
    int n;
    while(cin >> n) {
        priority_queue<Patient> patient_list[10];
        string op;
        int a, b;
        int cnt = 0;
        for(int i=0; i<n; i++) {
            cin >> op;
            if(op == "IN") {
                cin >> a >> b;
                cnt++;
                Patient inputPatient;
                inputPatient.num = cnt;
                inputPatient.level = b;
                patient_list[a].push(inputPatient);
            } else {
                if (op == "OUT") {
                    cin >> a;
                    if (patient_list[a].size()) {
                        printf("%d\n", patient_list[a].top().num);
                        patient_list[a].pop();
                    }
                    else
                        puts("EMPTY");
                }    
            }
        }
    }
}