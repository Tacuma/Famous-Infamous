#ifndef NODE_H
#define NODE_H


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Node
{
	friend class Tree;

public:
	Node(const string& question, Node* pYes, Node* pNo);
	//tests if is final question (leaf node)
	bool IsFinalQuestion() const;

public:
	string m_Question;  //question text
	Node* m_pYes;		//pointer to 'yes' child
	Node* m_pNo;		//pointer to 'no' child
};
#endif

// Here's the default constructor definition:

Node::Node(const string& question, Node* pYes, Node* pNo):
	m_Question(question),
	m_pYes(pYes),
	m_pNo(pNo)
{}


//IsFinalQuestion() Member Fuction
// tests if is final question (leaf node)
bool Node::IsFinalQuestion() const
{
	return (m_pYes == NULL && m_pNo == NULL);
}