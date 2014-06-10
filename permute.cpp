#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

ofstream output;
int stop = 0;

void permute(int level, string permuted, int used[], string original, int len, string parse, string limit) {
	
	int length = original.length();
	
	
	
		//if (level == length) {
		if (level == len) {
			cout<<permuted<<"\n";
			output<<permuted<<endl;		
			if (limit==permuted){
				stop = 1;				
			}
		} else {
			int i = 0;
			if(!parse.empty()){			
				i = original.find(parse.at(level));		
			}
			for(;i < length; i++) {
				if (!used[i]) {
					//used[i] = 1;
					permute(level + 1, permuted+original.at(i), used, original, len, parse, limit);
					parse = "";
					//used[i] = 0;
					if(stop){
						break;
					}
				}				
			}
	
		}	
}

int main(){	
	int digit = 0;
	string input = "";
	string limit = "";
	string logName = "";
	
	string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}|:<>?-=[];,./";
	int used[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	cout<<"##################Permutasi###################"<<endl;
	cout<<"#Created by : harmansakran; ver:0.2#Wordlist Generator######"<<endl;
	cout<<endl;
	
	cout<<"#First step : insert Log Name with extension, ex : caca.txt"<<endl;
	cout<<"#Leave blank if u want use default name (log.txt)"<<endl;
	cout<<"Log Name : ";	
	getline(cin,logName);
	cout<<endl;
	
	cout<<"#Second step Start Position, ex : abc(sistem will start from abc)"<<endl;
	cout<<"#Leave blank if u want start from the begining, ex : aa, aaa, aaaa"<<endl;
	cout<<"Current Position : ";	
	getline(cin,input);
	cout<<endl;
	
	cout<<"#Third step End Position, ex : cba(sistem will be stop on cba position)"<<endl;
	cout<<"#Leave blank if u want sistem finish all permute"<<endl;
	cout<<"limit Position : ";	
	getline(cin,limit);
	cout<<endl;
	
	cout<<"#Fourd step digit, ex : 5 or 3(must be same with len start and end string)"<<endl;
	cout<<"#Not allow for empty"<<endl;
	cout<<"Permutation n digits : ";	
	cin>>digit;		
	
	if(logName.empty()){
		logName = "log.txt";
	}
	
	output.open(logName.c_str(), ios::app);
	if(!output){
		cout<<"File tidak dapat dibuka"<<endl;		
	}
	
	permute(0, "", used, s, digit, input, limit);
	output.close();
	return 0;
}
