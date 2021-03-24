// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <string>
#include "List.h"
using namespace std;
//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) {
  List l{};

  REQUIRE( l.isEmpty() == true );
  REQUIRE( l.size() == 0 );
}
TEST_CASE("Insertion")
{
    List l{};

    l.insert(3);
    l.insertAtHead(2);
    l.insertAtHead(1);
    l.insertAtHead(0);
    l.insertAtTail(4);
    l.insert(5);

    REQUIRE(l.size() == 6);

    CHECK(l.traverse(0) == 0);
    CHECK(l.traverse(5) == 5);
    CHECK(l.traverse(3) == 3);

    CHECK_FALSE(l.traverse(4) == 2);
    CHECK_FALSE(l.traverse(2) == 1);
}

TEST_CASE("Deletion")
{
    List l{};

    l.insert(6);
    l.insert(7);
    l.insert(8);
    l.insert(9);
    l.insert(10);
    
    l.deleteAtHead();
    l.deleteAtTail();
    l.deleteAtIndex(2);

    REQUIRE(l.size() == 2);

    CHECK_FALSE(l.traverse(0) == 6);
    CHECK_FALSE(l.traverse(5) == 10);

    CHECK(l.traverse(1) == 8);
}

TEST_CASE("Print")
{
    List l{};
    string str1{};
    string str2{"1 2 3"};

    CHECK(str1 == l.print());
    
    l.insert(1);
    l.insert(2);
    l.insert(3);

    CHECK(str2 == l.print());
}

TEST_CASE("Copying and Moving")
{
    List l1{};
    List l2{};
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);

    l2 = l1;
    List l3{l1};


    CHECK(l1.size() == l2.size());
    CHECK(l1.size() == l3.size());
    CHECK(l3.size() == l2.size());

    CHECK_FALSE(l1.print() == " ");

    l1.deleteAtTail();
    List l4(move(l1));

    CHECK(l4.print() == "1 2 3 4");

    List k{};
    k.insert(5);
    k.insert(3);
    k.insert(6);

    List l{};
    l=move(k);

    CHECK(l.print() == "3 5 6");
    CHECK(k.print() != "3 5 6");

}