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
        std::vector<Node *> _children;
        Node* _parent;
        Node* _bro;

        Node(std::string name)
        {
            this->_name = name;
            this->_parent = nullptr;
            this->_bro = nullptr;
            std::vector<Node *> v;
            this->_children = v;
        }
        Node(Node& other){
            this->_name = other._name;
            this->_parent = other._parent;
            this->_bro = other._bro;
            this->_children = other._children;
        }
        ~Node() {}
    };

}