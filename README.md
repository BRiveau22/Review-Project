# Review Project - Gradebook
Group Members: Connor Stubbs, Grant Garcia, James Allen, and Ben Corriveau

Summary: This project is an interactive gradebook written in C++. Users can input a file of their grades through the command line and then view the grades with different filters as well as edit, add, and delete their grades. Once the user is done they can save their changes which will be overwritten in the file. 


Planning:

1. Write the scaffold for our main.cpp, gradebook.h, and, gradebook.cpp.
  a. Main - Hold name of file from the command line in a variable, open the file, call function to read the file, and output UI.
  
  b. Gradebook.h - Create function skeletons UI, reading, displaying, editing, adding, and deleting grades. Set private varaibles for vectors for each piece of data for each grade(name,grade,total,category,course), number of elements, and the name of the file.
  
  c. Gradebook.cpp - Write fucnction skeletons from Gradebook.h and process data with read function.
  
2. Assign functions to group members

  Ben - Write, Read, Delete, check negatitves, check valid, input handlers, and UI functions
  
  Connor - Three display functions
  
  James - Search and Filter functions
  
  Grant - Add and Edit Functions
  
3. Merge branches to the master once all functions are finished and make them compile together.
 
4. Write compilation and runtime instructions
 
 
Runtime Instructions:

1. Once you have compiled the program you are ready to interact with your virtual gradebook. You will be presented with a menu where you can enter an integer between 1-7 to choose an option. The first option available is to enter "1" to access the different grade display functions. Now you will be see a menu where you can input an integer between 1-4. These options are:

  View All - If you enter 1, every individual grade will be printed along with the name of the grade, points achieved, possible points, category, and the course name
  
 View Categories and Course - If you enter 2, the name of each course will be printed out along with the points earned in each category. At the bottom, the total points earned in the course will be printed. 
 
 
  
  
