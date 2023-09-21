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
    int** transitionTable = new int*[2];
    int*** tableAcceptedStr = nullptr;
    int sizeTransitionTable = -1;
    int* acceptingStates;
    int numAcceptingStates = 0;
    int lengthStr = 0;

public :
    // constructor called from input text file
    dfa(std::string path);
    int CalculateNumAccepted();
    void PrintTransitionTable();
    void PrintAcceptingStates();
    ~dfa();
};

#endif