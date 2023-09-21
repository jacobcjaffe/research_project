#include "dfa.h"
#include<string>

// initialize dfa object, fetches all of its definitions from a text file
// initializes the transition table, the table for calculating the number of
// accepted strings, and the set of accepting states
dfa::dfa(std::string path)
{
    std::ifstream in;
    in.open(path);
    int state;
    if (in.is_open()) {
        in >> sizeTransitionTable;
        transitionTable[0] = new int[sizeTransitionTable];
        transitionTable[1] = new int[sizeTransitionTable];

        // get the accepting states
        in >> numAcceptingStates;
        acceptingStates = new int[numAcceptingStates];
        for (int i = 0; i < numAcceptingStates; i++) {
            in >> acceptingStates[i];
        }

        // get the length of string
        in >> lengthStr;

        // get the transition table
        for (int i = 0; i < sizeTransitionTable; i++) {
            in >> transitionTable[0][i];
            in >> transitionTable[1][i];
        }

        // initialize table to calculate the number of accepted string
        tableAcceptedStr = new int**[sizeTransitionTable];
        for (int i = 0; i < sizeTransitionTable; i++) {
            tableAcceptedStr[i] = new int*[sizeTransitionTable];
            for (int j = 0; j < sizeTransitionTable; j++) {
                tableAcceptedStr[i][j] = new int[sizeTransitionTable];
            }
        }
    }
    else {
        std::cout << "could't open file" << std::endl;
    }
}

// calculates the number of accepted strings of size lengthStr
int dfa::CalculateNumAccepted() 
{
    return 0;
}

void dfa::PrintTransitionTable() 
{
    if (sizeTransitionTable == -1) {
        std::cout << "transition table not initialized" << std::endl;
        return;
    }
    std::cout << "The Transition Table" << std::endl;
    std::cout << " \t";
    for (int i = 0; i < sizeTransitionTable; i++) {
        std::cout << i << "\t \t";
    }
    std::cout << std::endl;
    for (int i = 0; i < 2; i++) {
        std::cout << i << "\t";
        for (int j = 0; j < sizeTransitionTable; j++) {
            std::cout << transitionTable[i][j] << "\t|\t";
        }
        std::cout << std::endl;
    }
}

void dfa::PrintAcceptingStates() 
{
    if (numAcceptingStates <= 0) {
        std::cout << "accepting states not initialized" << std::endl;
        return;
    }
    std::cout << numAcceptingStates << " accepting states" << std::endl;
    for (int i = 0; i < numAcceptingStates; i++) {
        std::cout << acceptingStates[i] << " ";
    }
    std::cout << std::endl;
}

// clean up allocated memory
dfa::~dfa() 
{
    std::cout << "cleaning up" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (transitionTable[i] != nullptr) {
            delete transitionTable[i];
        }
        delete transitionTable;
    }
    if (tableAcceptedStr != nullptr) {
        for (int i = 0; i < sizeTransitionTable; i++) {
            for (int j = 0; j < sizeTransitionTable; j++) {
                delete tableAcceptedStr[i][j];
            }
            delete tableAcceptedStr[i];
        }
        delete tableAcceptedStr;
    }
    if (acceptingStates != nullptr) {
        delete acceptingStates;
    }

}