#include <bits/stdc++.h>
using namespace std;

vector<string> mem, name;
vector<int> proc;
vector<bool> full;
int m;

int mem_rand(int am)
{
    vector<int> temp_num;
    bool flag = false;
    for (int i=0; i<proc.size(); i++)
        if (!full[i] && proc[i] >= am){
            flag = true;
            temp_num.push_back(i);
        }
    if (flag) return temp_num[rand() % temp_num.size()];
    else return -1;
}

void mem_insert(string str_n, int amount)
{
    int num = mem_rand(amount);
    if (num == -1) {
        cout << "Not enough memory.";
        system("pause");
        return;
    }
    proc[num] -= amount;
    proc.insert(proc.begin() + num, amount);
    full.insert(full.begin() + num, true);
    mem.insert(mem.begin() + num, "");
    name.insert(name.begin() + num, str_n);
}

int main()
{
    cout << "Enter the amount of memory: ";
    cin >> m;
    name.reserve(m);
    mem.reserve(m);
    proc.reserve(m);
    full.reserve(m);
    proc.push_back(m);
    full.push_back(false);
    name.push_back("");
    mem.push_back("");
    int p = 0;
    while (p != 4){
        system("cls");
        cout << "Memory info:" << endl << "The amount of memory: " << m << endl << "Name | Memory: String memory" << endl;
        for (int i=0; i<name.size(); i++)
            if (full[i]){
                cout << name[i] << " | " << proc[i] << ": " << mem[i] << endl;
            } else cout << "Free memory --> " << proc[i] << endl;
        cout << "Menu:" << endl << "1) Add a new process." << endl << "2) Edit string memory of process." << endl << "3) Delete process." << endl << "4) Close the program." << endl;
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
                cout << "Enter the amount of memory needed for the process: ";
                cin >> temp_m;
                mem_insert(temp_n, temp_m);
                break;
            }
        case 2:
            {
                cout << "Enter the name of the process: ";
                cin.ignore();
                getline(cin, temp_n);
                bool flag = false;
                for (int i=0; i<name.size(); i++)
                    if (name[i] == temp_n){
                        flag = true;
                        temp_m = i;
                        break;
                    }
                if (flag){
                    cout << "Enter a new string memory(the length of this string must be less than or equal to " << proc[temp_m] << "): ";
                    getline(cin, temp_n);
                    if (temp_n.length() <= proc[temp_m]) mem[temp_m] = temp_n;
                    else {
                    cout << "The length of this string is longer than " << proc[temp_m] << "." << endl;
                    system("pause");
                }
                } else {
                    cout << "There are no processes with that name." << endl;
                    system("pause");
                }
                break;
            }
        case 3:
            {
                cout << "Enter the name of the process: ";
                cin.ignore();
                getline(cin, temp_n);
                bool flag = false;
                for (int i=0; i<name.size(); i++)
                    if (name[i] == temp_n){
                        flag = true;
                        temp_m = i;
                        break;
                    }
                if (flag){
                    full[temp_m] = false;
                    for (int i=0; i<name.size() - 1; i++)
                        while ((i < name.size() - 1) && full[i] == false && full[i + 1] == false){
                            proc[i + 1] += proc[i];
                            proc.erase(proc.begin() + i);
                            full.erase(full.begin() + i);
                            mem.erase(mem.begin() + i);
                            name.erase(name.begin() + i);
                        }
                } else {
                    cout << "There are no processes with that name." << endl;
                    system("pause");
                }
                break;
            }
        }
    }
}
