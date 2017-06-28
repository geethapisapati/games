/*
 * main.cpp
 *
 *  Created on: Jun 26, 2017
 *      Author: geetha_sumant
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include <sstream>
#include <unordered_map>

using namespace std;
int main() {
	cout << "Welcome! Please enter your name: ";
	string name = "";
	cin >> name;
	cin.ignore();
	vector<string> words;
	vector<string> meanings;
	unordered_map<string, vector<string> > dict;
	string line;
	ifstream infile;
	infile.open("/Users/geetha_sumant/Documents/geetha_apps/geetha_c++/WordQuiz/wordlist3.txt");
	cout << "***********************************" << endl;
	cout << name << ", Welcome to the vocab quiz!"  << endl;
	cout << "To quit the quiz type 'q' at any time" << endl;
	cout << "***********************************" << endl;

	if(!infile) {
		cerr << "Unable to open file words.txt";
		exit(1);
	}
	regex e("([A-Za-z]*)([\\s]*)([A-Za-z-;\\s]*)");
	string tok = "";
	char delimiter = ';';


	while (getline(infile,line)) {
		smatch m,m1;
		regex_search(line,m,e);
		string w = m[1].str();
	    words.push_back(w);
	    stringstream mean(m[3].str());
	    while( getline(mean,tok,delimiter)) {
	    	dict[w].push_back(tok);
	    }
	}
	unordered_map<string, vector<string> >::iterator it;
	/*string ans = "Enfranchise";
	it = dict.find(ans);
	cout << it->second.size() << endl;
	cout << it->first << ": ";
	for(int i=0; i<it->second.size(); i++) {
		cout << it->second[i] << " ";
	}*/

	int correct = 0;
	int score = 0;
	string ans;
	for(int i=0; i<words.size(); i++) {
		correct = 0;
		string wd = words[i];
		cout << i+1 << ") " << words[i] << ":";
		getline(cin, ans);
		if(ans == "q") {
			cout << "***********************************" << endl;
			cout << "Score for "<< name << ": " << score << " out of " << i+1 << endl;
			cout << "***********************************" << endl;
			return 0;
		} else  {
			//cout << ans << endl;
			it = dict.find(wd);
			for(int j=0;j<it->second.size();j++) {
				if(ans == it->second[j])
				correct++;
			}
			if(correct > 0) {
				cout << "Right";
				score++;
			} else
				cout << "Wrong";
			cout << endl << endl;
		}
	}

	return 0;
}


