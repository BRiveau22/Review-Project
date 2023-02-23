//gradebook.cpp
#include "gradebook.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

Gradebook::Gradebook(std::string file_name) {
	this->file_name = file_name;
	this->num_elements = 0;
}


int valid_choice(int num_choices) {
	bool valid_choice = false;
	int choice;

	while (!valid_choice) {
		std::cin >> choice;
		if (choice >= 1 && choice <= num_choices) {
			valid_choice = true;
		}
		else {
			std::cout << "Please enter a valid option" << std::endl;
		}
	}
	return choice;
}

std::vector<int> Gradebook::Search_Grades() {
    std::vector<int> output_indexes;
    std::string input;
    std::cout << "Please enter what you want to search for:" << std::endl;
    std::cin >> input;

    for(int i = 0; i < num_elements; i++){
        if(input == std::to_string(grades_vector[i]) || input == names_vector[i] || input == categories_vector[i] || input == courses_vector[i]){
            output_indexes.push_back(i);
        }
    }

    if(output_indexes.empty()){
        std::cout << "Search results empty" << std::endl;
    }

    return output_indexes;
}

std::vector<int> Gradebook::Filter_Grades(std::string filter_category) {
	std::vector<int> output_indexes;

    std::string input;
    std::cout << "Please enter what you want to filter by (current grouping is " + filter_category + "):" << std::endl;
    std::cin >> input;

    for(int i = 0; i < num_elements; i++){
        if(filter_category == "grade" && std::stoi(input) == grades_vector[i]) {
            output_indexes.push_back(i);
        }
        else if(filter_category == "name" && input == names_vector[i]) {
            output_indexes.push_back(i);
        }
        else if(filter_category == "category" && input == categories_vector[i]) {
            output_indexes.push_back(i);
        }
        else if(filter_category == "course" && input == courses_vector[i]) {
            output_indexes.push_back(i);
        }
    }

    if(output_indexes.empty()){
        std::cout << "Filter results empty" << std::endl;
    }

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

		//Based on the location in the line, the value will be placed in the proper vector
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
		num_elements++;
	}
	in_file.close();
}

void Gradebook::Write_Changes() {
	//Opens the in_file to write to it
	std::ofstream out_file(file_name);
	std::string line = "";

	//Writes changes to the in_file
	for (int i = 0; i < names_vector.size(); i++) {
		line.append(names_vector[i]);
		line.append(std::to_string(grades_vector[i]));
		line.append(categories_vector[i]);
		line.append(courses_vector[i]);
		line.append("\n");
		out_file << line;
	}

	out_file.close();
}

void Gradebook::Display_Grades_Full() {
	//Displays all grades
    std::cout <<  "Names\tGrades\tCategories\tCourses" << std::endl;
    std::cout << "____________________________________" << std::endl;
    for(int i=0; i<this->grades_vector.size(); i++){
        std::cout << names_vector[i] << "\t" << grades_vector[i] << "    \t" << categories_vector[i] << "\t" << courses_vector[i] << std::endl;
        std::cout << "____________________________________" << std::endl;
    }
    Generate_Action1_UI();
}

void Gradebook::Display_Category_Totals() {
	//Displays all category totals and the course overall grade
    std::vector<std::string> cats_vector;
    std::vector<std::string> courses;
    std::vector<int> points_vector;


    // Finds all unique courses and categories
    for(int i=0; i<this->grades_vector.size(); i++){
        if(std::find(cats_vector.begin(), cats_vector.end(), categories_vector[i]) == cats_vector.end()){
            cats_vector.push_back(categories_vector[i]);
        }

        if(std::find(courses.begin(), courses.end(), courses_vector[i]) == courses.end()){
            courses.push_back(courses_vector[i]);
        }
    }

    std::vector<std::vector<int>> course_points(courses.size(), std::vector<int>(cats_vector.size()));

    // Finds points per category
    for(int j=0; j<cats_vector.size(); j++) {
        points_vector.push_back(0);
        for (int k = 0; k < this->grades_vector.size(); k++) {
            if (cats_vector[j] == this->categories_vector[k]) {
                points_vector[j] += this->grades_vector[k];
            }
        }
    }

    // Finds points per course
    for(int p=0; p<courses.size(); p++){
        for(int r=0; r<this->grades_vector.size(); r++){
            if(courses[p] == this->courses_vector[r]){
                for(int c=0; c<cats_vector.size(); c++){
                    if(cats_vector[c] == this->categories_vector[r]){
                        course_points[p][c] += this->grades_vector[r];
                    }
                }
            }
        }
    }

    // Prints the course, overall course grade, and category grades for the course
    for(int course=0; course<courses.size(); course++){
        std::cout << "Course: " << courses[course] << std::endl;
        int course_total_points = 0;

        for(int cat=0; cat<cats_vector.size(); cat++){
            bool found_cat = false;
            for(int r=0; r<this->grades_vector.size(); r++){
                if(courses[course] == this->courses_vector[r] && cats_vector[cat] == this->categories_vector[r]){
                    if(!found_cat){
                        std::cout << "\t" << cats_vector[cat] << std::endl;
                        found_cat = true;
                    }
                }
            }
            if(found_cat){
                std::cout << "\t\tCategory Total Points: " << course_points[course][cat] << std::endl;
                course_total_points += course_points[course][cat];
            }
        }
        std::cout << "\tOverall Course Grade: " << course_total_points << std::endl;
        std::cout << "____________________________________" << std::endl;
    }
    Generate_Action1_UI();
}

void Gradebook::Display_Course_Overall() {
	//Displays only the course overall grade
    std::vector<std::string> courses;
    std::vector<int> points;

    // Finds all unique courses
    for(int i=0; i<this->grades_vector.size(); i++){
        if(std::find(courses.begin(), courses.end(), courses_vector[i]) == courses.end()){
            courses.push_back(courses_vector[i]);
        }
    }

    // Finds grades for each course
    for(int p=0; p<courses.size(); p++) {
        points.push_back(0);
        for (int r = 0; r < this->grades_vector.size(); r++) {
            if (courses[p] == this->courses_vector[r]) {
                points[p] += this->grades_vector[r];
            }
        }
    }

    std::cout << "Course\tGrade" << std::endl;
    std::cout << "____________________________________" << std::endl;
    //Prints our courses and their grades
    for(int course=0; course<courses.size(); course++){
        std::cout << courses[course] << "\t" << points[course] << std::endl;
        std::cout << "____________________________________" << std::endl;
    }
    Generate_Action1_UI();
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
	std::cout << "\n1 - View All" << std::endl;
	std::cout << "2 - View Categories and Course" << std::endl;
	std::cout << "3 - View Course" << std::endl;
	std::cout << "4 - Home" << std::endl;
	std::cout << "\nPlease enter a value from 1-4" << std::endl;

	//Runs until a valid choice is input by the user
	choice = valid_choice(4);

	Action1_Input_Handler(choice);
}

void Gradebook::Action2_Input_Handler(int choice) {

}

void Gradebook::Generate_Action2_UI() {
	int edit_index = -1;

	//Checks for valid index
	std::cout << "Please enter index of grade which you wish to edit:" << std::endl;
	edit_index = valid_choice(num_elements - 1);

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
	
	//Checks for valid index
	std::cout << "Please enter index of grade which you wish to delete:" << std::endl;
	del_index = valid_choice(num_elements - 1);
	
	Del_Grade(del_index);
}

void Gradebook::Action5_Input_Handler(int choice) {
    if(choice == 1){
		std::vector<int> filtered_grades = Filter_Grades("name");
		//Displays grades to the user (create new function to display grades at found indexes)
		Generate_Action5_UI();
    } 
	else if (choice == 2) {
		std::vector<int> filtered_grades = Filter_Grades("course");
		Generate_Action5_UI();
	}
	else if (choice == 3) {
		std::vector<int> filtered_grades = Filter_Grades("category");
		Generate_Action5_UI();
	}
	else if (choice == 4) {
		std::vector<int> filtered_grades = Filter_Grades("grade");
		Generate_Action5_UI();
	}
	else if (choice == 5) {
		std::vector<int> filtered_grades = Search_Grades();
		Generate_Action5_UI();
	}
	else if (choice == 6) {
        return Generate_Home_UI();
    }
}

void Gradebook::Generate_Action5_UI() {
	int choice = -1;
	std::cout << "Search Grades" << std::endl;
	std::cout << "\n1 - Search by Name" << std::endl;
	std::cout << "2 - Search by Course" << std::endl;
	std::cout << "3 - Search by Category" << std::endl;
	std::cout << "4 - Search by Grade" << std::endl;
	std::cout << "5 - Search All" << std::endl;
	std::cout << "6 - Home" << std::endl;
	std::cout << "\nPlease enter a value from 1-6" << std::endl;

	//Runs until a valid choice is input by the user
	choice = valid_choice(6);

	Action5_Input_Handler(choice);
}

void Gradebook::Action6_Input_Handler(int choice) {

}

void Gradebook::Generate_Action6_UI() {
	Write_Changes();
	std::cout << "Your changes have been written to " << file_name  << std::endl;
	return Generate_Home_UI();
}

void Gradebook::Home_Input_Handler(int choice) {
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
		EXIT_SUCCESS;
	}
}

void Gradebook::Generate_Home_UI() {
	int choice = -1;
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
	choice = valid_choice(7);

	Home_Input_Handler(choice);
}