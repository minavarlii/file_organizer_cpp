File Organizer (C++)

A simple C++ command-line tool that organizes files on the Desktop into categorized folders based on file type.

Features
	•	Scans the Desktop directory
	•	Detects file types by extension
	•	Organizes files into an Organized/ folder
	•	Categories: Documents, Images, Audio, Videos, Others
	•	Prevents overwriting existing files
	•	Prints a summary of moved files

Example Structure
Desktop
└── Organized
  ├── Documents
  ├── Images
  ├── Audio
  ├── Videos
  └── Others

How to Compile:
g++ -std=c++17 src/main.cpp -o organizer

How to Run:
./organizer

Notes
	•	The program is safe to run multiple times
	•	Existing files are never overwritten