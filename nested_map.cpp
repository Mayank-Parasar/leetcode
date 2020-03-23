//
// Created by Mayank Parasar on 2020-03-23.
//
/*
    Here is the definition:

    struct nmap;
    struct nmap: map<string, boost::variant<string, nmap*>>{};

    The last line below doesn't work:

    nmap my_map;
    my_map["a"] = "b";
    my_map["c"] =  new nmap;
    my_map["c"]["d"] = "e";
 *
 * */

#include <iostream>
#include <boost/variant.hpp>
#include <map>

using namespace std;
using std::map;

struct nmap;
struct nmap: map<std::string, boost::variant<int, nmap*>>
{
    typedef boost::variant<int, nmap*> Variant;
    typedef map<int, Variant> base;

    friend nmap&       as_map(Variant& v)       { return *boost::get<nmap*>(v); }
    friend nmap const& as_map(Variant const& v) { return *boost::get<nmap*>(v); }

    friend int&       as_int(Variant& v)       { return boost::get<int>(v); }
    friend int const& as_int(Variant const& v) { return boost::get<int>(v); }
};

int main()
{
    nmap my_map;
    my_map["a"] = 1;
    my_map["b"] =  new nmap;

    as_map(my_map["b"])["c"] = 2;
    as_map(as_map(my_map["b"])["d"])["e"] = 3;

}