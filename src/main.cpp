#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

class Minigrep {
  private:
    std::string pattern_;
    bool case_sensitive_;
    bool show_line_numbers_;

    bool contains_pattern(std::string_view line, std::string_view pattern) const {
        if (case_sensitive_) {
            return line.find(pattern) != std::string_view::npos;
        }
        auto to_lower = [](char c) { return std::tolower(c); };
        std::string line_lower, pattern_lower;
        std::ranges::transform(line, std::back_inserter(line_lower), to_lower);
        std::ranges::transform(pattern, std::back_inserter(pattern_lower), to_lower);
        return line_lower.find(pattern_lower) != std::string::npos;
    }

  public:
    Minigrep(std::string pattern, bool case_sensitive = true, bool show_line_numbers = false)
        : pattern_(std::move(pattern)), case_sensitive_(case_sensitive),
          show_line_numbers_(show_line_numbers) {
    }

    void search_file(const std::filesystem::path &file_path) const {
        std::ifstream file(file_path);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open file " << file_path << '\n';
            return;
        }

        std::string line;
        size_t line_number = 0;
        while (std::getline(file, line)) {
            ++line_number;
            if (contains_pattern(line, pattern_)) {
                if (show_line_numbers_) {
                    std::cout << file_path.filename().string() << ':' << line_number << ':' << line
                              << '\n';
                } else {
                    std::cout << line << '\n';
                }
            }
        }
    }

    void search_directory(const std::filesystem::path &dir_path) const {
        try {
            for (const auto &entry : std::filesystem::recursive_directory_iterator(dir_path)) {
                if (entry.is_regular_file()) {
                    search_file(entry.path());
                }
            }
        } catch (const std::filesystem::filesystem_error &e) {
            std::cerr << "Error accessing directory: " << e.what() << '\n';
        }
    }
};

void print_usage(const char *program_name) {
    std::cerr << "Usage: " << program_name << " <pattern> <path> [-i] [-n]\n"
              << "  -i: case-insensitive search\n"
              << "  -n: show line numbers\n";
}

void main(int argc, char *argv[]) {
    if (argc < 3) {
        print_usage(argv[0]);
        return;
    }

    std::string pattern = argv[1];
    std::filesystem::path path = argv[2];
    bool case_sensitive = true;
    bool show_line_numbers = false;

    for (int i = 3; i < argc; ++i) {
        std::string_view arg = argv[i];
        if (arg == "-i") {
            case_sensitive = false;
        } else if (arg == "-n") {
            show_line_numbers = true;
        } else {
            print_usage(argv[0]);
            return;
        }
    }

    Minigrep grep(pattern, case_sensitive, show_line_numbers);

    try {
        if (std::filesystem::is_directory(path)) {
            grep.search_directory(path);
        } else {
            grep.search_file(path);
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

}
