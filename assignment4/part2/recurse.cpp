/********************************************************************* 
** Program Filename: stairs
** Author: Troy Diaz
** Date: 03/18/24
** Description: Solve a recursion problem based on a staircase with N steps. 
There are small, medium and large steps.
** Input: N (Number of Steps in Staircase)
** Output: Number of ways to reach top
*********************************************************************/

// The following is an example program that
// does some basic, limited testing of your
// ways_to_top() implementation.

#include <iostream>

#include "stairs.h"

using namespace std;

int main() 
{
	int n = 0;
	
	cout << "Value of n: ";
	cin >> n;

	cout << "Ways to top with " << n << " steps: " << ways_to_top(n) << endl;

	cout << ways_to_top(2) << endl;
	cout << ways_to_top(3) << endl; // Should print 4
	cout << ways_to_top(4) << endl; // Should print 7
	cout << ways_to_top(5) << endl; // Should print 13

}
