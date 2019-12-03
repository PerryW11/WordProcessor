// Word Processor
// Created by Perry Winch
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::string;
/*
   Word separator: 
	   Words can be separated by space(s), punctuation, new line ('/n').
	   If a word is finished by '-' and is followed by a new line, 
	   the next word is part of the last word on the previous line 
	   and count only as one(hyphenated).

	uniqueWord: if true, only unique words are counted. 
	            A repeated word, will only count once.

	caseSensitive: if true, when comparing words for uniqueWord, the comparison is
				   case sensitive. Otherwise, it is not.

	WordProcessor.cpp : implementation of the countWords function

	WordProcessor.h    : the declaration of countWords

	WordProcessorTests  : unit tests to test countWords

*/

//Checks if the character in the string is considered a word seperator
bool isWordSeparator(char &c)
{
	return (!isalpha(c));
}

int countWords(string s, bool caseSensitive, bool uniqueWord)
{

	int wordCount = 0;
	string word;
	std::vector<string> words;

	if (s.empty())
	{
		return 0;
	}
	if (!(caseSensitive))
	{

		// using transform() function and ::toupper in STL
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);
		std::cout << s << std::endl;
	}

	for (unsigned int x = 0; x <= s.length(); x++)
	{
		if (!(isWordSeparator(s[x])) || (s[x] == '-' && s[x + 1] == '\n')) // Not considering "-\n" as a word seperator
		{

			x++; // proceed to the next char to check conditions again
			continue;
		}
		else
		{
			word += s[x];
		}
		bool inVector = false; //  As long as inVector is true, add the  string word to the vector words
		if (isWordSeparator(s[x]) && (word != ""))
		{
			if (uniqueWord)
			{
				if (find(words.begin(), words.end(), word) != words.end()) // Check if the word is found in the vector already
				{
					inVector = true;
					word = "";
				}
				else
				{
					inVector = false; // Will add word in next condition
				}
			}
			if (inVector == false) // Add to vector if false
			{
				words.push_back(word); // Add the completed word to the vector
				word = "";			   // Reset the word variable in order to add a new word
			}
		}
	}
	return words.size(); // Return the amount of words counted
}
