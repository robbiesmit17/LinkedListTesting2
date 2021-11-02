// LinkedListTesting2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp> // Include for boost::split
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "boost/filesystem.hpp"
#include <filesystem>
#include <algorithm>


void democode() {
    //a vector is a template for a variable array. This creates an array of strings with size 100.
    std::vector<std::string> myArray(100);
    //vectors have a size function
    int myArraySize = myArray.size();
    //this assigns all values in myArray2 as thingymobob
    std::vector<std::string> myArray2(100, "thingymobob");

    //vectors allow for initialising with values. Size is automatically assigned.
    std::vector<std::string> myArray3{ "a","bc","def","ghij","klmno","pqrstu","vwxyzab" };
}

//This is used to create a node in the linked list. Node is just the name, not a type.
struct Node
{
    std::vector<std::string>* data;
    struct Node* next;
};

void append(struct Node** head, std::vector<std::string>* node_data) {

    /* 1. create and allocate node */
    struct Node* newNode = new Node;

    struct Node* last = *head; /* used in step 5*/

    /* 2. assign data to the node */
    newNode->data = node_data;


    /* 3. set next pointer of new node to null as its the last node*/
    newNode->next = NULL;

    /* 4. if list is empty, new node becomes first node */
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = newNode;
    return;

}
// display linked list contents
void displayList(struct Node* node)
{
    //traverse the list to display each node
    while (node != NULL)
    {
        for (std::string item : *(node->data)) {
            std::cout << item << std::endl;
        }
        node = node->next;
    }

    if (node == NULL)
        std::cout << "null";
}

std::vector<std::string> ReadWords(std::string fileName) {
    //std::string myText;
    //std::ifstream _ifswords(fileName);

    //std::string _strWords[10];

    //while (getline(_ifswords, myText)) {
        // Output the text from the file
       // std::cout << myText << std::endl;
    //}
    // Close the file


    std::ifstream is(fileName);
    //is.seekg(0, is.end);
    //int length = is.tellg();
    //is.seekg(0, is.beg);

    //char* buffer = new char[length];
    //is.read(buffer, length);

    //delete[] buffer;

    std::vector<std::string> output;
    std::string input = std::string((std::istreambuf_iterator<char>(is)), std::istreambuf_iterator<char>());
    
    output = boost::split(output,input, boost::is_any_of("\n"), boost::token_compress_on);
    //_ifswords.close();
    is.close();
    return output;
}

void LoopThroughFileSystem(Node* head) {
    boost::filesystem::path p("./words");

    boost::filesystem::directory_iterator end_itr;

    // cycle through the directory
    for (boost::filesystem::directory_iterator itr(p); itr != end_itr; ++itr)
    {
        // If it's not a directory, list it. If you want to list directories too, just remove this check.
        if (boost::filesystem::is_regular_file(itr->path())) {
            // assign current file name to current_file and echo it out to the console.


            std::string current_file = itr->path().string();
            //std::cout << current_file << std::endl;

            //returns a vector. then this adds it to the linked list.
            std::vector<std::string> item = ReadWords(current_file);
            append(&head, &item);

            for (std::string thing : item) {
                std::cout << thing << std::endl;
            }

        }
    }
}

//next steps: reading from a file into a vector efficiently

int main()
{
    /* empty list */
    //struct Node* head = NULL;
    //std::vector<std::string> thing = {"thing","otherthing"};
    //std::vector<std::string>* point = &thing;
    //append(&head, point);
    //displayList(head);

    struct Node* head = NULL;

    LoopThroughFileSystem(head);
    std::cout << std::endl;
    displayList(head);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
