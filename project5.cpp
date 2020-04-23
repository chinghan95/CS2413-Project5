#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <iterator>
#include <algorithm>  // for sort function
using namespace std;

// Utility comparator function to pass to the sort() module
// Ref: https://www.educative.io/edpresso/how-to-sort-a-map-by-value-in-cpp
bool sortByVal(const pair<string, int>& a, const pair<string, int>& b) {
	return (a.second > b.second);
}

int main(int argc, char* argv[]) {

	string fileName = argv[1];
	ifstream myInputFile;
	string token;
	char aChar;
	myInputFile.open(fileName);

	// Declaring map to be of <String, int> type key will be of string 
	// type and mapped value will be of int type
	map<string, int> tokenMap;
	multimap<int, string, greater<int>> newMap;
	map<string, int> sortedMap;

	while (myInputFile >> aChar) {
		while ((!myInputFile.eof()) && ((aChar == ' ') || (aChar == '\n'))) {
			myInputFile.get(aChar);
		}
		if (!myInputFile.eof()) {
			token.clear();
			while ((!myInputFile.eof()) && ((aChar != ' ') && (aChar != '\n'))) {
				token += aChar;
				myInputFile.get(aChar);
			}
		}

		// If key not fount in map iterator to end is returned
		if (tokenMap.find(token) == tokenMap.end()) {
			tokenMap.insert({ token, 1 });
			//cout << token << " not found.\n";
		}
		// If key is found in map, increase the frequencies of key
		else {
			//cout << token << " found in the tokenMap.\n";
			tokenMap[token]++;
		}
		//cout << token << endl;
	}

	// Close the file
	myInputFile.close();
	
	for (auto const& p : tokenMap)
		newMap.insert({ p.second, p.first });
	for (auto const& pair : newMap) {
		//cout << "{" << pair.first << ": " << pair.second << "}\n";
		cout << pair.second << " ";
	}
	cout << " " << endl;

	////////////////////////////////////////////////////////////////////////

	myInputFile.open(fileName);
	//cout << "Find the position of token.\n";
	while (myInputFile >> aChar) {
		while ((!myInputFile.eof()) && ((aChar == ' ') || (aChar == '\n'))) {
			myInputFile.get(aChar);
		}
		if (!myInputFile.eof()) {
			token.clear();
			while ((!myInputFile.eof()) && ((aChar != ' ') && (aChar != '\n'))) {
				token += aChar;
				myInputFile.get(aChar);
			}
			// Print the index of token in sorted token map.
			int idx = 0;
			for (auto const& pair : newMap) {
				idx++;
				if (token.compare(pair.second) == 0) {
					cout << idx << " ";
				}
			}
		}

	}
	cout << " " << endl;
	return 0;
}