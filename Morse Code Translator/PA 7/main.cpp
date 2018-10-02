/**********************************************************************************************
* Programmer: Trenton Fales                                                                   *
* Class: CptS 122 Spring 2018; Lab Section 9                                                  *
* Programming Assignment: 7                                                                   *
* Date: April 4th, 2018                                                                       *
*                                                                                             *
*                                                                                             *
* Description: This program opens the file "Convert.txt" which consists of English text, and  *
*              converts the file to Morse Code and displays the result out to the screen. It  *
*              also displays the binary search tree used to convert the English characters to *
*              Morse Code.                                                                    *
**********************************************************************************************/

#include "BST.h"

int main(void)
{
	fstream file;
	file.open("Convert.txt");

	BST tree;
	cout << "Current Tree: (In-Order Traversal)" << endl;
	tree.print();
	cout << endl << endl;

	while (!file.eof())
	{
		char character = '\0';
		file.get(character);
		if (character == ' ')
		{
			cout << "   ";
		}
		else if (character == '\n')
		{
			cout << endl;
		}
		else if (file.eof())
		{
			cout << endl;
			break;
		}
		else
		{
			cout << tree.search(character);
		}
	}

	file.close();

	return 0;
}