#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include "Node.hpp"
namespace ariel
{
    /*inner classes declaration*/
    class Iterator;

    class OrgChart
    {
        /*inner class - level Order iterator*/
    public:
        class Iterator
        {
        private:
            Node *_curr;
            std::string _flag;

        public:
            /*constructor*/
            Iterator(std::string flag, Node *root = nullptr);
            
            /*destructor*/
            ~Iterator() {}

            /*get curr employee reference (Node) */
            Node& operator*() const
            {
                return *_curr;
            }

            /*get curr employee ptr (Node) */
            Node* operator->() const
            {
                return _curr;
            }

            /* ++iter */
            Iterator& operator++();


            /* iter++ */
            const Iterator operator++(int);


            /* equals */
            friend bool operator==(const Iterator &a, const Iterator &b)
            {
                return a._curr == b._curr;
            }

            /* not equals */
            friend bool operator!=(const Iterator &a, const Iterator &b)
            {
                return a._curr != b._curr;
            }

            Iterator begin();

            Iterator end();


        }; // end iter

    private:
        Node* _root;
        size_t _size;
        friend std::ostream &operator<<(std::ostream &out, const OrgChart &org);

    public:
        OrgChart();
        ~OrgChart();
        OrgChart &add_root(std::string name);
        OrgChart &add_sub(std::string employer, std::string employee);
        Iterator begin_level_order();
        Iterator end_level_order();
        Iterator begin_reverse_order();
        Iterator end_reverse_order();
        Iterator begin_preorder();
        Iterator end_preorder();

        Iterator find(std::string name);
    };
}
