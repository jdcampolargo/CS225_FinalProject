#include "include/parser.h"
#include "include/node.h"
#include "include/airport.h"
#include <vector>
#include <map>
#include <fstream>

using std::vector;
using std::string;

void Parser::InputNodes(vector<Node>& airportVector, std::string filename) {
    std::ifstream myFile(filename);
    std::string line;
     while(std::getline(myFile, line))
     {
        vector<std::string> splitList = CommaSplit(line);
        
        removeWhiteSpace(splitList[3]);
        Node node = Node(Airport(splitList[0], splitList[1], splitList[2], splitList[3], splitList[4], splitList[5], splitList[6]));
        airportVector.push_back(node);
     }

}

void Parser::InputEdges(vector<Edge>& edgesVector, std::string filename) {
    std::ifstream myFile(filename);
    std::string line;
     while(std::getline(myFile, line))
     {
        vector<std::string> splitList = CommaSplit(line);
        Edge edge(removeWhiteSpace(splitList[1]), removeWhiteSpace(splitList[2]));
        edgesVector.push_back(edge);
     }
}

vector<std::string> Parser::CommaSplit(std::string string) {
    vector<std::string> splitList;
    std::string temp = "";
    for (size_t i = 0; i < string.length(); i++) {
        if (string[i] != ',') {
            temp += string[i];
        } else {
            splitList.push_back(temp);
            temp = "";
        }
    }
    splitList.push_back(temp);
    return splitList;
}

std::string Parser::removeWhiteSpace(std::string& string) {
    std::string trimmedString = "";
    for (int i = 0; i < string.length(); i++) {
        if (int(string[i]) != 13) {
            trimmedString += string[i];
        } 
    }
    if (trimmedString.length() == 4) {
        std::cout<<trimmedString<<std::endl;
        for (int i = 0; i < trimmedString.length(); i++) {
            std::cout<<int(trimmedString[i])<<std::endl;
        }
    }
    return trimmedString;
}