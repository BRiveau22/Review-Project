/*#define BOOST_TEST_MODULE Gradebook_Tests
#include <boost/test/included/unit_test.hpp>
#include "gradebook.h"

BOOST_AUTO_TEST_SUITE(GradebookTests)

BOOST_AUTO_TEST_CASE(ConstructorTest)
{
    std::string file_name = "grades.txt";
    Gradebook gradebook(file_name);
    BOOST_CHECK(gradebook.Search_Grades().size(), 0);
    BOOST_CHECK(gradebook.Filter_Grades().size(), 0);
    BOOST_CHECK(gradebook.names_vector.size(), 0);
    BOOST_CHECK(gradebook.grades_vector.size(), 0);
    BOOST_CHECK(gradebook.categories_vector.size(), 0);
    BOOST_CHECK(gradebook.courses_vector.size(), 0);
}

BOOST_AUTO_TEST_CASE(AddGradesTest)
{
    std::string file_name = "grades.txt";
    Gradebook gradebook(file_name);
    gradebook.Add_Grades();
    BOOST_CHECK(gradebook.Search_Grades().size(), 1);
    BOOST_CHECK(gradebook.Filter_Grades().size(), 1);
    BOOST_CHECK(gradebook.names_vector.size(), 1);
    BOOST_CHECK(gradebook.grades_vector.size(), 1);
    BOOST_CHECK(gradebook.categories_vector.size(), 1);
    BOOST_CHECK(gradebook.courses_vector.size(), 1);
}

BOOST_AUTO_TEST_CASE(EditGradeTest)
{
    std::string file_name = "grades.txt";
    Gradebook gradebook(file_name);
    gradebook.Add_Grades();
    int index = 0;
    gradebook.Edit_Grade(index);
    BOOST_CHECK(gradebook.Search_Grades()[index], 90);
}

BOOST_AUTO_TEST_CASE(DeleteGradeTest)
{
    std::string file_name = "grades.txt";
    Gradebook gradebook(file_name);
    gradebook.Add_Grades();
    int index = 0;
    gradebook.Del_Grade(index);
    BOOST_CHECK(gradebook.Search_Grades().size(), 0);
    BOOST_CHECK(gradebook.Filter_Grades().size(), 0);
    BOOST_CHECK(gradebook.names_vector.size(), 0);
    BOOST_CHECK(gradebook.grades_vector.size(), 0);
    BOOST_CHECK(gradebook.categories_vector.size(), 0);
    BOOST_CHECK(gradebook.courses_vector.size(), 0);
}

BOOST_AUTO_TEST_CASE(ReadGradesTest)
{
    std::string file_name = "grades.txt";
    Gradebook gradebook(file_name);
    gradebook.Read_Grades();
    BOOST_CHECK(gradebook.Search_Grades().size(), 2);
    BOOST_CHECK(gradebook.Filter_Grades().size(), 2);
    BOOST_CHECK(gradebook.names_vector.size(), 2);
    BOOST_CHECK(gradebook.grades_vector.size(), 2);
    BOOST_CHECK(gradebook.categories_vector.size(), 2);
    BOOST_CHECK(gradebook.courses_vector.size(), 2);
}

BOOST_AUTO_TEST_CASE(DisplayGradesFullTest)
{
    std::string file_name = "grades.txt";
    Gradebook gradebook(file_name);
    gradebook.Read_Grades();
    gradebook.Display_Grades_Full();
}

BOOST_AUTO_TEST_CASE(DisplayCategoryTotalsTest)
{
    std::string file_name = "grades.txt";
    Gradebook gradebook(file_name);
    gradebook.Read_Grades();
    gradebook.Display_Category_Totals();
}

BOOST_AUTO_TEST_CASE(DisplayCourseOverallTest)
{
    std::string file_name = "grades.txt";
    Gradebook gradebook(file_name);
    gradebook.Read_Grades();
    gradebook.Display_Course_Overall();
}

BOOST_AUTO_TEST_SUITE_END()*/