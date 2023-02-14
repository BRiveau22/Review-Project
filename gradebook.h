//gradebook.h
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Gradebook {
private:
	std::string file_name;
	std::vector<std::string> names_vector;
	std::vector<int> grades_vector;
	std::vector<std::string> categories_vector;
	std::vector<std::string> courses_vector;
	std::vector<int> grade_breakdown;
public:
	Gradebook(std::string file_name);
	std::vector<int> Search_Grades();
	std::vector<int> Filter_Grades();
	void Add_Grades();
	void Edit_Grade(int index);
	void Del_Grade(int index);
	void Read_Grades();
	void Write_Changes();
	void Display_Grades_Full();
	void Display_Category_Totals();
	void Display_Course_Overall();
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