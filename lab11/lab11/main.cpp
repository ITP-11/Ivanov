#include <bits/stdc++.h>
using namespace std;

map<string, int> files;

string login = "saliman", password = "anime";
int mem, mem_took = 0;

int main()
{
    string temp = "";
    while (1){
        cout << "To get access to files you need to login." << endl << "Enter your login: ";
        cin >> temp;
        if (login == temp){
            cout << "Enter your password: ";
            cin >> temp;
            if (password == temp){
                system("cls");
                cout << "Login complete!" << endl;
                system("pause");
                break;
            }
            system("cls");
            cout << "Incorrect password" << endl;
        }
        system("cls");
        cout << "Incorrect login" << endl;
    }

    cout << "Enter the amount of memory needed for files: ";
    cin >> mem;

    int p = -1;
    while (p != 0){
        system("cls");
        cout << "Menu:" << endl << "1) Add a file." << endl << "2) Look through the files." << endl << "3) Delete the file." << endl << "0) Close the program." << endl;
        cin >> p;
        if (p >= 1 && p <= 3){
            string name;
            int mem_temp;
            switch (p) {
            case 1:
                {
                    system("cls");
                    cout << "Enter the name of the file: ";
                    cin.ignore();
                    getline(cin, name);
                    if (files.find(name) != files.end()){
                        cout << "File with this name already exists." << endl << "Do you want to replace it?" << endl << "1) Yes." << endl << "2) No." << endl;
                        int choise;
                        cin >> choise;
                        cout << "Enter the amount of memory it will take: ";
                        cin >> mem_temp;
                        if (choise == 1){
                            if ((mem_took - files[name] + mem_temp) <= mem){
                                mem_took -= files[name];
                                files[name] = mem_temp;
                                mem_took += mem_temp;
                            }
                            else {
                                system("cls");
                                cout << "Out of memory";
                                system("pause");
                            }
                        } else {
                            if (mem_took + mem_temp <= mem) {
                                while (files.find(name) != files.end()) name += "#";
                                files[name] = mem_temp;
                                mem_took += mem_temp;
                            } else{
                                system("cls");
                                cout << "Out of memory";
                                system("pause");
                            }
                        }
                    } else {
                        cout << "Enter the amount of memory it will take: ";
                        cin >> mem_temp;
                        if (mem_took + mem_temp <= mem) {
                            files[name] = mem_temp;
                            mem_took += mem_temp;
                        } else{
                            system("cls");
                            cout << "Out of memory";
                            system("pause");
                        }
                    }
                    break;
                }
            case 2:
                {
                    system("cls");
                    cout << "Files info:" << endl << "Free memory: " << mem - mem_took << endl << "Name: Memory taken" << endl;
                    for (auto& i : files) cout << i.first << ": " << i.second << endl;
                    system("pause");
                    break;
                }
            case 3:
                {
                    system("cls");
                    cout << "Enter the name of the file: ";
                    cin.ignore();
                    getline(cin, name);
                    if (files.find(name) != files.end()) files.erase(name);
                    else {
                        cout << "There are no files with this name." << endl;
                        system("pause");
                    }
                    break;
                }
            }
        }
    }
}
