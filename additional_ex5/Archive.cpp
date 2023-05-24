#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void compress(const string& input_file, const string& output_file) {
    ifstream in(input_file, ios::binary);
    ofstream out(output_file, ios::binary);

    map<string, int> dictionary;
    vector<int> encoded_data;

    int code = 0;
    string w;
    char c;

    while (in.get(c)) {
        string wc = w + c;
        if (dictionary.count(wc)) {
            w = wc;
        }
        else {
            encoded_data.push_back(dictionary[w]);
            dictionary[wc] = code++;
            w = string(1, c);
        }
    }

    if (!w.empty()) {
        encoded_data.push_back(dictionary[w]);
    }

    for (int code : encoded_data) {
        out.write(reinterpret_cast<const char*>(&code), sizeof(code));
    }
}

void decompress(const string& input_file, const string& output_file) {
    ifstream in(input_file, ios::binary);
    ofstream out(output_file, ios::binary);

    map<int, string> dictionary;
    vector<int> encoded_data;

    int code;
    while (in.read(reinterpret_cast<char*>(&code), sizeof(code))) {
        encoded_data.push_back(code);
    }

    int dict_size = 128;
    for (int i = 0; i < dict_size; i++) {
        dictionary[i] = string(1, i);
    }

    string w = dictionary[encoded_data[0]];
    out << w;

    for (int i = 1; i < encoded_data.size(); i++) {
        int code = encoded_data[i];
        string entry;
        if (dictionary.count(code)) {
            entry = dictionary[code];
        }
        else if (code == dict_size) {
            entry = w + w[0];
        }
        else {
            throw "Bad compressed code";
        }
        out << entry;
        dictionary[dict_size++] = w + entry[0];
        w = entry;
    }
}

int main() {
    string input_file = "text.txt";
    string archive_file = "archive.bin";
    string output_file = "output.txt";

    compress(input_file, archive_file);
    decompress(archive_file, output_file);

    return 0;
}
