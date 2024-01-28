#include <iostream>
#include <fstream>

using namespace std;

struct Skier
{
    char name [32] = "";
    char surname [32] = "";
    char country [4] = "";
    double time = -1;
    bool active = true;
};


void checkFile() {
    fstream file;
    file.open("ski.dat", ios::in);
    if (!file.good()) {
        cout << "File not found, creating..." << endl;
        file.close();
        file.open("ski.dat", ios::out);
        file.close();
        file.open("ski.dat", ios::in);
        if (!file.good()) {
            cout << "File creation failed, exiting..." << endl;
            exit(1);
        }
        cout << "File created successfully" << endl;
    }
}

int menu() {
    int choice;
    cout << "1. Add a new skier" << endl;
    cout << "2. Display all skiers" << endl;
    cout << "3. Edit skier" << endl;
    cout << "4. Enter time for skier" << endl;
    cout << "5. Delete skier" << endl;
    cout << "6. Sort and show skiers" << endl;
    cout << "7. Exit" << endl;
    cin >> choice;
    return choice;
}

void newSkier() {
    Skier skier;
    cout << "Enter surname: ";
    cin >> skier.surname;
    cout << "Enter name: ";
    cin >> skier.name;
    cout << "Enter country code: ";
    cin >> skier.country;
    ofstream file;
    file.open("ski.dat", ios::binary|ios::out|ios::app);
    file.write((char*)&skier, sizeof(Skier));
    file.close();
    cout << "Skier " << skier.surname << ", " << skier.name << " from " << skier.country << " added!" << endl;
    return;
}

void printSkiers() {
    ifstream file;
    Skier skier;
    char cont;
    file.open("ski.dat", ios::in|ios::binary);
    while (file.read((char*)&skier, sizeof(Skier)))
    {
        cout << "Surname: " << skier.surname << endl << "   Name: " << skier.name << endl << "Country: " << skier.country << endl << "   Time: " << skier.time << endl;
        cin.get();
        // TODO: wait on user enter
    }
    file.close();
}

void editSkier() {
    fstream file;
    Skier skier, newSkier;
    char choice;
    int id = 0;
    cout << "Input skier id: ";
    cin >> id;
    //id -= 1;
    file.open("ski.dat", ios::in|ios::binary|ios::out);
    file.read((char*)&skier, sizeof(skier)*id);
    cout << "Edit " << skier.surname << ", " << skier.name << " (" << skier.country << ")? (Y/N)";

    cin >> choice;
    if (choice != 'Y' && choice != 'y') {
        return;
    }
    cout << "Current surname: " << skier.surname << endl << "    New surname: ";
    cin >> newSkier.surname;
    cout << "Current name: " << skier.name << endl << "    New name: ";
    cin >> newSkier.name;
    cout << "Current country: " << skier.country << endl << "    New country: ";
    cin >> newSkier.country;
    cout << "Current time: " << skier.time << endl << "    New time: ";
    cin >> newSkier.time;
    cout << endl << "Before edit: " << skier.surname << ", " << skier.name << " (" << skier.country << ") - " << skier.time << "s.";
    cout << endl << " After edit: " << newSkier.surname << ", " << newSkier.name << " (" << newSkier.country << ") - " << newSkier.time << "s." << endl;
    cout << "Save edits? (Y/N)";
    cin >> choice;
    if (choice != 'Y' && choice != 'y') {
        return;
    }
    file.write((char*)&newSkier, sizeof(skier)*id);
    file.close();
    cout << "Changes were succesfully made!" << endl;
    return;
}

void editTime () {
    fstream file;
    Skier skier;
    char choice;
    int id = 0;
    cout << "Input skier id: ";
    cin >> id;
    //id -= 1;
    file.open("ski.dat", ios::in|ios::binary|ios::out);
    file.read((char*)&skier, sizeof(skier)*id);
    cout << "Edit " << skier.surname << ", " << skier.name << " (" << skier.country << ")? (Y/N)";
    Skier newSkier = {*skier.surname, *skier.name, *skier.country};
    cin >> choice;
    if (choice != 'Y' && choice != 'y') {
        return;
    }
    cout << "Current time: " << skier.time << endl << "    New time: ";
    cin >> newSkier.time;
    cout << endl << "Before edit: " << skier.surname << ", " << skier.name << " (" << skier.country << ") - " << skier.time << "s.";
    cout << endl << " After edit: " << newSkier.surname << ", " << newSkier.name << " (" << newSkier.country << ") - " << newSkier.time << "s." << endl;
    cout << "Save edits? (Y/N)";
    cin >> choice;
    if (choice != 'Y' && choice != 'y') {
        return;
    }
    file.write((char*)&newSkier, sizeof(skier)*id);
    file.close();
    cout << "Change was succesfully made!" << endl;
    return;
}

int main()
{
    checkFile();
    cout << "Hello World" << endl;
    do {
        switch (menu()) {
        case 1:
            newSkier();
            break;
        case 2:
            printSkiers();
            break;
        case 3:
            editSkier();
            break;
        case 4:
            editTime();
            break;
        case 5:
            cout << "Delete skier" << endl;
            break;
        case 6:
            cout << "Sort and show skiers" << endl;
            break;
        case 7:
            cout << "Sure? (Y/N)" << endl;
            char choice;
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                cout << "Exiting..." << endl;
                exit(0);
            }
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    while (true);
    return 0;
}