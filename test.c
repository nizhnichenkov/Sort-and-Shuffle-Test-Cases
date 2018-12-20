//
//  testFactorial.c
//  cunit_testing
//
//  Created by denisov_slav on 01/05/2018.
//  Copyright © 2018 #denisov. All rights reserved.
//
#include "CUnit.h"
#include "Basic.h"
#include <string.h>
#include "sortAndShuffle.h"
#include <time.h>

/* testing the FisherYates function */
void FisherYates_pass(void){
    int pos_int[] = {3, 4, 5, 6}; // positive integers
    int neg_int[] = {-5, -22, -11, -433, -1004}; // negative integers
    int mix_int[] = {1, -1, 2, -2, 3, -3}; // mixed integers
    
    // checking whether the algorithm shuffles the positive integers
    fisherYates(pos_int, 4);
    CU_ASSERT(pos_int[0] != 3 && pos_int[1] != 4 && pos_int[2] != 5 && pos_int[3] != 6);
    
    // checking whether the algorithm shuffles the negative integers
    fisherYates(neg_int, 5);
    CU_ASSERT(neg_int[0] != -5 && neg_int[1] != -22 && neg_int[2] != -11 && neg_int[3] != -433 && neg_int[4] != 1004);
    
    // checking whether the algorithm shuffles the mixed integers
    fisherYates(mix_int, 6);
    CU_ASSERT(mix_int[0] != 1 && mix_int[1] != -1 && mix_int[2] != 2 && mix_int[3] != -2 && mix_int[4] != 3 && mix_int[5] != -3);
}

/* testing the QucikSort function */
void QuickSort_pass(void){
    int pos_int[] = {99, 33, 11, 10, 3}; // positive integers
    int neg_int[] = {-12, -44, -1, -7, -27}; // negative integers
    int mix_int[] = {99, -44, -1, 33, -7}; // mixed integers
    
    // checking whether the algorithm orders the positive integers in an increasing way
    quickSort(pos_int, 5);
    CU_ASSERT(pos_int[0] == 3 && pos_int[1] == 10 && pos_int[2] == 11 && pos_int[3] == 33 && pos_int[4] == 99);
    
    // checking whether the algorithm orders the negative integers in an increasing way
    quickSort(neg_int, 5);
    CU_ASSERT(neg_int[0] == -44 && neg_int[1] == -27 && neg_int[2] == -12 && neg_int[3] == -7 && neg_int[4] == -1);
    
    // checking whether the algorithm orders the mixed integers in an increasing way
    quickSort(mix_int, 5);
    CU_ASSERT(mix_int[0] == -44 && mix_int[1] == -7 && mix_int[2] == -1 && mix_int[3] == 33 && mix_int[4] == 99);
}

/* testing FisherYates function with incorrect assertions */
void FisherYates_fail(void){
    int pos_int[] = {17, 1, 35, 10, 11}; // positive integers
    int neg_int[] = {-13, -44, -3, -11, -47}; // negative integers
    int mix_int[] = {1, -2, 33, -33, -27}; // mixed
    int empty_arr[] = {}; // empty array
    float fl_arr[] = {5.33, 4.12, -3.11, 9.23}; // floating point array
    int one_arr[] = {1}; // array with one element
    
    // checking whether the test fails when checking if the positions haven't been changed on an array with positive integers
    fisherYates(pos_int, 5);
    CU_ASSERT(pos_int[0] == 17 || pos_int[1] == 1 || pos_int[2] == 35 || pos_int[3] == 10 || pos_int[4] == 11);
    
    // checking whether the test fails when checking if the positions haven't been changed on an array with negative integers
    fisherYates(neg_int, 5);
    CU_ASSERT(neg_int[0] == -13 || neg_int[1] == -44 || neg_int[2] == -3 || neg_int[3] == -11 || neg_int[4] == -47);
    
    // checking whether the test fails when checking if the positions haven't been changed on an array with mixed integers
    fisherYates(mix_int, 5);
    CU_ASSERT(mix_int[0] == 1 || mix_int[1] == -2 || mix_int[2] == 33 || mix_int[3] == -33 || mix_int[4] == -27);
    
    // checking whether a fail would be issued if there's an array with no elements
    fisherYates(empty_arr, 0);
    CU_ASSERT(empty_arr[0] == NULL);
    
    // checking whether the test fails when checking if the positions haven't been changed on an array with floats
    fisherYates(fl_arr, 4);
    CU_ASSERT(fl_arr[0] == 5.33 || fl_arr[1] == 4.12 || fl_arr[2] == -3.11 || fl_arr[3] == 9.23);
    
    // checking whether there would be a fail if there's an integer array with 1 element
    fisherYates(one_arr, 1);
    CU_ASSERT(one_arr[0] != 1);
    
}

/* testing QuickSort function with incorrect assertions */
void QuickSort_fail(void){
    int pos_int[] = {3, 5, 1, 77, 89}; // positive integers
    int mix_int[] = {14, 1, 0, -99, -3}; // mixed
    int neg_int[] = {-1, -99, -1234, -7, -9999}; // negative integers
    int empty_arr[] = {}; // empty array
    float fl_arr[] = {1.32, -4.11, -3.12, 5.55}; // floating point array
    int one_arr[] = {1}; // array with one element
    
    
    // checking whether quicksort would fail if the condition is looking for the values at the same places
    // but they would be changed since the first element is greater than some of the others
    quickSort(pos_int, 5);
    CU_ASSERT(pos_int[0] == 3 && pos_int[1] == 5 && pos_int[2] == 1 && pos_int[3] == 77 && pos_int[4] == 89);
    
    // checking whether quicksort would fail if the condition is looking for the values at the same places,
    // which results in a fail, since the elements are not entered in an increasing way
    quickSort(mix_int, 5);
    CU_ASSERT(mix_int[0] == 14 && mix_int[1] == 1 && mix_int[2] == 0 && mix_int[3] == -99 && mix_int[4] == -3);

    // checking whether quicksort would fail if the condition is looking for the values at the same places,
    // which results in a fail, since the elements are not entered in an increasing way
    quickSort(neg_int, 5);
    CU_ASSERT(neg_int[0] == -1 && neg_int[1] == -99 && neg_int[2] == -1234 && neg_int[3] == -7 && neg_int[4] == -9999);
    
    // nothing to be done here, as there are no elements and we have a condition which would fail
    quickSort(empty_arr, 0);
    CU_ASSERT(empty_arr[0] == NULL);
    
    // checking whether quicksort would fail if the condition is looking for the values at the same places,
    // which results in a fail, since the elements are not entered in an increasing way and the type is float and not int
    quickSort(fl_arr, 4);
    CU_ASSERT(fl_arr[0] == 1.32 || fl_arr[1] == -4.11 || fl_arr[2] == -3.12 || fl_arr[3] == 5.55);
    
    // no sorting is to be done here, and the assertion is looking for a different value at the only place possible,
    // which results in a fail.
    quickSort(one_arr, 1);
    CU_ASSERT(one_arr[0] != 1);
}

void runAllTests(){
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("suite", 0, 0);
    
    
    CU_add_test(suite, "FisherYates_pass", FisherYates_pass);
    CU_add_test(suite, "QuickSort_pass", QuickSort_pass);
    CU_add_test(suite, "FisherYates_fail", FisherYates_fail);
    CU_add_test(suite, "QuickSort_fail", QuickSort_fail);
    
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
}

int main() {
    runAllTests();
    
    return 0;
}


