/* ============================================================
 * Name        : CourseListBST.cpp
 * Author      : Jordan Clark
 * Version     : 1.0
 * Description : This program opens a .txt file to
 *               extract the course number, course title,
 *               and list of prerequites for each course.
 *               The data is stored and sorted on a binary
 *               search tree. The user can choose 1 to load
 *               data, 2 to print the whole list, 3 to view
 *               1 course and its prerequisites, or 4 to exit.
 * ============================================================
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

// ============================================================
//                               GLOBAL DEFINITIONS
// ============================================================

// Structure to hold course information
/*
 * Each course contains a course number, title, and a vector to
 * store as many prerequisites as the course contains.
 */
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;

    Course() {}
};

// Structure to hold BST Node
/*
 * Each node in BST contains course info, and both left & right
 * children.
 */
struct Node {
    Course course;
    Node* left;
    Node* right;

    // Constructor to create empty node
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // Constructor to create node with data
    Node(Course aCourse) : Node() {
        this->course = aCourse;
    }
};

// ============================================================
//                               CLASS DEFINITION
// ============================================================

// Create class
class CourseListBST {

private:
    Node* root;

    void addNode(Node* node, Course course);
    void printInOrderList(Node* node);
    void printCourse(Node* node, string courseNumber);

public:
    CourseListBST();
    virtual ~CourseListBST();
    void DeleteNode(Node* node);
    void Insert(Course course);
    int NumPreCourse(Course course);
    void PrintCourseList();
    void PrintCourseInfo(string courseNumber);
};

// ============================================================
//                               CONSTRUCT BINARY SEARCH TREE
// ============================================================

// Initialize root with constructor
CourseListBST::CourseListBST() 
{
    root = nullptr;
}

// Deconstructor to erase node
CourseListBST::~CourseListBST()
{
    DeleteNode(root);
}


// Delete Node: Takes in node parameter, deletes recursively
void CourseListBST::DeleteNode(Node* node)
{
    if (node)
    {
        DeleteNode(node->left);
        DeleteNode(node->right);
        delete node;
    }
}

/* Insert Node : Takes course parameter, initializes node
 *               with course info or adds node to tree */
void CourseListBST::Insert(Course course)
{
    if (root == nullptr)
    {
        root = new Node(course);
    } 
    else
    {
        this->addNode(root, course);
    }
}

/* Number of Prerequisites: Takes a course parmeter, loops 
 *                          through prerequisites vector &
 *                          returns count.              */
int CourseListBST::NumPreCourse(Course course)
{
    int count = 0;
    for (int i = 0; i < course.prerequisites.size(); i++)
    {
        if (course.prerequisites.at(i).length() > 0)
        {
            count++;
        }
    } 
    return count;
}

/* Print List: Points root node to print in order
 *             list function                   */
void CourseListBST::PrintCourseList()
{
    this->printInOrderList(root);
}


/* Print Course: Takes course number and sends root and 
 *               course number to printCourse()      */
void CourseListBST::PrintCourseInfo(string courseNumber)
{
    this->printCourse(root, courseNumber);
}

/* Add Node: Takes in node and course, adds node to left or right
 *           side of tree; creates new node if empty           */
void CourseListBST::addNode(Node* node, Course course)
{
    if (node->course.courseNumber.compare(course.courseNumber) > 0)
    {
        if (node->left == nullptr)
        {
            node->left = new Node(course);
        }
        else
        {
            this->addNode(node->left, course);
        }
    }
    else
    {
        if (node->right == nullptr)
        {
            node->right = new Node(course);
        }
        else
        {
            this->addNode(node->right, course);
        }
    }
}

/* void CourseListBST::printCourseInfo(Node* node)
{
    cout << node->course.courseNumber << "," << node->course.courseTitle << endl;
} */

// print List In Order
void CourseListBST::printInOrderList(Node* node) 
{
    if (node != nullptr)
    {
        printInOrderList(node->left);

        cout << node->course.courseNumber << "," << 
        node->course.courseTitle << endl;

        printInOrderList(node->right);
        
    }
    return;
}


// Print Course With Prerequisites
void CourseListBST::printCourse(Node* curr, string courseNumber)
{
    while (curr != nullptr)
    {
        if (curr->course.courseNumber.compare(courseNumber) == 0)
        {
            cout << '\n' << curr->course.courseNumber << ", " << 
            curr->course.courseTitle << endl;
            
            unsigned int size = NumPreCourse(curr->course);
            cout << "Prerequisite(s): ";

            unsigned int i = 0;
            for (i = 0; i < size; i++)
            {
                cout << curr->course.prerequisites.at(i);
                if ( i != size -1)
                {
                    cout << ", ";
                }
            } 
            if (i == 0)
            {
                cout << "No required prequisites." << endl;
            }return;
        }
        else if (courseNumber.compare(curr->course.courseNumber) < 0)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    cout << "Course " << courseNumber << " not found." << endl;
}

// ============================================================
//                               STATIC METHODS FOR TESTING
// ============================================================

// Parse through file
vector<string> parsedLine(const string& split, const string& delim = ",")
{
    vector<string> tokens;
    size_t start = 0, end = split.find(delim);
    while ( end != string::npos)
    {
        tokens.push_back(split.substr(start, end - start));
        start = end + delim.size();
        end = split.find(delim, start);
    }
    tokens.push_back(split.substr(start, end - start));
    return tokens;
}

// Load course from file
vector<Course> loadCourseFile(CourseListBST& courseTree)
{
    //CourseListBST courseTree;
    ifstream fin;
    vector<Course> courses;
    string line;

    fin.open("CourseInformation.txt");

    if (fin.fail())
    {
        cout << "\nFile failed to open.\n" << endl;
    }
    
    while (getline(fin, line))
    {
        if (line == "-1") break;

        Course course;
        vector<string> tokenized = parsedLine(line);

        course.courseNumber = tokenized[0];
        course.courseTitle = tokenized[1];

        for (int i = 2; i < tokenized.size(); ++i)
        {
            vector<string> prereqs = parsedLine(tokenized[i], ",");

            for (const string& prereq : prereqs)
            {
                Course prereqCourse;
                prereqCourse.courseNumber = prereq;
                prereqCourse.courseTitle = " ";
                course.prerequisites.push_back(prereq);
                courseTree.Insert(prereqCourse);
            }
        }
        courseTree.Insert(course);
       
    }

    fin.close();
    cout << "\nSuccess!\n" << endl;
    return courses;
}

// Display Menu
void menu() 
{
    CourseListBST courseTree;
    vector<Course> courses;
    int choice = 0;
    string userCourse;
    
    while (true) 
    {
        cout << "\nWelcome to the course planner.\n";
        cout << "  1. Load Data Structure\n";
        cout << "  2. Print Course List\n";
        cout << "  3. Print Course\n";
        cout << "  4. Exit\n";
        cout << "\nWhat would you like to do? ";
        
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        try {
            switch (choice) {
            
                case 1:
                    // Load Data Structure
                    loadCourseFile(courseTree);
                    //cout << "Test 1 Pass." << endl;
                    break;
        
                case 2:
                    // Print course list
                    cout << "\nHere is a sample schedule:\n";
                    courseTree.PrintCourseList();
                    cout << endl;
                    break;
                
                case 3:
                    // Print course
                    cout << "\nWhich course would you like to know about? ";
                    //string userCourse;
                    cin >> userCourse;
                    cout << endl;

                    courseTree.PrintCourseInfo(userCourse);
                    cout << endl;
                    break;
                
                case 4:
                    // Exit
                    cout << "\nThank you for using the ABCU course planner.\nGoodbye." << endl;
                    return;
                    break;
                    
                
                default:
                    // Input validation
                    throw runtime_error("\nPlease enter an option 1 through 4.\n");
            
            }
        }
        catch (const exception& e)
        {
            std::cerr << e.what() << endl;
        }
    }
}

// ============================================================
//                               MAIN
// ============================================================

int main() 
{
    //cout << "\nTEST PASS\n" << endl;
    menu();

    return 0;
}
