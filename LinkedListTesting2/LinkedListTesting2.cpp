#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <filesystem>
#include <algorithm>
#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp> // Include for boost::split
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "boost/filesystem.hpp"

void democode() {
    //a vector is a template for a variable array.
    
    //This creates an array of strings with size 100.
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
    std::string categoryName;
    std::vector<std::string> data;
    struct Node* next;
};

void append(struct Node** head, std::string categoryName, std::vector<std::string> node_data) {

    /* 1. create and allocate node */
    struct Node* newNode = new Node;

    struct Node* last = *head; /* used in step 5*/

    /* 2. assign data to the node */
    newNode->categoryName = categoryName;
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
        std::cout << node->categoryName << std::endl;
        for (std::string item : node->data) {
            std::cout << "   " << item << std::endl;
        }
        node = node->next;
    }
}

void displayCategories(struct Node* node)
{
    Node* list = node;
    //traverse the list to display each node
    while (list != NULL)
    {
        std::cout << list->categoryName << std::endl;
        list = list->next;
    }
}


//going to keep this as a seperate function for future expanability. Possibly read from different directories? 
std::vector<std::string> ReadWords(std::string fileName) {

    std::ifstream is(fileName);


    std::vector<std::string> output;
    std::string input = std::string((std::istreambuf_iterator<char>(is)), std::istreambuf_iterator<char>());
    
    output = boost::split(output,input, boost::is_any_of("\n"), boost::token_compress_on);
    //_ifswords.close();
    is.close();
    //std::cout << input<<std::endl;
    return output;
}

void LoopThroughFileSystem(Node* &head) {
    boost::filesystem::path p("./words");

    boost::filesystem::directory_iterator end_itr;

    // cycle through the directory
    for (boost::filesystem::directory_iterator itr(p); itr != end_itr; ++itr)
    {
        // If it's not a directory, list it. If you want to list directories too, just remove this check.
        if (boost::filesystem::is_regular_file(itr->path())) {
            // assign current file name to current_file and echo it out to the console.


            std::string current_file = itr->path().string();

            //returns a vector. then this adds it to the linked list.
            std::cout << current_file << std::endl;
            std::vector<std::string> item = (ReadWords(current_file));
            std::string fileName = itr->path().stem().string();
            append(&head,fileName, item);
        }
    }
}


int main()
{

    struct Node* head = NULL;

    LoopThroughFileSystem(head);
    std::cout << std::endl;
    displayList(head);
    /*
    use an iterator or something to display all of the categories.
    user picks a category.

    a random word is picked from the category.
    word is scrambled and couted.

    user inputs the answer.

    score is added.
    
    
    
    */

}