#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <regex>

void is_valid_hyperlink(const std::string& str) {
    static const std::regex r(R"(([\w+]+\:\/\/)?([\w\d-]+\.)*[\w-]+[\.\:]\w+([\/\?\=\&\#\.]?[\w-]+)*\/?)");
    std::smatch match;
    if (regex_search(str, match, r))
        std::cout << match[0] << std::endl;
}


int main()
{
    setlocale(LC_ALL, "ru");

    std::ifstream fin;
    //std::string file;
    //std::cin >> file;
    fin.open("test.html");
    if (!fin)
        std::cout << "Ошибка открытия файла\n\n";
    else
        std::cout << "Файл открыт\n\n";

    std::string str;
    while (std::getline(fin, str)) {
        is_valid_hyperlink(str);
    }

    return 0;

}