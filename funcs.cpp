#include <iostream>
#include "funcs.h"
#include <cctype>
#include <cmath>
#include <vector>

// add functions here
char shiftChar(char c, int rshift) {
    int a = c + rshift;
    if(isupper(c)) {
        if(a > 90) {
            a -= 26;
        }
    } else {
        if(a > 122) {
            a -= 26;
        }
    }

    return a;
}

std::string encryptCaeser(std::string plaintext, int rshift){
    std::string result;
    for(int i = 0; i<plaintext.size(); i++) {
        if(isalpha(plaintext[i])) {
            result += shiftChar(plaintext[i], rshift);
        } else {
            result += plaintext[i];
        }
    }
    return result;
}

std::string solve(std::string encrypted_string) {
	std::vector <double> actualFrequency {.084966,.020720,.045388,.033844,.111607,.018121,
    .024705,.030034,.075448, .001964, .011016, .054893, .030129, .066544, .071635, .031671,
    .001962, .075809, .057351, .069509, .036308, .010074, .012899, .002902, .017779, .002722
     };
	
	std::vector <double> frequency (26);
	double minScore = -1;
	int rot = 10;
	for(int i = 1; i < 27; i++) {
		std::string rotated = encryptCaeser(encrypted_string, i);
		int total = 0;
    	for(int i = 0; i < rotated.length(); i++){
        	char l = rotated[i];
        	if(isalpha(l)) {
            	if(l > 96) {
                	l -= 97;
            	} else if(l > 64) {
               		l -= 65;
            	}
            	frequency[l] += 1;
            	total++;
        	}
    	}

		double score = 0;
    	for(int i = 0; i < frequency.size(); i++) {
        	frequency[i] = (double)frequency[i] / (double)total;
        	if(frequency[i] != 0) {
            	score += std::abs(frequency[i] - actualFrequency[i]);
        	}
    	}
		
		if(minScore == -1) {
			minScore = score;
			rot = i;
		} else {
			if(score < minScore) {
				minScore = score;
				rot = i;
			}
		}			
	}
	return encryptCaeser(encrypted_string, rot);
}        
