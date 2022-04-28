#include <bits/stdc++.h>
using namespace std;

map<int, pair<string, bool> > proc;
vector<int> mem;

int m, n, t, t_n;

void proc_call()
{
    if (t == 0 && proc.size() > t_n){
        t = 2;
        t_n++;
    }
    vector<int> free_proc, any_proc;
    cout << "Virtual memory: ";
    for (auto& i : proc)
        if (!i.second.second) {free_proc.push_back(i.first); cout << i.first << ' ';}
        else any_proc.push_back(i.first);
    cout << endl;
    if (free_proc.size() == 0){
        cout << "All processes have their place in memory." << endl;
        cout << "Memory info:" << endl << "Process number called: " << any_proc[rand() % any_proc.size()] << endl << "(position in queue)Number: Name" << endl;
        for (int i=0; i<mem.size(); i++){
            cout << "(" << i << ")" << mem[i] << ": " << proc[mem[i]].first << endl;
        }
        system("pause");
        return;
    }
    int r_proc = free_proc[rand() % free_proc.size()];
    if (mem.size() == t_n){
        proc[mem[0]].second = false;
        mem.erase(mem.begin());
        mem.push_back(r_proc);
        proc[r_proc].second = true;
    } else {
        mem.push_back(r_proc);
        proc[r_proc].second = true;
    }
    cout << "Memory info:" << endl << "Process number called: " << r_proc << endl << "(position in queue)Number: Name" << endl;
    for (int i=0; i<mem.size(); i++){
        cout << "(" << i << ")" << mem[i] << ": " << proc[mem[i]].first << endl;
    }
    t--;
    system("pause");
}

int main()
{
    cout << "Enter the amount of memory: ";
    cin >> m;
    cout << "Enter number of pages: ";
    cin >> n;
    if (m % n != 0) cout << m << " is not a multiple of " << n << ". So some memory will be wasted." << endl;
    system("pause");
    int p = 0;
    while (p != 4){
        system("cls");
        cout << "Virtual memory info:" << endl << "The amount of memory: " << m - (m % n) << endl << endl << "Number: Name" << endl;
        for (auto& i : proc) {
            cout << i.first << ": " << i.second.first << endl;
            i.second.second = false;
        }
        cout << endl << "Menu:" << endl << "1) Add a new process." << endl << "2) Start the program." << endl << "3) Delete process." << endl << "4) Close the program." << endl;
        cin >> p;
        system("cls");
        string temp_n;
        int temp_m = 0;
        switch(p){
        case 1:
            {
                cout << "Enter the name of the new process: ";
                cin.ignore();
                getline(cin, temp_n);
                cout << "Enter the number of this process: ";
                cin >> temp_m;
                proc[temp_m] = make_pair(temp_n, false);
                break;
            }
        case 2:
            {
                cout << "Enter the request threshold at which the number of pages will increase(after the the memory is full): ";
                cin >> t;
                t += n;
                t_n = n;
                int temp = rand() % 30;
                mem.clear();
                for (int i=0; i<=temp; i++) {
                    system("cls");
                    cout << "Iterations left: " << temp - i << endl;
                    proc_call();
                }
                break;
            }
        case 3:
            {
                cout << "Enter the number of the process: ";
                cin >> temp_m;
                auto it = proc.find(temp_m);
                if (it != proc.end()){
                    proc.erase(it);
                } else {
                    cout << "There are no processes with that name." << endl;
                    system("pause");
                }
                break;
            }
        }
    }
}
