#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>


TEST_CASE("random code") {
    CHECK(snowman(14221212)== std::string("       \n _===_ \n (o o)/\n<( : ) \n (\" \") \n"));      
/*   _===_ 
     (o o)/
    <( : ) 
     (" ")     */
   CHECK(snowman(43421243)== std::string("  ___  \n (_*_) \n (-_o)/\n<(   ) \n (___) \n"));
/*    ___  
     (_*_) 
     (-_o)/
    <(   ) 
     (___)      */

    CHECK(snowman(32132141)== std::string("   _   \n  /_\\  \n\\(..O) \n (   )>\n ( : ) \n"));
/*     _   
      /_\  
    \(..O) 
     (   )>
     ( : )    */
    CHECK(snowman(12442324)== std::string("       \n _===_ \n\\(O.O) \n (] [)\\\n (   ) \n"));
/*         
     _===_ 
    \(O.O) 
     (] [)\
     (   )      */
    CHECK(snowman(44444444)== std::string("  ___  \n (_*_) \n (- -) \n (   ) \n (   ) \n"));
/*    ___  
     (_*_) 
     (- -) 
     (   ) 
     (   )      */
}


TEST_CASE("check all HAT") {
    /*
    this is basic snowman code: (11111111) 

     _===_ 
     (.,.) 
    <( : )>
     ( : ) 
    */

    CHECK(snowman(11111111)== std::string("       \n _===_ \n (.,.) \n<( : )>\n ( : ) \n"));
    CHECK(snowman(21111111)== std::string("  ___  \n ..... \n (.,.) \n<( : )>\n ( : ) \n"));
    CHECK(snowman(31111111)== std::string("   _   \n  /_\\  \n (.,.) \n<( : )>\n ( : ) \n"));
    CHECK(snowman(41111111)== std::string("  ___  \n (_*_) \n (.,.) \n<( : )>\n ( : ) \n"));
}

TEST_CASE("check all nose and mouth") {
    CHECK(snowman(12111111)== std::string("       \n _===_ \n (...) \n<( : )>\n ( : ) \n"));// can be? not look good/
    CHECK(snowman(13111111)== std::string("       \n _===_ \n (._.) \n<( : )>\n ( : ) \n"));
    CHECK(snowman(14111111)== std::string("       \n _===_ \n (. .) \n<( : )>\n ( : ) \n"));
}

TEST_CASE("check all left eyes") {
    CHECK(snowman(11211111)== std::string("       \n _===_ \n (o,.) \n<( : )>\n ( : ) \n"));
    CHECK(snowman(11311111)== std::string("       \n _===_ \n (O,.) \n<( : )>\n ( : ) \n"));
    CHECK(snowman(11411111)== std::string("       \n _===_ \n (-,.) \n<( : )>\n ( : ) \n"));
}

TEST_CASE("check all right eyes") {
    CHECK(snowman(11121111)== std::string("       \n _===_ \n (.,o) \n<( : )>\n ( : ) \n"));
    CHECK(snowman(11131111)== std::string("       \n _===_ \n (.,O) \n<( : )>\n ( : ) \n"));
    CHECK(snowman(11141111)== std::string("       \n _===_ \n (.,-) \n<( : )>\n ( : ) \n"));
}

TEST_CASE("check all left arms") {
    CHECK(snowman(11112111)== std::string("       \n _===_ \n\\(.,.) \n ( : )>\n ( : ) \n"));
    CHECK(snowman(11113111)== std::string("       \n _===_ \n (.,.) \n/( : )>\n ( : ) \n"));
    CHECK(snowman(11114111)== std::string("       \n _===_ \n (.,.) \n ( : )>\n ( : ) \n"));
}

TEST_CASE("check all right arms") {
    CHECK(snowman(11111211)== std::string("       \n _===_ \n (.,.)/ \n<( : ) \n ( : ) \n"));
    CHECK(snowman(11111311)== std::string("       \n _===_ \n (.,.) \n<( : )\\\n ( : ) \n"));
    CHECK(snowman(11111411)== std::string("       \n _===_ \n (.,.) \n<( : ) \n ( : ) \n"));
}

TEST_CASE("check all torso") {
    CHECK(snowman(11111121)== std::string("       \n _===_ \n (.,.) \n<(] [)>\n ( : ) \n"));
    CHECK(snowman(11111131)== std::string("       \n _===_ \n (.,.) \n<(> <)>\n ( : ) \n"));// can be?? he has 4 arm! maybe it should be only if both arm are null..
    CHECK(snowman(11111141)== std::string("       \n _===_ \n (.,.) \n<(   )>\n ( : ) \n"));
}

TEST_CASE("check all bases") {
    CHECK(snowman(11111112)== std::string("       \n _===_ \n (.,.) \n<( : )>\n (\" \") \n"));
    CHECK(snowman(11111113)== std::string("       \n _===_ \n (.,.) \n<( : )>\n (___) \n"));
    CHECK(snowman(11111114)== std::string("       \n _===_ \n (.,.) \n<( : )>\n (   ) \n"));
}

TEST_CASE("Good snowman code- whird call") {
    auto temp = std::string("   _   \n  /_\\  \n (O_O) \n/(> <)\\\n (___) \n");
    /* (33333333)
        _  
       /_\ 
      (O_O) 
     /(> <)\
      (___) 
    */
    // all the below call is the same in diffrent way.
    // there are tset for me to undestand function call in cpp
    CHECK(snowman(33333333) == temp);
    CHECK(snowman(11111111*3) == temp);
    CHECK(snowman(11111111+22222222) == temp);
    CHECK(snowman(11111111*3) == temp);
    //CHECK(snowman(33333333.22) == temp); // 
    int x = 33333333;
    CHECK(snowman(x)== temp);
}


TEST_CASE("out of range 1-4: higher value") {
    CHECK_THROWS(snowman(71111111)); //start with high value.
    CHECK_THROWS(snowman(51111111)); //start with high value.

    CHECK_THROWS(snowman(11111911)); // in rhe middel
    CHECK_THROWS(snowman(11611111)); // in rhe middel
    CHECK_THROWS(snowman(11118111)); // in rhe middel
    CHECK_THROWS(snowman(17119111)); // 2 in rhe middel

    CHECK_THROWS(snowman(11111115)); // in the end.
    CHECK_THROWS(snowman(11111116)); // in the end.
}
TEST_CASE("out of range 1-4: lower value") {
    CHECK_THROWS(snowman(01111111)); //start with low value.
    CHECK_THROWS(snowman(11011111)); // in rhe middel
    CHECK_THROWS(snowman(11111011)); // in rhe middel
    CHECK_THROWS(snowman(11011101)); // 2 in rhe middel
    CHECK_THROWS(snowman(11111110)); // in the end.
}

TEST_CASE("Incorrect input size") {
    CHECK_THROWS(snowman(0)); // small input size .
    CHECK_THROWS(snowman(111)); // small input size .
    CHECK_THROWS(snowman(112423211)); // big input size 
}
TEST_CASE("negative input") {
    CHECK_THROWS(snowman(-11111111)); //negative number
    CHECK_THROWS(snowman(-24124123)); //negative number
    CHECK_THROWS(snowman(-124)); //negative and short number
}
