#include "OrgChart.hpp"
namespace ariel{

    OrgChart::OrgChart(){}
    OrgChart::~OrgChart(){}
    OrgChart& OrgChart::add_root(std::string root){return *this;}
    OrgChart& OrgChart::add_sub(std::string employer, std::string employee){return *this;}
    IterLevel OrgChart::begin_level_order();
    IterLevel end_level_order();
    IterReverse begin_reverse_order();
    IterReverse end_reverse_order();
    IterPre begin_preorder();
    IterPre end_preorder();

}