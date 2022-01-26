/********************************************************/
/*          TRIE TREE  ADT                               */
/********************************************************/
#pragma once
#include<iostream>
#include<string.h>
#include<string>
#include<fstream> //for file handling
using namespace std;

fstream file;

/********************************************************/
/*              Node Class                              */
/********************************************************/
class Node {
public:
	//public data members
	bool isEnd;
	Node* children[26];
	string meaning;

	Node() //ctor
	{
		isEnd = false;
		meaning = "";
	}
};

//create() for creating a trie tree node with 26 childrens
Node* create()
{
	Node* newNode = new Node;
	for (int i = 0; i < 26; i++)
		newNode->children[i] = NULL;

	newNode->isEnd = false;
	return newNode;
}
/********************************************************/
/*              Trie Class                              */
/********************************************************/

class Trie {
	//private data members
	Node* root; //for storing the root of the tree
	string suggestions[3]; //for storing suggestions 
	int suggestCount; //for storing the count of the suggestions

	//loads the dictionary from "Dictionary.txt" file
	void loadDictionary()
	{
		//create and read the file 
		fstream file;
		file.open("Dictionary.txt", ios::in);

		if (file.is_open()) //if file opened 
		{
			string word; //for storing the word
			string meaning; //for storing the meaning

			while (!file.eof()) //read file till the end 
			{
				getline(file, word);
				getline(file, meaning);
				insertNode(root, word, meaning); //insert the word along with it's meaning in the Dictionary(trie tree)
			}
		}
		file.close(); //close the file 
	}

	/* updates the file */
	void updateFile(string word, string meaning)
	{
		file << endl << word << endl << meaning;
	}

	/* inserts a word in the tree */
	void insertNode(Node*& node, string word, string means)
	{
		Node* curr = root; //curr node for traversing the tree

		for (int i = 0; i < word.length(); i++)//loop over all the characters in the tree
		{
			// word[i] - 'a' = for getting the index by subtracting the ascii values of the characters 

			//if the index at    this    index is null, create one 
			if (curr->children[word[i] - 'a'] == NULL) // c-'a' =  a= 65, subtracting a's decimal value to get the index of the current character 
				curr->children[word[i] - 'a'] = create();

			curr = curr->children[word[i] - 'a']; //goto the children of curr
		}
		curr->isEnd = true; // mark the end of the word
		curr->meaning = means; //store the meaning 

	}


	/* Traverses the tree recursively and prints every word in the tree */
	void traverse(string& str, Node* node)
	{
		if (node->isEnd) //if end of the word, print the word
			cout << endl << str;

		for (char index = 0; index < 26; ++index)
		{
			Node* child = node->children[index];  //for storing the child of node at index 'index'
			char ch = 'a' + index; //get the character 

			if (child)
			{
				str.push_back(ch); // store the ch in string
				traverse(str, child);
				str.pop_back(); //remove the last character 

			}
		}
	}
	/* for seraching for a word from the tree */
	bool searchWord(string& word)
	{
		Node* current = root;//current node for traversing the tree

		for (int i = 0; i < word.length(); i++)//till the lenth of the word
		{
			if (current->children[word[i] - 'a'] == NULL) //if no further children found
				return false;

			current = current->children[word[i] - 'a'];//goto the next child
		}

		if (current->isEnd) //if the word ended, it means it's found
		{
			//store the recent 3 searched words in suggestions 
			suggestions[suggestCount % 3] = word;
			suggestCount++;
			return true; //return true 

		}
		return false; //else not found 
	}

	/*for deleting a word from the tree*/
	void DeleteWord(string word, Node*& node, int level)
	{
		if (!node) return; //if null node found
		if (level == word.length())
		{
			if (node->isEnd) //word found, mark 'isEnd' as false so that we can delete it 
				node->isEnd = false;

			if (isEmpty(node)) //if depth is the same as the length of the word
			{
				delete node; //delete the current node 
				node = NULL;
			}
			return;
		}

		DeleteWord(word, node->children[word[level] - 'a'], level + 1); //goto the next level 

		if (isEmpty(node) && node->isEnd == false)
		{
			delete node;
			node = NULL;
		}
		return;
	}

	/* deletes every node of the tree */
	void destroyTrie(Node*& node)
	{
		if (node) //if node is not null
		{
			if (node->isEnd) //if end of word found, delete it 
			{
				delete node;
				return;
			}
			for (int i = 0; i < 26; i++) //recursively delete every 26 childs of every node 
			{
				destroyTrie(node->children[i]);
			}
		}
	}

public:

	Trie()//default ctor
	{
		root = create();//create the root node
		file.open("Dictionary.txt", ios::in | ios::out | ios::app); //open the file in input, output and append mode
		loadDictionary(); //loads the dictionary 
		suggestCount = 0;
	}

	~Trie()//destructor
	{
		destroyTrie(root); //destroy every node of the tree 
	}

	/*returns if the word is in the tree or not */
	bool searchBool(string word)
	{
		if (searchWord(word))
			return true;
		return false;
	}

	/*searches a word, if found return the word else return nothing*/
	string search(string word)
	{
		if (searchWord(word))
			return word;
		return "";
	}

	/*Deletes the word*/
	void Delete(string word)
	{
		if (!searchWord(word)) return;//word not in the dictionary

		DeleteWord(word, root, 0);
	}

	/*Inserts a word along with its meaning */
	void insert(string word, string means)
	{
		if (searchWord(word) == false) //if word already not in the dictionary, update the file 
			updateFile(word, means);
		insertNode(root, word, means); // insert the word 
	}

	/*getter for the meanng of a word */
	string getMeaning(string word)
	{
		Node* current = root; //current node for traversing the tree

		for (int i = 0; i < word.length(); i++)
		{
			if (current->children[word[i] - 'a'] == NULL) //if word not found
				return "";

			current = current->children[word[i] - 'a']; //goto the next child 
		}
		if (current->isEnd) //if word found, return its meaning 
		{
			return current->meaning;
		}
		return ""; //erturn nothing if word ot found 
	}

	/*suggests 3 words */
	void suggest(string& w1, string& w2, string& w3)
	{
		w1 = suggestions[0];
		w2 = suggestions[1];
		w3 = suggestions[2];
	}

	/* for displaying every word in the tree on the console (not utilized in the project(traverse() too)) */
	void print()
	{
		string s;
		traverse(s, root);
	}

	/* returns if the tree is empty */
	bool isEmpty(Node* node)
	{
		for (int i = 0; i < 26; i++)
			if (node->children[i])
				return false;
		return true;
	}
};