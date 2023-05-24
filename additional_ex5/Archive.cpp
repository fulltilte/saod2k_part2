#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

const int MAX_DICT_SIZE = 128;

std::string compressLZ78(const std::string& input) {
    std::unordered_map<std::string, int> dictionary;
    std::string compressed;

    std::string currentMatch;
    int nextCode = 1;

    for (char c : input) {
        currentMatch += c;

        // Проверяем, содержится ли текущая последовательность в словаре
        if (dictionary.count(currentMatch) == 0) {
            // Если последовательность отсутствует, добавляем ее в словарь
            dictionary[currentMatch] = nextCode++;
            // Записываем код предыдущей последовательности в сжатый вывод
            compressed += std::to_string(dictionary[currentMatch.substr(0, currentMatch.length() - 1)]);

            // Если словарь достиг максимального размера, очищаем его
            if (nextCode >= MAX_DICT_SIZE) {
                dictionary.clear();
                nextCode = 1;
            }

            currentMatch = "";
        }
    }

    // Записываем код последней последовательности в сжатый вывод
    if (!currentMatch.empty()) {
        compressed += std::to_string(dictionary[currentMatch]);
    }

    return compressed;
}

std::string decompressLZ78(const std::string& compressed) {
    std::unordered_map<int, std::string> dictionary;
    std::string decompressed;

    std::string currentMatch;
    int nextCode = 1;

    for (char c : compressed) {
        currentMatch += c;

        // Проверяем, является ли текущий символ числом
        if (isdigit(c)) {
            int code = std::stoi(currentMatch);
            if (code == 0) {
                // Новая последовательность, добавляем символ в результат
                decompressed += currentMatch.back();
                dictionary[nextCode++] = std::string(1, currentMatch.back());
            }
            else {
                // Декодируем последовательность из словаря и добавляем в результат
                std::string sequence = dictionary[code] + currentMatch.back();
                decompressed += sequence;
                dictionary[nextCode++] = sequence;
            }

            // Очищаем текущую последовательность
            currentMatch = "";
        }
    }

    return decompressed;
}

int main() {
    std::locale::global(std::locale("Russian"));

    std::ifstream inputFile("text.txt"); // Открываем файл для чтения входных данных
    std::ofstream compressedFile("compressed.txt"); // Открываем файл для записи сжатого вывода
    std::ofstream decompressedFile("decompressed.txt"); // Открываем файл для записи декомпрессированного вывода

    if (!inputFile || !compressedFile || !decompressedFile) {
        std::cout << "Ошибка открытия файлов." << std::endl;
        return 1;
    }

    std::string input;
    std::getline(inputFile, input); // Читаем строку из файла

    std::string compressed = compressLZ78(input);
    compressedFile << compressed; // Записываем сжатый вывод в файл

    std::string decompressed = decompressLZ78(compressed);
    decompressedFile << decompressed; // Записываем декомпрессированный вывод в файл

    std::cout << "Сжатый вывод записан в файл 'compressed.txt'." << std::endl;
    std::cout << "Декомпрессированный вывод записан в файл 'decompressed.txt'." << std::endl;

    inputFile.close(); // Закрываем файлы
    compressedFile.close();
    decompressedFile.close();

    return 0;
}
