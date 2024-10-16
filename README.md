# PROJECT--Timetable-Management-System
This C program generates timetables for two sections (A and B) of a computer engineering course. It assigns subjects and activities (labs, lunch, etc.) to time slots randomly. Functions print the timetable in different views: numeric, subject names, or faculty IDs. Data is read from files, and labs are scheduled without overlap between sections..



This is a C program designed to generate and display timetables for two sections (A and B) of a computer engineering course. The program includes functions to print various versions of the timetable (numeric, human-readable, and staff-based) and uses randomized allocation to assign subjects and activities (like lunch or sports) to different time slots throughout the week.

Key Components of the Code:
Structure Definition (details):

A struct named details stores information about faculty members and subjects. Each faculty has a name, coursecode, sec (section), coursetype (e.g., lecture or lab), dep (department), facid (faculty ID), and subid (subject ID).
Global Variables:

data[8]: An array of details structs to store information about 8 different faculty members (one for each subject).
Timetable Representation (tt[5][7]):

The timetable is represented as a 2D array where each row represents a day (Monday to Friday), and each column represents an hour slot from 8:15 AM to 3:30 PM.
Functions:
numtt(int tt[5][7]):

Prints the timetable as an integer grid, where each integer represents a subject or activity (e.g., 1 for MAT, 2 for EEE, etc.).
maintt(int tt[5][7]):

Prints a human-readable timetable using the actual subject names instead of numbers. It converts the integer values from tt[5][7] into subject names like MAT, EEE, CS, etc., and adds labels for days and time slots.
staff(int subjectno):

Looks up the faculty ID for a given subject number (subid) and prints it. This is used to display which faculty member is teaching a subject during a specific time slot.
stafftt(int tt[5][7]):

Similar to maintt, but instead of printing subject names, this prints the faculty IDs for each time slot based on the subject being taught.
Timetable Generation:
Random Timetable Generation Logic:

The program uses randomized scheduling to assign subjects to various time slots. Several arrays and data structures help in this process:
diffstaff_subarrayy[], diffstaff_subid[], and diffstaff_maxhr[]: Arrays to store details about subjects with different staff.
samestaff_subarray[], samestaff_subid[], and samestaff_maxhr[]: Arrays for subjects that share the same staff.
addcls_subarray[], addcls_subid[], and addcls_maxhr[]: Arrays for additional classes like library, mentor sessions, or sports.
Timetable Initialization:

nullallot(int tt[5][7]): Initializes all values in the timetable matrix to 0 (empty slots).
lunchallot(int tt[5][7]): Assigns the 4th hour of each day to lunch by setting it to 9.
Subject Assignment:

The program manually assigns lab hours and then randomly allocates other subjects to free time slots, ensuring that no subject is double-booked or placed in conflicting slots.
E.g., diffac() function assigns subjects with different staff, and addsub() adds additional classes (like sports or library).
Execution Flow (main()):
Input:

The user is prompted to enter the section (A or B). Based on the input, the program reads the respective section's data from either inputa.txt or inputb.txt.
Timetable Generation:

The timetable for the selected section is generated using a combination of manual assignments (for labs) and random assignments (for other subjects).
Timetable Display:

After generating the timetable, the program displays the numeric timetable, the human-readable timetable, and the staff-based timetable (which shows faculty IDs instead of subject names).
Handling Section B (cseb part):

Section B's timetable is generated in a similar fashion to Section A, but the program ensures that labs don't overlap with Section A's labs.
Output:
Depending on whether the user selects Section A or B, the program prints three different views of the timetable:

Numeric View (numtt): Shows a 2D array of integers representing subjects.
Main Timetable (maintt): Shows the actual subject names in each time slot.
Staff Timetable (stafftt): Shows which faculty member is teaching in each slot.
Summary:
The program generates randomized timetables for two sections, ensures no subject clashes, and provides three different views of the timetable.
It reads faculty and subject information from files (inputa.txt or inputb.txt), and uses both fixed and randomized scheduling for generating a complete weekly timetable.
The three display functions allow users to see the timetable as subject names, as numeric codes, or by the faculty members teaching each slot.






