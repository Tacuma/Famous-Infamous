//Game Class

#ifndef GAME_H
#define GAME_H
#include "Tree.h"
using namespace std;

class Game
{
public:
	Game();
	//displays instructions
	//void DisplayInstructions();
	//plays a round of a game
	void Play();
	//This saves the game: Assignment 3 
	void Save(string);
	//This loads the game: Assignment 3 
	void Load(ifstream&);
private:
	//binary tree, stores questions
	Tree m_Tree;
};

#endif

//constructor
//The Game constructor is empty.

Game::Game()
{}


//plays a round of game
void Game::Play()
{
			m_Tree.Reset();

			char response;
				
			while (m_Tree.DisplayCurrentQuestion())
			{
				response = m_Tree.AskYesNo();
				m_Tree.NextQuestion(response);
			}
			response = m_Tree.AskYesNo();

			if (response == m_Tree.YES)
			{
				cout << "I guessed it!" <<endl;
			}
			else 
			{
				cout << "I give up." << endl;
				m_Tree.AddPerson();			
	        }
			cout << endl;
}

void Game::Save(string file2)
{
	m_Tree.Reset();
	m_Tree.SaveGame(file2);
	m_Tree.DeleteTree();
	m_Tree.Reset();
}
	
void Game::Load(ifstream& stream)
{
	m_Tree.Reset();
	m_Tree.LoadGame(stream);
	m_Tree.Reset();
}

