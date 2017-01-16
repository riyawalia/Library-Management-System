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



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

class Date {
    int year, month, day;
    void Date() {
        year=0; month=0; day=0;
    }
    void display-date () {
        if (year==0 && month ==0 && day==0)
        {
            std::cout<<"Book not issued yet"<<endl;
        }
        else {
        std::cout<<day<<"."<<month<<"."<<year<<endl;
    }
    void input-date(int d, int m, int y) {
        date=d; month=m; year=y;
    }
};

class Book {
    int price, fee;
    char author[], name[];
    Date date;
    void input-book (char bauthor[], char bname[], int bprice, Date bdate, int bfee) {
        author= bauthor;
        name= bname;
        fee= bfee;
        price= bprice;
        date=bdate;
    }
    void display-book () {
        std::cout<<"Name: "<<name<<endl;
        std::cout<<"Author: "<<author<<endl;
        std::cout<<"Price: "<<price<<endl;
        std::cout<<"Date Issued: "<<name<<endl;
        std::cout<<"Late Fee: "<<fee<<endl;
    }
// Late fee is charged when the book is returned after two weeks or more of the date of issue.
//    If the book is returned after a month or later, a late fee equal to the price of the book is charged.
    
    void calculate-fee() {
        int d, m, y;
    std:cout<<"Enter the current date in ddmmyyyy format:";
        std::cin>>d>>std::cin>>m>>y;
        Date current-date;
        current-date.input-date(d m y);
        if (current-date.month== date.month) {
            if (current-date.day- date.day>=14)
                fee= current-date.day- date.day;
            else fee=0;
            }
        if (current-date.month!=date.month) {
            if (30-date.day+ current-date.day>=30)
                fee= price;
            if (30-date.day+ current-date.day>=14)
                fee= 30-date.day+ current-date.day;
            else fee=0;
        }
    }
};

