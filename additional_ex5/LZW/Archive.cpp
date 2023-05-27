#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>

void compress(std::ifstream& input_file, std::ofstream& output_file) {
    std::unordered_map<std::string, int> dictionary;
    for (int i = 0; i < 256; ++i) {
        dictionary[std::string(1, i)] = i;
    }

    std::string current;
    std::vector<int> output;
    char c;
    while (input_file.get(c)) {
        std::string next = current + c;
        if (dictionary.count(next)) {
            current = next;
        }
        else {
            output.push_back(dictionary[current]);
            dictionary[next] = dictionary.size();
            current = std::string(1, c);
        }
    }
    if (!current.empty()) {
        output.push_back(dictionary[current]);
    }

    for (int i : output) {
        output_file << i << " ";
    }
    output_file << std::endl;
}

void decompress(std::ifstream& input_file, std::ofstream& output_file) {
    std::unordered_map<int, std::string> dictionary;
    for (int i = 0; i < 256; ++i) {
        dictionary[i] = std::string(1, i);
    }

    int code;
    input_file >> code;
    std::string current = dictionary[code];
    output_file << current;
    while (input_file >> code) {
        std::string next;
        if (dictionary.count(code)) {
            next = dictionary[code];
        }
        else if (code == dictionary.size()) {
            next = current + current[0];
        }
        else {
            throw std::invalid_argument("Invalid input");
        }
        output_file << next;
        dictionary[dictionary.size()] = current + next[0];
        current = next;
    }
    output_file << std::endl;
}

int main() {
    std::ifstream input_file("engwiki_ascii.txt");
    std::ofstream compressed_file("compressed.txt");
    compress(input_file, compressed_file);
    input_file.close();
    compressed_file.close();

    std::ifstream compressed_input_file("compressed.txt");
    std::ofstream output_file("output.txt");
    decompress(compressed_input_file, output_file);
    compressed_input_file.close();
    output_file.close();

    return 0;
}
