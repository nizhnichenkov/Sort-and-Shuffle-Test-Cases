COMP10050 ASSIGNMENT 4 

Student Name: Svetoslav Nizhnichenkov
Student ID: 17712081

4 test cases have been implemented: 

1. FisherYates_pass
	•	A test case which tests the correctness of the algorithm. 
	•	3 assertions have been implemented: 
	1.	An array with only positive integers
	2.	An array with only negative integers
	3.	An array with mixed integers 
	•	Each assertion checks whether the places of the values have been changed. 

2. FisherYates_fail 
	•	A test case which fails using incorrect assertions 
	•	6 assertions have been implemented: 
	1.	An array with only positive integers - checks whether each element has remained at its place, which will result in a fail. 
	2.	An array with only negative integers - checks whether each element has remained at its place. 
	3.	An array with mixed integers - checks whether each element has remained at its place. 
	4.	An empty array - checks whether the first element is equal to NULL, which in my case is a fail since the empty array’s been given a garbage value. 
	5.	A float array - checks whether each element has remained at its place, also a warning was issued stating that I’m passing a float to a parameter of type ‘int’. 
	6.	An array with only one element - checking whether the first element has changed its place, but since there’s no other element in the array, that would result in a fail. 

3. QuickSort_pass
	•	A test case testing the correctness of the algorithm 
	•	3 assertions have been implemented: 
	1.	An array with only positive integers
	2.	An array with only negative integers
	3.	An array with mixed integers
	•	Each assertion checks whether the values are in increasing order. 

4. QuickSort_fail 
	•	A test case which fails using incorrect assertions
	•	6 assertions have been implemented: 
	1.	An array with only positive integers - checks whether each element has remained at its place, which is not the case, and this would result in a fail. 
	2.	An array with only negative integers - checks whether each element has remained at its place, which results in a fail. 
	3.	An array with mixed integers - results in a fail. 
	4.	An empty array - checks whether the first element is NULL, which is not the case (I think that mainly depends on the state of the machine). 
	5.	A float array - checks the same condition as explained earlier, the issue here is that I’m passing floats to a parameter of type ‘int’, that issues a warning and also fails. 
	6.	An integer array with only one element - checks whether the position of the element changes, which results in a fail, since there is only one element and there are no more places available for it to be moved elsewhere. 


