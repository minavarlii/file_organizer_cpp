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

## Quality & Safety Considerations

This tool is designed to be safe, predictable, and repeatable.

Key considerations include:
- Defensive logic to prevent overwriting existing files
- Idempotent behavior, allowing the program to be safely re-run multiple times
- Clear separation between file detection and file movement logic
- Explicit handling of unknown or unsupported file types

These decisions reduce the risk of unintended file system changes and make the tool suitable for everyday use.

## Edge Cases Considered

The following edge cases are explicitly considered during development and testing:

- Files with duplicate names in destination directories
- Files without extensions
- Unknown or unsupported file extensions
- Empty source directories
- Re-running the tool after a previous successful run

These scenarios are handled to ensure predictable behavior and avoid data loss.

## Implementation Details
	•	Implemented in C++17
	•	Uses std::filesystem for directory traversal and file operations
	•	Includes defensive logic to avoid overwriting existing files
	•	Designed to be safely re-run multiple times
### How to Compile
`g++ -std=c++17 src/main.cpp -o organizer`

### How to Run 
`./organizer`

## Testing

The project currently relies on manual testing of deterministic behavior.

Test scenarios include:
- Running the tool on a directory with mixed file types
- Re-running the tool to verify idempotent behavior
- Verifying that existing files are not overwritten
- Confirming correct categorization of files by extension

The deterministic nature of the application makes it well-suited for future automated testing.

## Tech Stack
• C++17
• Standard Library (std::filesystem)

## Notes
	•	The program can be run multiple times without duplicating or overwriting files
	•	Files that already exist in the destination folders are preserved
	•	Intended for local use on desktop environments
