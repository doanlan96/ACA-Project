#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "../headers/read_file.h"
#include "../headers/rabin_karp.h"

int main(int argc, char *argv[])
{
    // remove lines from the texts and print their sizes
    system("python3 ../clean_data/remove_lines_for_serial.py");		
	string txt = read_file( "./genome_human_single_line.txt" );
	string pat = read_file( "./pattern_human_single_line.txt" );
    cout<<"size of the full text: "<<txt.length()<<" and the "<<"size of the pattern: "<<pat.length()<<endl;

    // clock ticking
    clock_t start = clock();
    int pat_appear = search((char*)txt.c_str(), (char*)pat.c_str());
    clock_t finish = clock();
    double exec_time = double(finish - start)*1000 / CLOCKS_PER_SEC;
    system("rm genome_human_single_line.txt  pattern_human_single_line.txt");

    // print the result
    cout<<"Found: "<<pat_appear<<" pattern appearance(s)"<<" in "<<exec_time<<" milliseconds."<<endl;
    return 0;
}