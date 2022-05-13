#pragma once
#include <iostream>
#include <string>
#include <vector>
namespace ariel
{
    class Node
    {
    public:
        std::string _name;
        std::vector<Node *> _employees;
        Node(std::string name)
        {
            this->_name = name;
            std::vector<Node *> v;
            this->_employees = v;
        }
        Node(Node& other){
            this->_name = other._name;
            this->_employees = other._employees;
        }
        ~Node() {}
    };

}