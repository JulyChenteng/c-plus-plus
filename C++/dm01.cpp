#include <iostream>
using std::cout; 
using std::endl;

#include <string>
using std::string;

#include <regex>
using std::regex; using std::sregex_iterator; using std::smatch;

int main()
{
	// find the characters ei that follow a character other than c
	string pattern("[^c]ei");
	// we want the whole word in which our pattern appears
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";

	regex r(pattern); // construct a regex to find pattern
	smatch results;   // define an object to hold the results of a search

	// define a string that has text that does and doesn't match pattern
	string test_str = "receipt freind theif receive";

	// use r to find a match to pattern in test_str
	if (regex_search(test_str, results, r))				// if there is a match
		cout << results.str() << endl;					// print the matching word

	sregex_iterator it(test_str.begin(), test_str.end(), r);
	sregex_iterator end_it;   // end iterator
	for (; it != end_it; ++it)
		cout << it->str() << endl;						// print current match

	// alternative way to obtain all the matches in a given string
	auto it2 = test_str.cbegin();
	while (it2 != test_str.cend() &&
		regex_search(it2, test_str.cend(), results, r)) {
		cout << results.str() << endl;
		
		/* 
		reposition the iterator past any nonmatched part
		of the string plus the size of this match 
		*/
		it2 += results.prefix().length() + results.length();

	}

	return 0;
}
