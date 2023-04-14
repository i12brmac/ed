/**
 * @file trie_node.cpp
 *
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */

#include <cassert>
#include <sstream>
#include <cstdint>

#include "trie_node.hpp"

TrieNode::TrieNode (bool is_key_state)
{
    //TODO
    _isKey=is_key_state;
    _dict=std::map<char,Ref>();
    _current=_dict.end();

    //
    assert(is_key()==is_key_state);
    assert(!current_exists());
};

TrieNode::Ref TrieNode::create(bool is_key_state)
{
    return std::make_shared<TrieNode>(is_key_state);
}

TrieNode::~TrieNode()
{}

bool TrieNode::is_key() const
{
    bool ret_val = true;
    //TODO
    if(_isKey==false){
        ret_val=false;
    }
    //
    return ret_val;
}

bool
TrieNode::has(char k) const
{
    bool ret_v = false;
    //TODO
    if(_dict.find(k)!=_dict.end()){
        ret_v=true;
    }
    //
    return ret_v;
}

TrieNode::Ref
TrieNode::child(char k) const
{
    assert(has(k));
    TrieNode::Ref node = nullptr;
    //TODO
    node=_dict.at(k);
    //
    return node;
}

bool
TrieNode::current_exists() const
{
    bool ret_val = true;
    //TODO
    if(_current==_dict.end()){
        ret_val=false;
    }
    //
    return ret_val;
}

TrieNode::Ref
TrieNode::current_node() const
{
    assert(current_exists());
    TrieNode::Ref node = nullptr;
    //TODO
    node=_current->second;
    //
    return node;
}

char
TrieNode::current_symbol() const
{
    assert(current_exists());
    char symbol = 0;
    //TODO
    symbol=_current->first;
    //
    return symbol;
}

void
TrieNode::set_is_key_state(bool new_state)
{
    //TODO
    _isKey=new_state;
    //
    assert(is_key()==new_state);
}

bool
TrieNode::find_child(char s)
{
    bool found = false;
    //TODO
    if(has(s)){
        _current=_dict.find(s);
        found=true;
    }
    else{
        _current=_dict.end();
    }
    //
    assert(found || !current_exists());
    assert(!found || current_symbol()==s);
    return found;
}

void
TrieNode::goto_first_child()
{
    //TODO
    _current=_dict.begin();
    //
}

void
TrieNode::goto_next_child()
{
    assert(current_exists());
    //TODO
    _current++;
    //
}

void
TrieNode::set_child(char k, Ref node)
{
    assert(node != nullptr);
    //TODO
    if(has(k)){
        _dict.at(k)=node;

    }
    else{
        _dict[k]=node;
        _current=_dict.find(k);
    }

    //
    assert(current_symbol()==k);
    assert(current_node()==node);
}

std::ostream&
TrieNode::fold(std::ostream& out) const
{
    //TODO
    //Hint: review c++ input/output manipulators at
    //      https://en.cppreference.com/w/cpp/io/manip

    out<<"[";

    if(_isKey==false){
        out<<" F";
    }
    else{
        out<<" T";
    }

    for(auto it=_dict.begin(); it!=_dict.end(); it++){
        out<<std::hex<<" "<<(short)it->first;
        out<<" ";
        it->second->fold(out);

    }
        out<<" ]";
    //
    return out;
}

TrieNode::Ref TrieNode::create(std::istream& in) noexcept(false)
{
    TrieNode::Ref node = nullptr;
    //TODO

    //
    return node;
}
