//
// Created by Mayank Parasar on 2020-02-26.
//
/*
 * MS Excel column titles have the following pattern: A, B, C, ..., Z, AA, AB, ..., AZ, BA, BB, ..., ZZ, AAA, AAB, ...
 * etc. In other words, column 1 is named "A", column 2 is "B", column 26 is "Z", column 27 is "AA" and so forth.
 * Given a positive integer, find its corresponding column name.
Examples:
Input: 26
Output: Z

Input: 51
Output: AY

Input: 52
Output: AZ

Input: 676
Output: YZ

Input: 702
Output: ZZ

Input: 704
Output: AAB
 */
#include <iostream>
#include <deque>

using namespace std;

// Big Switch case
char intToChar(int num) {
    switch (num) {
        case 0: return 'A'; break;
        case 1: return 'B'; break;
        case 2: return 'C'; break;
        case 3: return 'D'; break;
        case 4: return 'E'; break;
        case 5: return 'F'; break;
        case 6: return 'G'; break;
        case 7: return 'H'; break;
        case 8: return 'I'; break;
        case 9: return 'J'; break;
        case 10: return 'K'; break;
        case 11: return 'L'; break;
        case 12: return 'M'; break;
        case 13: return 'N'; break;
        case 14: return 'O'; break;
        case 15: return 'P'; break;
        case 16: return 'Q'; break;
        case 17: return 'R'; break;
        case 18: return 'S'; break;
        case 19: return 'T'; break;
        case 20: return 'U'; break;
        case 21: return 'V'; break;
        case 22: return 'W'; break;
        case 23: return 'X'; break;
        case 24: return 'Y'; break;
        case 25: return 'Z'; break;
        default: assert(0); return -1;
    }
}

deque<char> convert_to_title(int num) {
    deque<char> title;
    while(num > 0) {
        num = num - 1;
        title.push_front(intToChar(num % 26));
        num = num / 26;
    }

    return title;
}

int main() {

//    int num = 52;
//    int num = 27;
//    int num = 676;
    int num = 704;

    deque<char>title = convert_to_title(num);

    for(auto i : title)
        cout << i;

    cout << endl;

    return 0;
}