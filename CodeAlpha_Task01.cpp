//#include <iostream>
//#include <iomanip>
//#include <limits>
//using namespace std;
//
//float getValidFloat(string prompt, float min, float max) 
//{
//    float value;
//    while (true) 
//    {
//        cout << prompt;
//        cin >> value;
//        if (cin.fail() || value < min || value > max) 
//        {
//            cout << "Invalid input.Please enter a number between " << min << " and " << max << ".\n";
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
//        }
//        else 
//        {
//            return value;
//        }
//    }
//}
//int getValidInt(string prompt, int min) 
//{
//    int value;
//    while (true) 
//    {
//        cout << prompt;
//        cin >> value;
//        if (cin.fail() || value < min)
//        {
//            cout << "nvalid input. Please enter an integer ≥ " << min << ".\n";
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        }
//        else 
//        {
//            return value;
//        }
//    }
//}
//
//int main() 
//{
//    int numCourses = getValidInt("Enter number of courses taken: ", 1);
//
//    float grades[100], credits[100];
//    float totalCredits = 0, totalGradePoints = 0;
//
//    for (int i = 0; i < numCourses; ++i)
//    {
//        cout << "\nCourse " << i + 1 << ":\n";
//        grades[i] = getValidFloat("Enter grade (0.0 - 4.0): ", 0.0, 4.0);
//        credits[i] = getValidFloat("Enter credit hours (>0): ", 0.1, 100);
//
//        totalCredits += credits[i];
//        totalGradePoints += grades[i] * credits[i];
//    }
//
//    float GPA = totalGradePoints / totalCredits;
//
//    float previousCGPA = getValidFloat("\nEnter previous CGPA (0.0 - 4.0): ", 0.0, 4.0);
//    float previousCredits = getValidFloat("Enter previous total credit hours (≥ 0): ", 0.0, 1000.0);
//
//    float CGPA = (GPA * totalCredits + previousCGPA * previousCredits) / (totalCredits + previousCredits);
//
//   
//    cout << fixed << setprecision(2);
//    cout << "\n\n--- Course Summary ---\n";
//    for (int i = 0; i < numCourses; ++i)
//    {
//        cout << "Course " << i + 1 << ": Grade = " << grades[i]
//            << ", Credit Hours = " << credits[i] << endl;
//    }
//
//    cout << "\n Semester GPA: " << GPA;
//    cout << "\n Overall CGPA: " << CGPA << endl;
//
//    return 0;
//}
