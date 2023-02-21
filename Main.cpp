//Main.cpp
#include "gradebook.h"
#include <vector>
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
	//std::string file_name = argv[1];
    std::string file_name = "/Users/connorstubbs/Desktop/URI Freshman/CSC 212/Projects/Review Project/Review-Project/Gradebook_Test.txt";
	Gradebook current_gradebook(file_name);
    current_gradebook.Read_Grades();
	std::cout << "Welcome to your virtual gradebook!\nWhat would you like to do today?" << std::endl;
	current_gradebook.Generate_Home_UI();
}