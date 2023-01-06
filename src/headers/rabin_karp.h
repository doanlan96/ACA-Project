#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


#define D 256 // the number of characters in the alphabet
#define Q INT_MAX // A big prime number to avoid the collision 


// RABIN-KARP implementation
int search(char txt[] ,char pat[])
{
    int M = strlen(pat); 
    int N = strlen(txt); 
    int i, j;   // indexes
    int hash_p = 0; // hash value for pattern
    int hash_t = 0; // hash value for txt
    int h = 1; 
    int pat_appear = 0; // the number of the pattern appearance
 
    // The value of h would be "pow(R, M-1)%q"
    for (i = 0; i < M-1; i++){
        h = (h*D)%Q;
    }    
 
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++){
        hash_p = (D*hash_p + pat[i])%Q;
        hash_t = (D*hash_t + txt[i])%Q;
    }
 
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {   
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        if ( hash_p == hash_t )
        {
            // Check for characters one by one
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }
            // if p == t and pat[0...M-1] = txt[i...i+M-1]
            if (j == M)
                pat_appear++;
        }
 
        // Calculate hash value for next window of text:
        // Remove leading digit, add trailing digit
        if ( i < N-M )
        {
            hash_t = (D*(hash_t - txt[i]*h) + txt[i+M])%Q;
            // We might get negative value of t, converting it to positive
            if (hash_t < 0)
                hash_t = (hash_t + Q);
        }
    }
    // return the number of the pattern appearance in the given text string
    return pat_appear;
}
