//gradebook.cpp
#include "gradebook.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

Gradebook::Gradebook(std::string file_name) {
	this->file_name;
}

std::vector<int> Gradebook::Search_Grades() {
	std::vector<int> output_indexes;
    //create a input variable with a input handling function


    std::vector<int>::iterator it;
//    it = find(grades_vector.begin(), grades_vector.end(), input);
//    if (it != grades_vector.end())
//    //    std::cout << "Element found in myvector: " << *it << '\n';
//    //  else
//    //    std::cout << "Element not found in myvector\n";
//    for(int i = 0; i < this->grades_vector.size(); i++){
//        if(input )
//    }

	return output_indexes;
}

std::vector<int> Gradebook::Filter_Grades() {
	std::vector<int> output_indexes;
	return output_indexes;
}

void Gradebook::Add_Grades() {
	//Adds user-specified grades until user enters exit code
}

void Gradebook::Edit_Grade(int index) {
	//User can edit grade at specified index
}

void Gradebook::Del_Grade(int index) {
	//User can delete grade at specified index
	names_vector.erase(names_vector.begin() + index);
	grades_vector.erase(grades_vector.begin() + index);
	categories_vector.erase(categories_vector.begin() + index);
	courses_vector.erase(courses_vector.begin() + index);
}

void Gradebook::Read_Grades() {
	//Reads grades from file and puts them in the correct vector
	std::ifstream in_file(file_name);
	std::string line = "";
	int line_location = 0;

	while (in_file.is_open() && std::getline(in_file, line)) {
		std::istringstream current_line(line);

		while (std::getline(current_line, line, ',')) {
			if (line_location % 4 == 0) {
				names_vector.push_back(line);
			}
			else if (line_location % 4 == 1) {
				grades_vector.push_back(std::stoi(line));
			}
			else if (line_location % 4 == 2) {
				categories_vector.push_back(line);
			}
			else if (line_location % 4 == 3) {
				courses_vector.push_back(line);
			}
			line_location++;
		}
	}
	in_file.close();
}

void Gradebook::Write_Changes() {
	//Writes changes to the in_file
	std::ofstream out_file(file_name);

	out_file.close();
}

void Gradebook::Display_Grades_Full() {
	//Displays all grades
}

void Gradebook::Display_Category_Totals() {
	//Displays all category totals and the course overall grade
}

void Gradebook::Display_Course_Overall() {
	//Displays only the course overall grade
}

void Gradebook::Action1_Input_Handler(int choice) {
	if (choice == 1) {
		return Display_Grades_Full();
	}
	else if (choice == 2) {
		return Display_Category_Totals();
	}
	else if (choice == 3) {
		return Display_Course_Overall();
	}
	else if (choice == 4) {
		return Generate_Home_UI();
	}
}

void Gradebook::Generate_Action1_UI() {
	int choice = -1;
	bool valid_choice = false;
	std::cout << "\n1 - View All" << std::endl;
	std::cout << "2 - View Categories and Course" << std::endl;
	std::cout << "3 - View Course" << std::endl;
	std::cout << "4 - Home" << std::endl;
	std::cout << "\nPlease enter a value from 1-4" << std::endl;

	//Runs until a valid choice is input by the user
	while (!valid_choice) {
		std::cin >> choice;
		if (choice < 1 || choice > 4) {
			std::cout << "Please enter a valid option" << std::endl;
		}
		else {
			valid_choice = true;
		}
	}

	Action1_Input_Handler(choice);
}

void Gradebook::Action2_Input_Handler(int choice) {

}

void Gradebook::Generate_Action2_UI() {
	int edit_index = -1;
	bool valid_choice = false;
	int max_index = 10;

	//Checks for valid index
	std::cout << "Please enter index of grade which you wish to edit:" << std::endl;
	while (!valid_choice) {
		std::cin >> edit_index;
		if (edit_index < 0 || edit_index > max_index) {
			std::cout << "Please enter a valid index" << std::endl;
		}
		else {
			valid_choice = true;
		}
	}

	Edit_Grade(edit_index);
}

void Gradebook::Action3_Input_Handler(int choice) {

}

void Gradebook::Generate_Action3_UI() {
	std::cout << "Add grades" << std::endl;
	Add_Grades();
}

void Gradebook::Action4_Input_Handler(int choice) {

}

void Gradebook::Generate_Action4_UI() {
	int del_index = -1;
	bool valid_choice = false;
	int max_index = 10;
	
	//Checks for valid index
	std::cout << "Please enter index of grade which you wish to delete:" << std::endl;
	while (!valid_choice) {
		std::cin >> del_index;
		if (del_index < 0 || del_index > max_index) {
			std::cout << "Please enter a valid index" << std::endl;
		}
		else {
			valid_choice = true;
		}
	}
	
	Del_Grade(del_index);
}

void Gradebook::Action5_Input_Handler(int choice) {

}

void Gradebook::Generate_Action5_UI() {
	std::cout << "Search Grades" << std::endl;
	
	int choice = -1;
	bool valid_choice = false;
	std::cout << "\n1 - Search by Name" << std::endl;
	std::cout << "2 - Search by Course" << std::endl;
	std::cout << "3 - Search by Category" << std::endl;
	std::cout << "4 - Search by Grade" << std::endl;
	std::cout << "5 - Home" << std::endl;
	std::cout << "\nPlease enter a value from 1-5" << std::endl;

	//Runs until a valid choice is input by the user
	while (!valid_choice) {
		std::cin >> choice;
		if (choice < 1 || choice > 5) {
			std::cout << "Please enter a valid option" << std::endl;
		}
		else {
			valid_choice = true;
		}
	}

	Action5_Input_Handler(choice);
}

void Gradebook::Action6_Input_Handler(int choice) {

}

void Gradebook::Generate_Action6_UI() {
	std::cout << "Save Changes" << std::endl;
	Write_Changes();
}

int Gradebook::Home_Input_Handler(int choice) {
	if (choice == 1) {
		Generate_Action1_UI();
	}
	else if (choice == 2) {
		Generate_Action2_UI();
	}
	else if (choice == 3) {
		Generate_Action3_UI();
	}
	else if (choice == 4) {
		Generate_Action4_UI();
	}
	else if (choice == 5) {
		Generate_Action5_UI();
	}
	else if (choice == 6) {
		Generate_Action6_UI();
	}
	else if (choice == 7) {
		return 0;
	}
}

void Gradebook::Generate_Home_UI() {
	int choice = -1;
	bool valid_choice = false;
	//Generates the startup text-based UI for the user
	std::cout << "\n1 - View Grades" << std::endl;
	std::cout << "2 - Edit Grades" << std::endl;
	std::cout << "3 - Add Grades" << std::endl;
	std::cout << "4 - Delete Grades" << std::endl;
	std::cout << "5 - Search Grades" << std::endl;
	std::cout << "6 - Save Changes" << std::endl;
	std::cout << "7 - Exit Application" << std::endl;
	std::cout << "\nPlease enter a value from 1-7" << std::endl;
	
	//Runs until a valid choice is input by the user
	while (!valid_choice) {
		std::cin >> choice;
		if (choice < 1 || choice > 7) {
			std::cout << "Please enter a valid option" << std::endl;
		}
		else {
			valid_choice = true;
		}
	}

	Home_Input_Handler(choice);
}