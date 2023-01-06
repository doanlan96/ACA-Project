#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "../headers/read_file.h"
#include "../headers/rabin_karp.h"

int main(int argc, char *argv[])
{
    // system("clear");
	// system(("py ../clean_data/remove_nl.py "+string(argv[1])).c_str());
	// system(("py ../clean_data/remove_nl.py "+string(argv[2])).c_str());
    system("py ../clean_data/remove_nl.py");		
	string txt = read_file( "./genome_no_new_line.txt" );
	string pat = read_file( "./pat_no_new_line.txt" );
	system("del genome_no_new_line.txt  pat_no_new_line.txt");

    cout<<"size of the full text: "<<txt.length()<<" and the "<<"size of the pattern: "<<pat.length()<<endl;



    clock_t begin = clock();

    int pat_appear = search((char*)txt.c_str(), (char*)pat.c_str());
    clock_t end = clock();
    double elapsed_secs = double(end - begin)*1000 / CLOCKS_PER_SEC;

    cout<<"Found: "<<pat_appear<<" pattern appearance(s)"<<" in "<<elapsed_secs<<" milliseconds."<<endl;
    return 0;
}