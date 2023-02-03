#include <bits/stdc++.h>
#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "../headers/read_file.h"
#include "../headers/rabin_karp.h"

#define TAG 555
#define SEPARATOR "&"


int main (int argc, char *argv[]) {
	//Initialize MPI common
	MPI_Status status;
	int my_rank, size, ret_val;	

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	//Master initialization
	if (my_rank == 0){ 
	
		system("py ../clean_data/remove_lines_for_parallel.py");
		string txt = read_file( "./genome_single_line.txt" );
		string pat = read_file( "./pat_single_line.txt" );
		system("del genome_single_line.txt  pat_single_line.txt");


    	long int N = txt.length();
    	int M = pat.length();
		int pay_load_size = (int)(N/(size-1));

		clock_t t = clock();

		cout<<"size of the full text: "<<N<<" and the "<<"size of the pattern: "<<M<<endl;

		// master sends a 'subtext'  to each of the slaves
		long int offset = 0;
		for (int p = 1; p < size; ++p)
		{	
			string subtxt = txt.substr(offset, payLoadSize);
			string message = string(subtxt)+SEPARATOR+string(pat)+"\0";
			// cout<<"number of elements in the message: "<<message.length()<<"\n"; 

		    ret_val = MPI_Send(message.c_str(),  message.length() , MPI_CHAR, p, TAG, MPI_COMM_WORLD);
			offset += pay_load_size;
		}

		int result;
		int results=0;
		// master receives results from slaves
		for (int p = 1; p < size; ++p){
            //int result;
			MPI_Recv(&result, 1, MPI_INT, p, TAG, MPI_COMM_WORLD, &status);
			results+=result;
		}
		double millisecs = 1000* double(clock() - t)/CLOCKS_PER_SEC;
		//END MASTER
		cout<<"Found: "<<results<<" occurences"<<" in "<<millisecs<<" milliseconds."<<endl;
	}
	
	//Slaves initialization
	if(my_rank != 0){
		// Dynamic probing of incoming message size. 
		// Probe for an incoming message from master
		MPI_Status status;
		MPI_Probe(0, TAG, MPI_COMM_WORLD, &status);
		
	    // When probe returns, the status object has the size and other
        // attributes of the incoming message. Get the message size
		int message_size; //size of the incoming string
        MPI_Get_count(&status, MPI_CHAR, &message_size);
	
		// Allocate a buffer to hold the incoming chars
		int num_bytes = sizeof(char)*(message_size);
		
		char* buf = (char*)malloc(num_bytes);
		
		ret_val = MPI_Recv(buf, message_size, MPI_CHAR, 0, TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);


		// split into subtext and pattern
		char* pattern;
    	char* text;
		// get subtext
		text = strtok(buf, SEPARATOR);
		// get pattern
		pattern = strtok(NULL, SEPARATOR);

		// search for pattern appearances
		int result = search(text, pattern);

		cout<<"Slave of rank: "<<my_rank<<" subtext hash: "<<hasher(text)<<" length of the string: "<<strlen(text)<<endl;

		// send the result back to the master
		ret_val = MPI_Send(&result, 1, MPI_INT, 0, TAG, MPI_COMM_WORLD);
		free(buf);
		cout<<"";
	}
	//End
	MPI_Finalize();
    return 0;
}