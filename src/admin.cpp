#include "../include/admin.h"

bool Admin::login() { // Authenticates admin by comparing entered credentials with stored ones
    string username, password;
    cout << "Enter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    cin >> password;

    if (username == correctUsername && password == correctPassword) {
        cout << "Login successful!" << endl;
        return true;
    }
    else {
        cout << "Invalid username or password." << endl;
        return false;
    }
}