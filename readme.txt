A_INTRO
this program builds a linked list and assigns random priority number to each item.
user can choose how big the list is, display list, sort by bubble sort and delete list.

B_INSTRUCTION
COMPILE: type "make" into terminal
RUN: type "./main" into terminal to run program

C_PSUEDOCODEL

MAIN
	INITIALISE IORB HEAD
	LISTSIZE = 10
 WHILE(1)
	DISPLAY MENU
	GET INPUT FROM USER
	CHECK INPUT VALIDITY
	SWITCH CASE DEPENDING ON INPUT
		0. EXIT PROGRAM
		1. BUILD LIST
			GET RANDOM PRIORITY
			CREATE FILLER
			INSERT TO LIST
				CREATE NEW BLOCK
				ADD DATA TO NEW BLOCK
				ADD OLD HEAD POINTER TO NEW'S NEXT LINK
				UPDATE NEW BLOC AS NEW HEAD
		2. DISPLAY LIST
			CHECK IF LIST IS EMPTY
			CREATE TEMP BLOCK LINKED TO BEGINNING OF LIST
			WHILE TEMP BLOCK IS NOT NULL
				PRINT OUT FILLER OF TEMP BLOCK
				UPDATE TEMP BLOCK'S NEXT LINK
			END WHILE
		3. SORT LIST
			CHECK IF LIST IS EMPTY
			SORT LIST BY PARSING BEGINNING OF LIST TO BUBBLESORT FUNCTION
				COMPARE CURRENT AND NEXT BLOCK
				IF CURRENT IS BIGGER THAN NEXT, SEND TO SWAP
					CREAT TEMP BLOCK AND STORE NEXT'S NEXT
					NEXT BLOCK UPDATE TO CURRENT
					CURRENT UPDATE TO TEMP(PREVIOUS NEXT'S NEXT)
					RETURN SMALLER BLOCK
				MOVE TO NEXT BLOCK
				IF LIST SORTED, BREAK
		4. DELETE LIST
			WHILE HEAD POINTER IS NOT EMPTY
				CREATE TEMP BLOCK
				IF HEAD BLOCK IS NOT NULL, HEAD POINTER UPDATE TO THE NEXT BLOCK
				FREE TEMP BLOCK
			END WHILE
	END SWITCH
 END WHILE
END MAIN

D_TEST

i ran the program 10 times, every time building, displaying, sorting and deleting the list. 
below is a sample output

1. build linked list
2. display list, displaying computed priority
	166
	346
	484
	316
	280
	88
	34
	268
	70
	508
3. sort list
4. display sorted list, displaying computed priority
	34
	70
	88
	166
	268
	280
	316
	346
	484
	508
	expected results
5. delete list
6. exit program

E_LIMITATIONS
the program outputs expected results.
