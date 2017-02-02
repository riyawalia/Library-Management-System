//
//  main.cpp
//  Library Manegement System
//
//  Created by Riya Walia on 2017-01-11.
//  Copyright © 2017 Riya Walia. All rights reserved.
//

// books will be represented by a class Book with string for bname, int for price, object date for date of issue (all instances of date will be 0 if not issued), string for bauthor, int for late fee
// functions in class Book include constructor function that will input values, display function and 
// date will be represented by an object with year, month, date
// books will be organised in a binary tree where the key is the book code and the value is the coresponding book
// if book is returned 2 weeks after issue date, late fee starts. 1$ for each day for another month. If a month or more, borrower has to pay the price of the book.

#include <iostream>
#include <string>


class Date {
public:
    int year, month, day;
    Date() {reset_date(); }
    void reset_date() {
        year=0; month=0; day=0;
    }
    void display_date () {
        if (year==0 && month ==0 && day==0)
        {
            std::cout<<"Book not issued yet"<<std::endl;
        }
        else {
            std::cout<<day<<"."<<month<<"."<<year<<std::endl;
        }}
    void input_date() {
        std::cout<<"Enter today's day: "; std::cin>>day;
        std::cout<<"Enter the current month: "; std::cin>>month;
        std::cout<<"Enter the current year: "; std::cin>>year;
    }
};

class Book {
public:
    int price, fee=0;
    char author[150];
    char name[150];
    int id;
    Date date;
    char issuer[150];
    void input_book () {
        std::cout<<"Please enter the name of the book: "; std::cin>>name;
        std::cout<<"Please enter the name of the author: ";
        std::cin>>author;
        std::cout<<"Please enter the price of the book: "; std::cin>>price;
        std::cout<<"Please enter the Book ID: "; std::cin>>id;
    }
    void display_book () {
        std::cout<<"Name: "<<name<<std::endl;
        std::cout<<"Author: "<<author<<std::endl;
        std::cout<<"Price: "<<price<<std::endl;
        std::cout<<"Date Issued: "; date.display_date();
        std::cout<<"Late Fee: "<<fee<<std::endl;
        std::cout<<"Unique Idenitifcation Number: "<<id<<std::endl;
    }
    void issue_book() {
        std::cout<<"Enter name of the issuer: ";
        std::cin>>issuer;
        date.input_date();
    }
    void book_return() {
        calculate_fee();
        if(fee!=0) std::cout<<"This book has been returned late. A fee of "<<fee<<" must be charged"<<std::endl;
        else std::cout<<"Book returned on time. No late fee charged!"<<std::endl;
        date.reset_date();
        strcpy(issuer,"Not issued by anybody yet");
    
        
    }

// Late fee is charged when the book is returned after two weeks or more of the date of issue.
//    If the book is returned after a month or later, a late fee equal to the price of the book is charged.
    
    void calculate_fee() {
        Date current_date;
        current_date.input_date();
        if (current_date.month== date.month) {
            if (current_date.day- date.day>=14)
                fee= current_date.day- date.day;
            else fee=0;
            }
        if (current_date.month!=date.month) {
            if (30-date.day+ current_date.day>=30)
                fee= price;
            if (30-date.day+ current_date.day>=14)
                fee= 30-date.day+ current_date.day;
            else fee=0;
        }
    }
};

// implimentation of a binary tree:
struct node {
    Book B;
    node *left;
    node *right;
};

class btree {
public:
    btree();
    
    void insert(Book B, node *leaf);
    void insert(Book B);
    node *search(int id, node *leaf);
    node *root;
    void destroy_tree();
    void destroy_tree(node *leaf);
    
};
btree::btree() { root=NULL;}

void btree::destroy_tree(node *leaf) {
    if (leaf!=NULL) // until the root is reached
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    } }

void btree::insert(Book B, node *leaf)
{
    if(B.id<leaf->B.id) {
        if(leaf->left!=NULL)
            insert(B, leaf->left);
        
        else {
            leaf->left= new node; // creates a new node at the left of the leaf
            leaf->B= B;
            leaf->left->left= NULL; //sets the left leaf of the new node to null
            leaf->left->right= NULL; // sets the right leaf of the new node to null
        } }
    if (B.id>=leaf->B.id) {
        if (leaf->right!=NULL)
            insert(B,leaf->right);
        else {
            leaf->right= new node;
            leaf->B=B;
            leaf->right->left=NULL;
            leaf->right->left=NULL;
            
        }
    } }
node *btree::search(int id, node *leaf)
{
    if(id==leaf->B.id) return leaf;
    if(id<leaf->B.id) return search(id, leaf->left);
    else return search(id, leaf->right);
}
void btree::destroy_tree()
{ destroy_tree(root); }

void btree::insert(class Book B) {
    if(root!=NULL) insert(B, root);
    else { root=new node;
        root->B=B;
        root->left=NULL;
        root->right=NULL;
    }
}
// main function starts
int main() {
    char ans;
    Book books[100];
    btree booktree;
    // menu
    while(ans!='Q')
    {
        std::cout<<"Enter an operation: A. Add more books B. Issue a book C. Return a book D. Display a book Q. Quit ";
        std::cin>>ans;
        switch(ans) {
            case 'A': { int n;
                std::cout<<"How many books would you like to add today? "; std::cin>>n;
                for(int i=0; i<n; i++) {
                    books[i].input_book();
                    booktree.insert(books[i]);
                    std::cout<<std::endl; } }
                break;
            case 'B': { int id;
                std::cout<<"Enter Book ID of the book to be issued: "; std::cin>>id;
                node *bnode= booktree.search(id, booktree.root);
                bnode->B.issue_book();
        }
                break;
            case 'C': { int id;
                std::cout<<"Enter Book ID of the book to be returned: "; std::cin>>id;
                node *bnode= booktree.search(id, booktree.root);
                bnode->B.book_return(); }
                break;
                
            case 'D': {
                int id;
                std::cout<<"Enter the Book ID of the book to be displayed: "; std::cin>>id;
                node *bnode= booktree.search(id, booktree.root);
                bnode->B.display_book();
            }
                break;
        
    }
    
}
}

