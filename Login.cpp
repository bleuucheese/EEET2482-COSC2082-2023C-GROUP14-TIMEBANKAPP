#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include "users.cpp"   
using std::cout;
using std::cin;

static const std::filesystem::path USER_FILE_PATH = std::filesystem::current_path() / "users.txt";

void promptLogin() {
    User user;
    cout << "=====LOGIN PAGE=======\n";
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
}

int main() {
    
    return 0;
}