#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <algorithm>

void readFromFile(std::list<int>& myList, const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::ofstream outputFile(filename);
        outputFile.close();
        return;
    }
    
    // Читаем с линии через запятую
    // std::string line;
    // while (std::getline(inputFile, line, ',')) {
    //     int element = std::stoi(line);
    //     myList.push_back(element);
    // }

    // читаем в столбик через любой символ
    int element;
    while (inputFile >> element) {
        myList.push_back(element);
        // Ignoruj przecinki
        inputFile.ignore();
    }
    // Zamykamy plik
    inputFile.close();
}


// Записывание в строку со знаком на конце
// std::string listToString(const std::list<int>& myList) {
//     std::stringstream ss;
//     for (auto it = myList.begin(); it != myList.end(); ++it) {
//         ss << *it;
//         if (std::next(it) != myList.end()) {
//             ss << ",";
//         }
//     }
//     return ss.str();
// }

void writeToFile(const std::list<int>& myList, const std::string& filename) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open())
    {
        std::ofstream outputFile(filename);
        outputFile.close();
        return;
    }
    

    // Записывание в строку без знака на конце
    // for (const auto& element : myList) {
    //     outputFile << element << std::endl;
    // }

    // Записывание в столбик со знаком на конце
    //     for (auto it = myList.begin(); it != myList.end(); ++it) {
    //     outputFile << *it;
    //     // Dodaj przecinek na końcu każdej linii, chyba że to ostatni element
    //     if (std::next(it) != myList.end()) {
    //         outputFile << ",";
    //     }
    //     outputFile << std::endl;
    // }

    // Записывание в строку со знаком на конце
    // outputFile << listToString(myList);

    // Записываем x:y
    auto it = myList.begin();
    while (it != myList.end()) {
        if (std::next(it) != myList.end()) {
            // Jeśli to nie jest ostatni element, zapisz parę
            outputFile << *it << ":" << *std::next(it) << std::endl;
            std::advance(it, 2);  // Przesuń iterator o 2, aby przejść do następnej pary
        } else {
            // Jeśli to ostatni element, zapisz go pojedynczo
            outputFile << *it << std::endl;
            ++it;
        }
    }

    outputFile.close();
}


void sortList(std::list<int>& myList) {
    myList.sort();
}

void removeElement(std::list<int>& myList, int element) {
    myList.remove(element);
}

void addToSortedList(std::list<int>& myList, int element) {
    auto it = std::lower_bound(myList.begin(), myList.end(), element);
    myList.insert(it, element);
}

int main() {
    std::list<int> myList;

    readFromFile(myList, "input.txt");

    sortList(myList);

    removeElement(myList, 5);

    addToSortedList(myList, 10);
    addToSortedList(myList, 3);

    for (const auto& element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    writeToFile(myList, "output.txt");

    return 0;
}
