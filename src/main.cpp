#include <iostream>
#include <filesystem>
#include <map>

namespace fs = std::filesystem;

std::string getCategory(const std::string& ext) {
    if (ext == ".pdf" || ext == ".txt" || ext == ".docx") return "Documents";
    if (ext == ".jpg" || ext == ".png") return "Images";
    if (ext == ".mp3" || ext == ".wav") return "Audio";
    if (ext == ".mp4" || ext == ".mov") return "Videos";
    return "Others";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./organizer <directory_path>\n";
        return 1;
    }

    fs::path targetPath = argv[1];
    fs::path basePath = targetPath / "Organized";

    if (!fs::exists(targetPath) || !fs::is_directory(targetPath)) {
        std::cout << "Error: Provided path is not a valid directory.\n";
        return 1;
    }

    if (!fs::exists(basePath)) {
        fs::create_directory(basePath);
    }

    std::map<std::string, int> counts;

    std::cout << "Scanning directory: " << targetPath << "\n";

    for (const fs::directory_entry& entry : fs::directory_iterator(targetPath)) {
        if (!entry.is_regular_file()) continue;

        std::string extension = entry.path().extension().string();
        std::string category = getCategory(extension);

        fs::path categoryPath = basePath / category;
        if (!fs::exists(categoryPath)) {
            fs::create_directory(categoryPath);
        }

        fs::path destinationPath = categoryPath / entry.path().filename();

        if (!fs::exists(destinationPath)) {
            fs::rename(entry.path(), destinationPath);
            counts[category]++;
        }
    }

    std::cout << "\nSummary:\n";
    for (const auto& pair : counts) {
        std::cout << pair.first << ": " << pair.second << " files\n";
    }

    std::cout << "\nDone.\n";
    return 0;
}