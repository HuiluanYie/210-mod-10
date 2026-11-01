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

const int WAITING = 0, SERVING = 1, FINISHED = 2;
const int TIME = 25, NUM_OF_EVENT = 3;

// Function prototypes
void display(const map<string, array<list<int>, 3>>&);
void time_run(map<string, array<list<int>, 3>>&);

// Define main function
int main()
{
    // Initialize a map to store the food-station information, 
    //   each associated with an array of lists for 
    //   waiting students, students being served, students who got food.
    map<string, array<list<int>, NUM_OF_EVENT>> cafeteria;
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
        cafeteria[station][WAITING].push_back(student_id);
    }
    // Close the file
    fin.close();

    // disply the current cafeteria(for testing)
    display(cafeteria);

    // Begin a time-based simulation for the cafeteria.
        // For TIME time intervals
            // call the finction to simulate changes

            // Wait or pause briefly to simulate the passage of time between intervals
// End of main function
    return 0;
}


// Define a function to display the cafeteria.
    // Parameters: map of food stations.
void display(const map<string, array<list<int>, NUM_OF_EVENT>>& c)
{
    // For each food station:
        // Display the station's name, the students in the waiting list, 
        // in the serving list, and in the finished list.
    for (auto s : c)
    {
        cout << "\nFood station: " << s.first << '\n';

        cout << "Waiting: ";
        for (int id : s.second[WAITING])
        {
            cout << id << ' ';
        }
        cout << "Serving: ";
        for (int id : s.second[SERVING])
        {
            cout << id << ' ';
        }
        cout << "Finished: ";
        for (int id : s.second[FINISHED])
        {
            cout << id << ' ';
        }
    }
}

// Define a function to simulate a time period run.
    // Parameters: map of food stations
void time_run(map<string, array<list<int>, NUM_OF_EVENT>>& c)
{
    // for each food station in the map
        // Randomly select one of the three possible events.
    for (auto s : c)
    {
        int event = rand() % NUM_OF_EVENT;

        switch (event)
        {
        case 0:
            // Event 1: Serve students.
            if (s.second[SERVING].empty())
            {
                if (s.second[WAITING].empty())
                {
                    cout << "No student needs serving.";
                }
                else
                {
                    int id = s.second[WAITING].front();
                    cout << "Student #" << id << " is now being served.";
                    s.second[WAITING].pop_front();
                    s.second[SERVING].push_back(id);
                }
            }
            else
            {
                int id = s.second[SERVING].front();
                    cout << "Student #" << id << " is has been sussesfully served.";
                    s.second[SERVING].pop_front();
                    s.second[FINISHED].push_back(id);
            }
            break;

        case 1:
            // Event 2: A student changes lines.
            if (s.second[WAITING].empty())
            {
                cout << "No student in line.\n";
            }
            break;

        case 2:
            // Event 3: Service delay.
            break;
        
        default:
            break;
        }
    }
    
    
}
