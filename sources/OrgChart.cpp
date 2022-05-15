#include "OrgChart.hpp"
namespace ariel
{

    OrgChart::OrgChart() {}
    OrgChart::~OrgChart() {}
    OrgChart::Iterator::Iterator(std::string flag, Node *root)
        : _flag(flag), _curr(root) {}

    OrgChart::Iterator OrgChart::find(std::string name)
    {
        for (auto iter = this->begin_level_order(); iter != this->end_level_order(); iter++)
        {
            if (iter->_name == name)
            {
                return iter;
            }
        }
        return this->end_level_order();
    }

    OrgChart &OrgChart::add_root(std::string name)
    {
        if (this->_root == nullptr)
        {
            Node root{name};
            this->_root = &root;
            this->_size++;
        }
        else
        {
            this->_root->_name = name;
        }
    }
    OrgChart &OrgChart::add_sub(std::string employer, std::string employee)
    {
        Iterator iter = this->find(employer);
        if (iter != this->end_level_order())
        {
            Node newNode{employee};
            newNode._parent = &(*iter);
            iter->_children.back()->_bro = &newNode;
        }
        else
        {
            throw std::invalid_argument("employer" + employer + "dosen't exist");
        }
    }

    OrgChart::Iterator OrgChart::begin_level_order() {}
    OrgChart::Iterator OrgChart::end_level_order() {}
    OrgChart::Iterator OrgChart::begin_reverse_order();
    OrgChart::Iterator OrgChart::end_reverse_order();
    OrgChart::Iterator OrgChart::begin_preorder();
    OrgChart::Iterator OrgChart::end_preorder();


    OrgChart::Iterator &OrgChart::Iterator::operator++(){
        
    }

    // OrgChart::Iterator &OrgChart::Iterator::operator++()
    // {
    //     if (this->_flag == "level_order")
    //     { // TODO: from Org throw
    //         if (this->_curr->_parent == nullptr)
    //         { // root
    //             if (!this->_curr->_children.empty())
    //             {
    //                 this->_curr = this->_curr->_children.at(0);
    //             }
    //         }
    //         else if (this->_curr->_bro != nullptr)
    //         { // go throw curr level
    //             this->_curr = this->_curr->_bro;
    //         }
    //         else
    //         {
    //             Node *parent = this->_curr->_parent;
    //             Node *tmp;
    //             if (parent->_bro != nullptr)
    //             {
    //                 tmp = parent->_bro;
    //             }
    //             else if (!parent->_children.empty())
    //             {
    //                 tmp = parent->_children.at(0);
    //             }

    //             while (tmp->_children.empty() && tmp->_bro != nullptr)
    //             {
    //                 tmp = tmp->_bro;
    //             }

    //             this->_curr = tmp->_children.at(0);
    //         }
    //     }
    // }

}