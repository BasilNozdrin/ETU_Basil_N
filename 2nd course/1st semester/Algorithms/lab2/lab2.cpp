#include <iostream>
#include <fstream>
#include <string>

int depth(std::string str) {
    int result = 0;
    int opened = 0;
    
    for (std::string::iterator it=str.begin(); it!=str.end(); it++) {
        switch (*it) {
            case '(': {
                if (*(it+1) != ')') {
                    opened += 1;
                } else {
                    it++;
                }
                break;
            }
            case ')': {
                if (opened > result)
                    result = opened;
                opened--;
            }
            default: {
                break;
            }
        }
    }

    return result;
}


int main() {
    std::ifstream input("input.txt");
    for (std::string line; getline(input, line); ) {
        std::cout << "depth of \"" << line << "\" is " << depth(line) << "\n";
    }
    
    return 0;
}

/* 13
 * вычислить глубину (число уровней вложения) иерархического списка
 * как максимальное число одновременно открытых левых скобок
 * в сокращённой скобочной записи списка;
 *
 * принять, что глубина пустого списка
 * и глубина атомарного S-выражения равны нулю;
 *
 * например, глубина списка (a (b ( ) c) d) равна двум;
 * */
