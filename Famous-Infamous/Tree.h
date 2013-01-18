//Tree Class

#ifndef TREE_H
#define TREE_H
#include<iostream>
#include <string>
#include "Node.h"
using namespace std;


class Tree
{
public:
	//builds minimal starting tree
	Tree();
	//frees alocated memory
	~Tree();
	//resets current position to root
	void Reset();
	//deletes node and all descendents
	void Delete(Node* pNode);
	void DeleteTree();
	//displays question at current position
	bool DisplayCurrentQuestion();
	//advances current position to next question
	void NextQuestion(char answer);
	//adds person to tree, based on current position
	void AddPerson();
	//asks yes or no question
	char AskYesNo(const string& question="");
	//displays a list of all questions for the names of people stored in the code's binary tree.
	//Quiz 3
	void PrintQuestions();
	//Assignment 3
	void SaveGame(string);
	//Assignment 3
	void LoadGame(ifstream&);
		
	static const char YES = 'y';
	static const char NO = 'n';

private:
	//pointer to root
	Node* m_pRoot;
	//pointer to current position
	Node* m_pCurrent;
	//pointer to parent of current position
	Node* m_pCurrentParent;
};
#endif


//builds minimal starting tree
Tree::Tree()
{
	
	Node* pNodeGandhi = new Node("Are you thinking of Gandhi?", NULL, NULL);
	Node* pNodeSanta = new Node("Are you thinking of Santa Claus?", NULL, NULL);
	Node* pNodeQuestion = new Node("Is/was the person real?", pNodeGandhi, pNodeSanta);
	m_pRoot = pNodeQuestion;
	m_pCurrent = m_pRoot;
	m_pCurrentParent = NULL; 

}

//Destructor
//frees allocated memory
Tree::~Tree()
{
	Delete(m_pRoot);
}

//resets current position to root
void Tree::Reset()
{
	m_pCurrent = m_pRoot;
	m_pCurrentParent = NULL;
}

//deletes node and all descendants
void Tree::Delete(Node* pNode)
{
	if (pNode != NULL )
	{
		Delete(pNode->m_pYes);  //recursive call
		Delete(pNode->m_pNo);	//recursive call
		delete pNode;
		//pNode = NULL;
	}
}

void Tree::DeleteTree()
{
	Delete(m_pRoot);
	m_pRoot = NULL;
}

//displays question at current position
bool Tree::DisplayCurrentQuestion()
{
	
	//never called when m_pCurrent is NULL, but just in case...
	if (m_pCurrent == NULL)
	{
		return false;
	}
	cout << m_pCurrent->m_Question;
	return (!m_pCurrent->IsFinalQuestion());
}

//advances current position to next question

void Tree::NextQuestion(char answer)
{
	//never called when m_pCurrent is NULL, but just in case...
	if (m_pCurrent == NULL)
	{
		return;
	}

	//never called when m_pCurrent points to final question, just in case...
	if (m_pCurrent->IsFinalQuestion())
	{
		
		return;
	}

	m_pCurrentParent = m_pCurrent;

	if (answer == YES)
	{
		//m_pCurrent->m_position=4;
		m_pCurrent= m_pCurrent->m_pYes;
	}
	else
	{
		//m_pCurrent->m_pchoice='n';
		m_pCurrent = m_pCurrent->m_pNo;
		
	}
	
}



//adds person to tree, based on current position
void Tree::AddPerson()
{
	//get name of new person
	cout << "Who are you thinking of?: ";
	string name;
	cin.ignore();
	getline(cin, name);

	//get question to distinguish new person
	cout << "What question would distinguish these two people?:" << endl;
	string question;
	getline(cin, question);
	//create new nodes
	Node* pNodePerson = new Node("Are you thinking of " + name + "?", NULL, NULL);
	Node* pNodeQuestion = new Node(question, NULL, NULL);
	//get answer to question that distinguishes new person
	char answer = AskYesNo("What would the answer be for " + name + "?");

	//connect new question node to new person node
	if (answer == YES)
	{
		pNodeQuestion->m_pYes = pNodePerson;
		pNodeQuestion->m_pNo = m_pCurrent;
	}
	else
	{
		pNodeQuestion->m_pYes = m_pCurrent;
		pNodeQuestion->m_pNo = pNodePerson;
	}
	//insert new question node into tree
	if (m_pCurrentParent->m_pYes == m_pCurrent)
	{
		m_pCurrentParent->m_pYes = pNodeQuestion;
	}
	else
	{
		m_pCurrentParent->m_pNo = pNodeQuestion;
	}
}




char Tree::AskYesNo(const string& question)
{
	char response;
	do
	{
		cout << question;
		cout << " (" << YES << "/" << NO << "): ";
		cin >> response;
	} while (response != YES && response != NO);
		
	return response;
}

// This Saves the Game into a txt file
void SaveHelper (Node* ptr, ofstream& outData)
{
	if (ptr!=NULL)
		{
			outData << ptr->m_Question <<",";
			if ((ptr->m_pYes == NULL) && (ptr->m_pNo == NULL))
				outData << "0" << endl;
			else if ((ptr->m_pYes != NULL) && (ptr->m_pNo == NULL))
				outData << "L" << endl;
			else if ((ptr->m_pYes == NULL) && (ptr->m_pNo != NULL))
				outData << "R" << endl;
			else if ((ptr->m_pYes != NULL) && (ptr->m_pNo != NULL))
				outData << "2" << endl;
			SaveHelper(ptr->m_pYes,outData);
			SaveHelper(ptr->m_pNo, outData);
		}
}

void Tree::SaveGame(string file2)
{	
	ofstream outData;
	outData.open(file2.c_str());
	SaveHelper(m_pRoot,outData);
	outData.close();
}


void LoadHelper(Node*& root, ifstream& inData){
		string question;
		char D;
		getline(inData,question,',');
		inData >> D;
		inData.ignore(1);
		root = new Node(question,NULL,NULL);
		if ((D=='2')||(D=='L'))
			LoadHelper(root->m_pYes,inData);
		if ((D=='2')||(D=='R'))
			LoadHelper(root->m_pNo,inData);
}


void Tree::LoadGame(ifstream& inData ){
	
	LoadHelper(m_pRoot,inData);
	inData.close();
}


// Prints the People in the list
void print(Node* tree, int& count) 
{
	if (tree != NULL)
	{
		print(tree->m_pYes, count);
		if ((tree->m_pYes == NULL) && (tree->m_pNo == NULL)){
			count++;
			cout << count << " - " << tree->m_Question << endl;
		}
		print(tree->m_pNo, count);
	}
}

void Tree::PrintQuestions(){
	int count = 0;
	print(m_pRoot,count);
}