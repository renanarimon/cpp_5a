#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Node.hpp"
namespace ariel
{
    /*inner classes declaration*/
    class IterLevel;
    class IterReverse;
    class IterPre;

    class OrgChart
    {
    private:
        Node* root;
        size_t _size;
        friend std::ostream& operator<<(std::ostream& out, const OrgChart& org);

    public:
        OrgChart();
        ~OrgChart();
        OrgChart& add_root(std::string root);
        OrgChart& add_sub(std::string employer, std::string employee);
        IterLevel begin_level_order();
        IterLevel end_level_order();
        IterReverse begin_reverse_order();
        IterReverse end_reverse_order();
        IterPre begin_preorder();
        IterPre end_preorder();

        /*inner class - level Order iterator*/
        class IterLevel
        {
        private:
        Node* _curr;
        public:
            IterLevel(Node* root = nullptr)
                : _curr(root){}
            ~IterLevel(){}
            std::string& operator*() const; // return curr employee's name
            std::string* operator->() const; // return ptr to curr employee
            IterLevel& operator++(); // ++iter
            const IterLevel operator++(int); // ??
            bool operator==(const IterLevel& other); // curr == other.curr
            bool operator!=(const IterLevel& other); // curr != other.curr
            IterLevel begin(); // tree root wrapped in IterLevel type
            IterLevel end(); // last node in tree wrapped in IterLevel type
       
        }; // end LevelOrder_iter

        class IterReverse
        {
        private:
        public:
            IterReverse(){}
            ~IterReverse(){}

        }; // end ReversOrder_iter

        class IterPre
        {
        private:
        public:
            IterPre(){}
            ~IterPre(){}
        }; // end PreOrder_iter
    };

}
