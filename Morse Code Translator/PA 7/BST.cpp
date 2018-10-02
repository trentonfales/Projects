#include "BST.h"

BST::BST()
{
	mpRoot = nullptr;
	mInputStream.open("MorseTable.txt", ios::in);

	char line[100] = "";
	while (!mInputStream.eof())
	{
		char character = '\0';
		mInputStream.get(character);
		mInputStream.getline(line, 100);
		string codedCharacter = line;
		insert(character, codedCharacter);
	}

	mInputStream.close();
}

BST::~BST()
{
	delete mpRoot;
}

void BST::insert(char character, string codedCharacter)
{
	insert(this->mpRoot, character, codedCharacter);
}

void BST::insert(BSTNode *& pTree, char character, string codedCharacter)
{
	if (pTree == nullptr)
	{
		BSTNode *pMem = new BSTNode(character, codedCharacter);
		pTree = pMem;
	}
	else if (character < (pTree)->getCharacter())
	{
		insert(pTree->getLeft(), character, codedCharacter);
	}
	else
	{
		insert(pTree->getRight(), character, codedCharacter);
	}
}

void BST::print()
{
	print(this->mpRoot);
}

void BST::print(BSTNode *pTree)
{
	if (pTree != nullptr)
	{
		print(pTree->getLeft());
		cout << pTree->getCharacter() << " ";
		print(pTree->getRight());
	}
}

string BST::search(char character)
{
	string codedCharacter = search(this->mpRoot, character);
	return codedCharacter;
}

// toupper() found from http://www.cplusplus.com/reference/cctype/toupper/
string BST::search(BSTNode *pTree, char character)
{
	character = toupper(character);
	while (pTree != nullptr && pTree->getCharacter() != character)
	{
		if (character < pTree->getCharacter())
		{
			pTree = pTree->getLeft();
		}
		else 
		{
			pTree = pTree->getRight();
		}
	}
	return pTree->getCodedCharacter();
}