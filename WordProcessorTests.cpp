
#include <cassert>
#include "WordProcessor.h"

using std::cin;
using std::cout;
using std::endl;

void genericTests()
{
	assert(countWords("", false, false) == 0); // 0 words counted
	cout << "test #1 completed" << endl;

	assert(countWords("! $ ? . , : ;", false, false) == 0); // 0 words counted
	cout << "test #2 completed" << endl;

	assert(countWords("abc def", false, false) == 2); // 2 words counted
	cout << "test #3 completed" << endl;

	assert(countWords("abc   def", false, false) == 2); // 2 words counted
	cout << "test #4 completed" << endl;

	assert(countWords("abc\ndef", false, false) == 2); // 2 words counted
	cout << "test #5 completed" << endl;

	assert(countWords("abc-ndef", false, false) == 2); // 2 words counted
	cout << "test #6 completed" << endl;

	assert(countWords("abc-\nndef", false, false) == 1); // 1 word counted
	cout << "test #7 completed" << endl;

	assert(countWords("abc def def\nabc", false, false) == 4); // 4 words counted
	cout << "test #8 completed" << endl;

	assert(countWords("ab\nab!ab?ab:ab.ab;ab\nab", false, false) == 8); // 8 words counted
	cout << "test #9 completed" << endl;

	assert(countWords("ab\nAB!ab?AB:ab.AB;ab\nAB", true, true) == 2); // 2 words counted
	cout << "test #10 completed" << endl;

	assert(countWords("ab\nAb!aB?AB:ab.AB;ab\nAB\nZZZZ zzzz Zzzz\nzzzz", false, true) == 2); // 2 words counted
	cout << "test #11 completed" << endl;

	assert(countWords("Ab.Ba\nAb-\nAB:BA\nba;BA", true, false) == 6); //Testing for functionality of the
	cout << "test #12 completed" << endl;							  // hyphenated word with caseSensitivity being true

	assert(countWords("abc:DEF\naBc-dEf-\ngh.deFgH", false, true) == 3); //Testing for hyphenated word clause with uniqueWord true
	cout << "test #13 completed" << endl;

	assert(countWords("aB1abc2def3abc", false, true) == 3); //Testing numbers with uniqueWord true
	cout << "test #14 completed" << endl;

	assert(countWords("aB1abc2def3abc", true, false) == 4); //Testing numbers with caseSensitivity true
	cout << "test #15 completed" << endl;
}
