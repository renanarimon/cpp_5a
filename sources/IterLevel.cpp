#include "OrgChart.hpp"

namespace ariel{
    std::string& OrgChart::IterLevel::operator*() const{
        return this->_curr->_name;
    } // return curr employee's name
    std::string* OrgChart::IterLevel::operator->() const{
        return &(this->_curr->_name);
    } // return ptr to curr employee
    IterLevel& OrgChart::IterLevel::operator++(){
    } // ++iter
    const IterLevel OrgChart::IterLevel::operator++(int){} // ??
    bool OrgChart::IterLevel::operator==(const IterLevel& other){
        return this->_curr == other._curr;
    } // curr == other.curr
    bool OrgChart::IterLevel::operator!=(const IterLevel& other){
        return this->_curr != other._curr;
    } // curr != other.curr
    IterLevel OrgChart::IterLevel::begin(){} // tree root wrapped in IterLevel type
    IterLevel OrgChart::IterLevel::end(){} // last node in tree wrapped in IterLevel type
}