CS 162 Assignment #4 Part 1: Hunt the Wumpus & Part 2: Recursion
Name: Troy Diaz
ONID: 934417663
Section: CS 162-001
Assignment 4, due 3/17/2024

Part 1
Description:

Welcome to Hunt the Wumpus! The game is designed around an adventurer who is looking
for gold in a grid and escapes with the treasure alive. While searching for gold, the
adventurer must avoid or deal with obstacles such as the Wumpus, stalactites, and being
submerged underwater. Messages or percepts are displayed to the adventurer to warn or
draw attention to events in the game.

Instructions:

1) Compile the program:

make clean && make

2) Run the program:

./wumpus

The program will prompt you:

Side length of cave:

Here, give it a number between 5 and 50 inclusive. Then, the program will ask you if you
want the game in debug mode or not.

Debug mode? (1/0):

For testing purposes, use 1. For regular gameplay, use 0. Here is an example of a game
that has debug mode on and is a 5x5 size grid. Here, it will prompt you for directional
inputs such as WASD and F to fire an arrow. The goal is to avoid the stalactites (S)
that has a 50% chance of killing the player, use the pools (P) to traverse the grid
without interacting with the events, fire an arrow (press f) when it’ll surely hit the
Wumpus (W) or the Wumpus will have a 75% chance of moving, grab the Gold (G) and return
back to the start (~).

There are indicators or precepts when the player is near an event. These percepts only
appear if the character is directly above, below, to the left/right of them. An arrow
count is given to the player. Oxygen levels indicate how many moves a player has to
exit the pools.

Arrows remaining: 3
Oxygen Level: 10
-------------------------
   || S || W ||   ||   ||
-------------------------
   || G || S || P ||   ||
-------------------------
 P ||   ||   ||   ||   ||
-------------------------
   ||   ||   ||   ||*~ ||
-------------------------
   ||   ||   ||   ||   ||
-------------------------

Player move...

W-up
A-left
S-down
D-right
f-fire an arrow
Enter input:

Limitations:
- Once you choose a direction, you cannot take it back.
- If you inputted to fire an arrow, you must fire it in a specific direction.

What is the hierarchy of the classes? Which classes represent a “has-a” relationship,
which classes represent an “is-a” relationship?

The Event class is the abstract base class, and the derived classes are: Gold, Pool,
Stalactites, and Wumpus. Those derived Event classes also share an is-a relationship.
The Room class has-a relationship with the Event class.

Which function(s) did you make virtual? Pure virtual? Please explain why.

The destructor() in the Event class is virtual. I made this function virtual initially
because the program needed to free up the dynamic memory that pointed to the Event objects.
In the end, I did not use Event object pointers.

The percept() and encounter() functions in the Event class are pure virtual. I made these
pure virtual because I would be reusing these functions in the derived Event classes.

Did you implement the Big 3 for any classes? If yes, why? If not, why not?

In my game.cpp and game.h files, I included a constructor, destructor, copy constructor,
and assignment operator overload. However, they are not called anywhere in my program.
This is because I used the vector library primarily to deal with dynamic memory allocation.
I don’t use any new keywords to indicate dynamic memory allocation, as in my program,
I call functions just to set a room to be true or false to indicate an event/player is
in that room. Copying member variables was not needed because the vector library handles
copies.

Part 2
Description:
This program, stairs, will solve a recursion problem based on a staircase with N steps.
There are small, medium and large steps. It calculates the combinatorial ways to reach
the top of a staircase given a nonnegative integer N steps using small (1), medium (2),
and large (3) steps.

Instructions:
1) Compile the program:

make clean && make

2) Run the program:

./stairs

The program will prompt you:

Value of n:

To which you give it a nonnegative integer that is preferably less than 20. Then it will
display Ways to top with n steps:

Value of n: 19
Ways to top with 19 steps: 66012
2
4
7
13

The following numbers are testing cases. They calculate the ways to top using 2, 3, 4,
and 5 steps.

Limitations:
- The larger n gets, the program will output slower.

What is your thought process when designing the recursive function? How did you determine
the base case and recursive call(s) for your function?

My design needed base cases and a recursive call in my return statement. I knew this was
a combinatorial problem and required to return the sum of ways using small, medium, and
large steps of n. My program has two base cases when n = 0 and n < 0. There is only one
way to the top when n = 1. There is no way to the top if n is negative. And then we get
to the return statement, there are three subtasks: ways_to_top(n-1), ways_to_top(n-2),
and ways_to_top(n-3) each handling the different ways to the top. These calculate the
remaining steps to the top and stop when the recursive call hits one of the base cases.
In the final step, we add it all together because we want the total number of ways to
the top.

In this assignment, which requirement did you find most challenging? How did you
overcome it? What would you do differently if given a second chance?

For part 1 of this assignment, the most challenging part was writing this program
polymorphically. I needed ways to break up my code and not include it all in one .cpp or
.h file. Polymorphism helped me define a common interface with each .h file. If I were
to do this differently, I could have done more with the encounter functionality, as most
of it is in my Game files.

For part 2 of this assignment, the most challenging part was writing the recursive
statement. Although it was a smaller problem than part 1, I referred back to the demos
in class and thought about how to design a program to calculate the ways to the top of
the stairs given N steps using recursive calls. I thought about how it needed to break
down the value of N and reach the top. Throughout the process, I was running into
logical errors, but I could identify the correct number of base cases and include the
right number of types of steps in this program. I feel this is as simple as it gets, if
I were given another chance I would do it the same way again.