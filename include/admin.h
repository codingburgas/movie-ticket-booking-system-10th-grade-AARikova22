#pragma once
#include <iostream>
#include <string>

using namespace std;

class Admin {
public:
    bool login();
private:
    string correctUsername = "admin";
    string correctPassword = "password123";
};