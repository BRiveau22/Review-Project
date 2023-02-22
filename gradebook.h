//gradebook.h
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Gradebook {
private:
	std::string file_name;
	int num_elements;
	std::vector<std::string> names_vector;
	std::vector<int> grades_vector;
	std::vector<std::string> categories_vector;
	std::vector<std::string> courses_vector;
public:
	Gradebook(std::string file_name);
	std::vector<int> Search_Grades();//text input from user, outputs a vector of results
	std::vector<int> Filter_Grades();
	void Add_Grades();
	void Edit_Grade(int index);//user inputs the index and specifies what aspect of the grade should be changed
	void Del_Grade(int index);//delete grade at given index
	void Read_Grades();//use file name to open file and put data into respective vectors
	void Write_Changes();//write to the input file using vectors

    //take vectors and display information to the user
	void Display_Grades_Full();
	void Display_Category_Totals();
	void Display_Course_Overall();

    //UI functions generate the text-based UI
    //UI functions will call input_handler functions to handle user input
	void Action1_Input_Handler(int choice);
	void Generate_Action1_UI();
	void Action2_Input_Handler(int choice);
	void Generate_Action2_UI();
	void Action3_Input_Handler(int choice);
	void Generate_Action3_UI();
	void Action4_Input_Handler(int choice);
	void Generate_Action4_UI();
	void Action5_Input_Handler(int choice);
	void Generate_Action5_UI();
	void Action6_Input_Handler(int choice);
	void Generate_Action6_UI();
	void Home_Input_Handler(int choice);
	void Generate_Home_UI();
};