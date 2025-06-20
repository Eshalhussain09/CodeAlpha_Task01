//#include <iostream>
//#include <fstream>
//#include <string>
//#include <iomanip>
//using namespace std;
//
//bool usernameExists(const string& username) 
//{
//    ifstream file("users.txt");
//    string u, p;
//    while (file >> u >> p) 
//    {
//        if (u == username)
//        {
//            return true;
//        }
//    }
//    return false;
//}
//
//void registerUser() {
//    string username, password;
//
//    cout << "\n Registration\n";
//    cout << "Enter username: ";
//    cin >> username;
//
//    if (usernameExists(username)) 
//    {
//        cout << " Username already exists. Try a different one.\n";
//        return;
//    }
//
//    cout << "Enter password: ";
//    cin >> password;
//
//    ofstream file("users.txt", ios::app);
//    file << username << " " << password << endl;
//
//    cout << "Registration successful!\n";
//}
//
//bool loginUser() {
//    string username, password;
//
//    cout << "\n Login\n";
//    cout << "Enter username: ";
//    cin >> username;
//    cout << "Enter password: ";
//    cin >> password;
//
//    ifstream file("users.txt");
//    string u, p;
//    while (file >> u >> p) {
//        if (u == username && p == password) 
//        {
//            cout << " Login successful. Welcome, " << username << "!\n";
//            return true;
//        }
//    }
//
//    cout << " Login failed. Invalid username or password.\n";
//    return false;
//}
//
//int main() 
//{
//    int choice;
//
//    do 
//    {
//        cout << "\n=== MENU ===\n";
//        cout << "1. Register\n";
//        cout << "2. Login\n";
//        cout << "3. Exit\n";
//        cout << "Choose an option: ";
//        cin >> choice;
//
//        switch (choice) 
//        {
//        case 1:
//            registerUser();
//            break;
//        case 2:
//            loginUser();
//            break;
//        case 3:
//            cout << "Exiting... Goodbye!\n";
//            break;
//        default:
//            cout << "Invalid choice. Try again.\n";
//        }
//    } while (choice != 3);
//
//    return 0;
//}
