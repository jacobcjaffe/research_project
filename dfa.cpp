#include "dfa.h"

dfa::dfa() {}

void dfa::FetchTransitionTable(std::string path) 
{
    std::ifstream in;
    in.open(path);
    if (in.is_open()) {
        in >> sizeTransitionTable;

    }

}

int dfa::CalculateNumAccepted(int length) 
{

}

void dfa::PrintTransitionTable() 
{
    if (sizeTransitionTable == -1) {
        std::cout << "transition table not initialized" << std::endl;
    }
    for (int i = 0; i < sizeTransitionTable; i++) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < sizeTransitionTable; j++) {
            std::cout << transitionTable[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}