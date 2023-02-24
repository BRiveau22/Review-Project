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

1. Once you have compiled the program you are ready to interact with your virtual gradebook. You will be presented with a menu where you can enter an integer between 1-7 to choose an option. The first option available is to enter 1 to access the different grade display functions. Now you will be see a menu where you can input an integer between 1-4. These options are:

  View All - If you enter 1, every individual grade will be printed along with the name of the grade, points achieved, possible points, category, and the course name.
  
 View Categories and Course - If you enter 2, the name of each course will be printed out along with the points earned in each category. At the bottom, the total points earned in the course will be printed. 
 
 View Course - If you enter 3, the grade for each class will be displayed as a percentage.
 
 Home - If you enter 4, you will be brought back to the home menu
 
2. From the main menu, you can enter 2 to access the edit grades option. While using this option, you will be need to input the index of the grade in the data file (starting at index 1), the name of the assignment, the points you received, the total points available, the type of assignment(homework, quiz, exam, etc...), and the name of the course. This allows you to change whichever aspect of the grade that you need to. Afterwards, you will be retunred to the main menu.

3. Option 3 on the main menu will let you activate add grade function. Similarily to the edit function, you will be prompted to enter the name of the assignment, points received, possible points, assignment type, and course name. After adding the grade, you can enter 1 to add another grade or enter 2 to return to the home menu.

4. Opposite of the previous option, option 4 allows you to delete a grade. After entering 4 you will be prompted to enter the index(starting at 1) of the grade that you wih to be deleted. The grade and all its data will be deleted and you will be returned to the main menu.

5. Option 5 allows you to see a filtered list of all of your grades. The first four options allow you to filter by specific categories (name, course, type of assignment, and grade). Option 5 allows you to search across all categories at once. Lastly, option 6 brings you back home.

6. Once you decide that you would liken overwrite your original text files of grades with the changes you have made, select option 6. All of the new data will overwrite your new data, so be sure that the changes you made are what you want.

7. Finally, entering 7 will exit the program.
 
 
  
  
