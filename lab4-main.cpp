// File: lab4-main.cpp
// Programmer: Eric Howard
// Description: Main Client File

#include <iostream>

using namespace std;

#include "recordsOffice.h"

int main(){ //int argc, char* argv[]){
    //string commandsFileName( "lab4-commands-short.tab");
    //string commandsFileName( "lab4-commands.tab");
    string commandsFileName( "lab4-commands-test.tab");

    recordsOffice records;
    cout << "Importing " << commandsFileName << endl;
    records.importRecords(commandsFileName);
    
    return 0;
}