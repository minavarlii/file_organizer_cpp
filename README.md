# File Organizer (C++)

A lightweight **C++ command-line utility** that automatically organizes files on the Desktop
into categorized folders based on file type.

The tool is designed to be **safe, repeatable, and predictable**, making it suitable for
everyday use without risk of data loss.

## Features
- Scans the Desktop directory
- Detects file types based on file extensions
- Organizes files into a single `Organized/` directory
- Automatically categorizes files into:
  - Documents
  - Images
  - Audio
  - Videos
  - Others
- Prevents overwriting existing files
- Prints a clear summary of all moved files

## Implementation Details
	•	Implemented in C++17
	•	Uses std::filesystem for directory traversal and file operations
	•	Includes defensive logic to avoid overwriting existing files
	•	Designed to be safely re-run multiple times
### How to Compile
`g++ -std=c++17 src/main.cpp -o organizer`

### How to Run 
`./organizer`

## Notes
	•	The program can be run multiple times without duplicating or overwriting files
	•	Files that already exist in the destination folders are preserved
	•	Intended for local use on desktop environments
