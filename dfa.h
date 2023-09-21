#ifndef DFA
#define DFA
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

// a class to define the dfa and the methods that act on it
class dfa 
{
private:
    int** transitionTable = nullptr;
    int** tableAccepted = nullptr;
    int sizeTransitionTable = -1;
    int* acceptingStates;

public :
    // default constructor
    dfa();
    void FetchTransitionTable(std::string path);
    int CalculateNumAccepted(int length);
    void PrintTransitionTable();
};

#endif