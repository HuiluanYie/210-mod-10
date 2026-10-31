// COMSC-210 | Lab 30 | Huiluan Yie

// Include necessary headers for file handling, data structures, 
// strings, random numbers, and console input/output.
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <array>
#include <list>
using namespace std;

// Define a function to display the cafeteria.
    // Parameters: map of food stations.

    // For each food station:
        // Display the station's name, the students in the waiting list, 
        // in the serving list, and in the finished list.

// Define a function to simulate a time period run.
    // Parameters: map of food stations, number of intervals.

    // for each food station in the map
        // Randomly select one of the three possible events.


// Define main function
int main()
{
    // Initialize a map to store the food-station information, 
    //   each associated with an array of lists for 
    //   waiting students, students being served, students who got food.
    map<string, array<list<int>, 3>> cafeteria;
    string station;
    int student_id;

    // Open an external file to read initial data about the food-stations and populate the map
    ifstream fin("students.txt");
    // If file does not open, print an error and exit
    if (!fin)
    {
        cout << "Fail to open file.";
        return -1;
    }
    // Read data from file and populate map
    // For each line, extract food-station name and student(ID number)
    while (fin >> station >> student_id)
    {
        // Add the student the correct food station in the map.
        cafeteria[station].[]
    }

    // Close the file
    fin.close();

    // Begin a time-based simulation for the cafeteria.
        // For 20 time intervals
            // call the finction to simulate changes

            // Wait or pause briefly to simulate the passage of time between intervals
// End of main function
    return 0;
}
