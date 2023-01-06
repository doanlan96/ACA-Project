#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//Read all the content in .txt file and return it as 'string'.
string read_file(string pathname){
    fstream file;
    stringstream buffer;
    string content = "";
    file.open(pathname, ios::in); //open file to read using file object
    if (file.is_open()){ //check if the file is opened
        buffer << file.rdbuf();
        content = buffer.str();
    }
    file.close(); // close the file object        
    return content;
}

