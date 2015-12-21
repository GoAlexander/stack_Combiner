stack_Combiner


stack_Combiner is the stack program with a lot of additional features. It was made as university task (HSE).

Features of stack_Combiner:
-stack on basis of singly linked list
-support of basic operations on stack:
	push
	pop
	top
	isempty
-sorting of elements in singly linked list
-building and visualization of AVL-tree
-values of stack are special class which contains (in the same time):
	1) decimal value (int)
	2) binary value (vector) (supporting of standart binary and two`s complement conceptions)
-user can enter values in different forms (the program will convert value to another):
	positive decimal
	negative decimal
	standart binary
	two`s complement

==================================================

Some notes:
This code is not so ideal. There are some things which could be more effective. It needs also some refactoring but it works! :)

==================================================

Compilation:
g++ -std=c++11 main.cpp stack.cpp value.cpp avltree.cpp -o bin/stack_Combiner.out

(c++11 because of stoi())

==================================================

How to use stack_Combiner you can read in the program.

==================================================

Some information for testing of program:
AVL-tree:
	Insert:
		25 50 40 30 20 10
	The tree will be:
			30
           /  \
         20   40
        /  \     \
       10  25    50
    Preorder
    	30 20 10 25 40 50

Bin/dec convertions:
10 -> 01010
15 -> 01111

01010 -> 10
01111 -> 15

-10 -> 1111111111110110
-15 -> 1111111111110001

1111111111110110 -> -10
1111111111110001 -> -15

==================================================

Some good links:
http://neerc.ifmo.ru/wiki/index.php?title=Стек
https://www.quora.com/How-do-I-implement-an-AVL-tree-in-code
http://kukuruku.co/hub/cpp/avl-trees
http://habrahabr.ru/post/150732/
http://ci-plus-plus-snachala.ru/?p=57

Visualization of tree:
http://www.sanfoundry.com/cpp-program-implement-avl-trees/
https://www.cs.usfca.edu/~galles/visualization/AVLtree.html
