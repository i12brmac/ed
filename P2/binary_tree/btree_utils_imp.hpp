/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#pragma once

#include <cassert>
#include <exception>
#include <memory>
#include <iostream>
#include <queue>

#include "btree_utils.hpp"

template<class T>
int compute_height (typename BTree<T>::Ref t)
{
    assert(t != nullptr);
    int height = 0;
    //TODO
    int cont=0;
    int cont2=0;
    if(t->is_empty()){
        height=-1;
    }
    else{


        cont=compute_height<T>(t->left())+1;
        cont2=compute_height<T>(t->right())+1;
        if(cont>cont2){
            height=cont;
        }
        else{height=cont2;}

    }
    //
    return height;
}

template<class T>
size_t compute_size (typename BTree<T>::Ref t)
{
    assert(t != nullptr);
    size_t ret_val = 0;
    //TODO
    //Hint: when you call a template into other template maybe you need
    // to specialize the call.
        int cont=0;
        if(t->is_empty()){
            ret_val=0;
        }
        else{
            cont++;
            cont+=compute_size<T>(t->left());
            cont+=compute_size<T>(t->right());
            ret_val=cont;
        }
    //
    return ret_val;
}

template <class T, typename Processor>
bool
prefix_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool retVal = true;
    //TODO
    //Hint: when you call a template into other template maybe you need
    // to specialize the call.
    if(!tree->is_empty()){
        retVal=p(tree);
        retVal= retVal && prefix_process<T>(tree->left(),p);
        retVal= retVal && prefix_process<T>(tree->right(),p);
    }
    //
    return retVal;
}

template <class T, class Processor>
bool
infix_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool retVal = true;
    //TODO
    //Hint: when you call a template into other template maybe you need
    // to specialize the call.
    if(!tree->is_empty()){

        retVal= retVal && infix_process<T>(tree->left(),p);
        retVal= retVal && p(tree);
        retVal= retVal && infix_process<T>(tree->right(),p);
    }
    //
    return retVal;
}

template <class T, class Processor>
bool
postfix_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool retVal = true;
    //TODO
    //Hint: when you call a template into other template maybe you need
    // to specialize the call.
    if(!tree->is_empty()){
    retVal= retVal && postfix_process<T>(tree->left(),p);
    retVal= retVal && postfix_process<T>(tree->right(),p);
    retVal= retVal && p(tree);
    }
    //
    return retVal;
}


template <class T, class Processor>
bool
breadth_first_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool go_on = true;
    //TODO
    //Hint: think about which data structure can help you to do this kind 
    //  of traversal.
    std::queue<typename BTree<T>::Ref> q;
    auto subtree=BTree<T>::create();
    q.push(tree);
    while(go_on==true && q.empty()==false){
        subtree=q.front();
        if(!subtree->is_empty()){
            go_on=p(subtree);
            q.push(subtree->left());
            q.push(subtree->right());
        }
        q.pop();

    }

    //
    return go_on;
}

template <class T>
std::ostream&
print_prefix(std::ostream& out, typename BTree<T>::Ref tree)
{
    //TODO
    //You must create a lambda function with a parameter to be printed and
    //  use a prefix_process to process the tree with this lambda.
    //Remember: the lambda must return true.
    auto l=[&out](typename BTree<T>::Ref tree){
        out<<tree->item()<<' ';
        return true;
    };
    prefix_process<T>(tree, l);

    //
    return out;
}

template <class T>
std::ostream&
print_infix(std::ostream& out, typename BTree<T>::Ref tree)
{
    //TODO
    //You must create a lambda function with a parameter to be printed and
    //  use an infix_process to process the tree with this lambda.
    //Remember: the lambda must return true.
    auto l=[&out](typename BTree<T>::Ref tree){
        out<<tree->item()<<' ';
        return true;
    };
    infix_process<T>(tree, l);
    //
    return out;
}

template <class T>
std::ostream&
print_postfix(std::ostream& out, typename BTree<T>::Ref tree)
{
    //TODO
    //You must create a lambda function with a parameter to be printed and
    //  use a postfix_process to process the tree with this lambda.
    //Remember: the lambda must return true.
    auto l=[&out](typename BTree<T>::Ref tree){
        out<<tree->item()<<' ';
        return true;
    };
    postfix_process<T>(tree, l);
    //
    return out;
}

template <class T>
std::ostream&
print_breadth_first(std::ostream& out, typename BTree<T>::Ref tree)
{
    //TODO
    //You must create a lambda function with a parameter to be printed and
    //  use a breadth_first_process to process the tree with this lambda.
    //Remember: the lambda must return true.
    auto l=[&out](typename BTree<T>::Ref tree){
        out<<tree->item()<<' ';
        return true;
    };
    breadth_first_process<T>(tree,l);
    //
    return out;
}

template <class T>
bool search_prefix(typename BTree<T>::Ref tree, const T& it, size_t& count)
{
    bool found = false;
    count = 0;
    //TODO
    //You must create a lambda function with a parameter to compare it to the
    // value of the element to be searched for.
    // Use the lambda with the prefix_process.
    //Remember: Also, the lambda must update the count variable and
    //must return True/False.
    auto l=[&count,it](typename BTree<T>::Ref t){
        count++;
        if(t->item()==it){
            return false;
        }
        return true;
    };

    found=!prefix_process<T>(tree, l);

    //
    return found;
}

template <class T>
bool search_infix(typename BTree<T>::Ref tree, const T& it, size_t& count)
{
    bool found = false;
    count = 0;
    //TODO
    //You must create a lambda function with a parameter to compare it to the
    // value of the element to be searched for.
    // Use the lambda with the infix_process.
    //Remember: Also, the lambda must update the count variable and
    //must return True/False.
    auto l=[&count,it](typename BTree<T>::Ref t){
        count++;
        if(t->item()==it){
            return false;
        }
        return true;
    };

    found=!infix_process<T>(tree, l);
    //
    return found;
}

template <class T>
bool search_postfix(typename BTree<T>::Ref tree, const T& it, size_t& count)
{
    bool found = false;
    count = 0;
    //TODO
    //You must create a lambda function with a parameter to compare it to the
    // value of the element to be searched for.
    // Use the lambda with the postfix_process.
    //Remember: Also, the lambda must update the count variable and
    //must return True/False.
    auto l=[&count,it](typename BTree<T>::Ref t){
        count++;
        if(t->item()==it){
            return false;
        }
        return true;
    };

    found=!postfix_process<T>(tree, l);
    //
    return found;
}

template <class T>
bool search_breadth_first(typename BTree<T>::Ref tree, const T& it, size_t& count)
{
    bool found = false;
    count = 0;
    //TODO
    //You must create a lambda function with a parameter to compare it to the
    // value of the element to be searched for.
    // Use the lambda with the breadth_first_process.
    //Remember: Also, the lambda must update the count variable and
    //must return True/False.
    auto l=[&count,it](typename BTree<T>::Ref t){
        count++;
        if(t->item()==it){
            return false;
        }
        return true;
    };

    found=!breadth_first_process<T>(tree, l);
    //
    return found;
}


template<class T>
bool check_btree_in_order(typename BTree<T>::Ref const& tree)
{
    bool ret_val = true;
    //TODO
    //Hint: You can create a lambda function with a parameter to compare it with
    // the last the value seen.
    // Use the lambda with the infix_process.
    
    //
    return ret_val;
}

template<class T>
bool has_in_order(typename BTree<T>::Ref tree, T const& v)
{
    assert(check_btree_in_order<T>(tree));    
    bool ret_val = false;
    //TODO

    //
    return ret_val;
}

template <class T>
void insert_in_order(typename BTree<T>::Ref tree, T const& v)
{
    assert(check_btree_in_order<T>(tree));
    //TODO

    //
    assert(has_in_order<T>(tree, v));
}
