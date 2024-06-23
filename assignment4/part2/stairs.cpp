int ways_to_top(int n) 
{
	// base cases:
	if (n == 0)
	{
		// only one way to top
		return 1;
	}
	else if (n < 0)
	{
		// no negative steps
		return 0;
	}

	// returning sum of combinatorial ways to top
	return ways_to_top(n-1) + ways_to_top(n-2) + ways_to_top(n-3);
}
