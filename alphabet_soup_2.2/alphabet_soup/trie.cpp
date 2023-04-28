/**
 * @file trie.cpp
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
#include "trie.hpp"

Trie::Trie()
{
    //TODO
    _root=TrieNode::Ref();
    _current=TrieNode::Ref();
    _prefix="";
    //
    assert(is_empty());
}

Trie::Ref Trie::create()
{    
    return std::make_shared<Trie>();
}

Trie::Trie(TrieNode::Ref root_node, std::string const& pref)
{
    //TODO
    _root=root_node;
    _prefix=pref;
    //
    assert(prefix() == pref);
}

Trie::Ref Trie::create(TrieNode::Ref root_node, std::string const& prefix)
{
    //We cannot use std::make_shared here
    //because the constructor is protected.
    typename Trie::Ref trie ( new Trie(root_node, prefix));
    return trie;
}

Trie::Ref Trie::create(std::istream& in) noexcept(false)
{
    Trie::Ref trie = nullptr;
    //TODO
        std::string token;
        in>>token;
        if(token!="["){
            throw std::runtime_error("Wrong input format");
        }
        else{
            auto aux = TrieNode::create(in);
            trie = Trie::create(aux,"");
            in>>token;
        }
    //
    return trie;
}

bool
Trie::is_empty() const
{
    bool ret_v=true;
    //TODO
    if(_root!=nullptr){
        ret_v=false;
    }
    //
    return ret_v;
}

std::string
Trie::prefix() const
{
    std::string ret_val = "";
    //TODO
    ret_val=_prefix;
    //
    return ret_val;
}

bool
Trie::is_key() const
{
    assert(!is_empty());
    bool ret_val = true;
    //TODO
    if(!_root->is_key()){
        ret_val=false;
    }
    //
    return ret_val;
}


TrieNode::Ref
Trie::root() const
{
    TrieNode::Ref node = nullptr;
    //TODO
    node=_root;
    //
    return node;
}

bool
Trie::has(std::string const& k) const
{
    assert(!is_empty());
    bool found = false;
    //TODO
    //Hint: use find_node() to do this.
    //Remember: The Trie can have a prefix==k but does not store the key k.    
    auto aux=find_node(k);
    found = aux!=nullptr && aux->is_key();
    //
    return found;
}

static void
preorder_traversal(TrieNode::Ref node, std::string prefix,
                   std::vector<std::string> & keys)
{
    //TODO
    //Remember: node->is_key() means the prefix is a key too.

    if(node->is_key()){
        keys.push_back(prefix);
    }
    node->goto_first_child();
    while(node->current_exists()){
        preorder_traversal(node->current_node(),prefix+node->current_symbol(), keys);
        node->goto_next_child();
    }
    //
}


void
Trie::retrieve(std::vector<std::string>& keys) const
{
    assert(!is_empty());
    //TODO
    //Remember add the subtrie's prefix to the retrieve keys.
    preorder_traversal(_root,prefix(),keys);
    //
}

Trie::Ref
Trie::child(std::string const& pref) const
{
    assert(!is_empty());
    Trie::Ref ret_v = Trie::create();
    //TODO
    //Hint: use find_node() to do this.
    auto aux=find_node(pref);
    if(aux!=nullptr){
        ret_v->_root=aux;
        ret_v->_prefix=_prefix+pref;
    }
    //
    assert(ret_v != nullptr);
    return ret_v;
}

bool
Trie::current_exists() const
{
    assert(!is_empty());
    bool ret_val = false;
    //TODO
    if(_current!=nullptr){
        ret_val=true;
    }
    //
    return ret_val;
}

Trie::Ref
Trie::current() const
{
    assert(current_exists());
    Trie::Ref trie = nullptr;
    //TODO
    trie=Trie::create(_current->current_node(),_prefix);
    //
    return trie;
}

char
Trie::current_symbol() const
{
    assert(current_exists());
    char symbol = 0;
    //TODO
    symbol=_current->current_symbol();
    //
    return symbol;
}

void
Trie::insert(std::string const& k)
{
    assert(k != "");
    //TODO
    if(_root==nullptr){
        _root=TrieNode::create(false);
    }
    auto node=_root;
    for(int i=0; i<k.size(); i++){
        if(node->has(k[i])){
            node=node->child(k[i]);
        }
        else{
            auto newNode=TrieNode::create(false);
            node->set_child(k[i], newNode);
            node=newNode;
        }
    }
    node->set_is_key_state(true);

    //
    assert(!is_empty());
    assert(has(k));
}

TrieNode::Ref
Trie::find_node(std::string const& pref) const
{
    assert(!is_empty());
    TrieNode::Ref node;
    //TODO
    //Remember: the prefix "" must return the trie's root node.
    int i=0;
    node=_root;

    while(i<pref.size() && node!=nullptr)
        if(node->has(pref[i])){
            node=node->child(pref[i]);
            i++;
        }
        else{
        node=nullptr;
        }

    //
    return node;
}

std::ostream&
Trie::fold(std::ostream& out) const
{
    //TODO
    out << "[ ";
        if(_root!=nullptr){
            _root->fold(out);
        }
        out << " ]";
    //
    return out;
}

bool
Trie::find_symbol(char symbol)
{
    assert(!is_empty());
    bool found = false;
    //TODO
    found=_current->find_child(symbol);
    _current=_current->current_node();
    //
    assert(!found || current_exists());
    assert(found || !current_exists());
    assert(!current_exists() || current_symbol()==symbol);
    return found;
}

void
Trie::goto_first_symbol()
{
    assert(!is_empty());
    //TODO
    _current->goto_first_child();
    _current=_current->current_node();

    //
    assert(!current_exists() ||
           current()->prefix()==prefix()+current_symbol());
}

void
Trie::goto_next_symbol()
{
    assert(current_exists());
    //TODO
    _current->goto_next_child();
    _current=_current->current_node();

    //
}
