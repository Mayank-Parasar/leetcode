//
// Created by Mayank Parasar on 2020-04-06.
//

/*
 * INPUT:
"God likes good dog"

God - 'g' 'o' 'd'
good - 'g' 'o' 'd'
dog - 'g' 'o' 'd'

case, frequency, order - does not matter
SIMILAR words

OUTPUT:
{God, good, dog}
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

string mysort(string str) {

    bool swap_ = true;
    while(swap_) {
        swap_ = false;
        for (int ii = 0; ii < str.length() - 1; ii++) {
            if (str[ii] > str[ii + 1]) {
                swap(str[ii], str[ii+1]);
                swap_ = true;
            }
        }
    }
    return str;
}



string remove_duplicate(string str) {
    string result;

    for(int ii = 0; ii < str.length()-1; ii++) {
        if(str[ii] == str[ii+1]) {
            continue;
        }
        else{
            result +=str[ii];
        }
    }

    result += str[str.length() - 1];

    return result;
}

vector<string> mysort(vector<string> string_vec) {
    vector<string> result;
    for(auto i : string_vec) {
        result.push_back(mysort(i));
    }

    return result;
}

vector<string> vecotize_string(string str) {
    vector<string> result;
    string tmp;
    for(int ii = 0; ii < str.length(); ii++) {
        tmp += str[ii];
        if(str[ii+1] == ' ' || str[ii+1] == '\0') {
            result.push_back(tmp);
            tmp = "";
            ii++;
        }
    }
    return result;
}

int main() {

    string str_orig = "God likes good dog and dog";
//    string str_orig = "Name of the game is Name";

    string str(str_orig);
    // remove case-sensitivity
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    // vectrozie the string
    vector<string> vec_string = vecotize_string(str);
    vector<string> vec_string_orig = vecotize_string(str_orig);

    // sort all the charactar within the words in a vector
    vector<string> vec_string_sorted = mysort(vec_string);

    // now remove the duplicates from each string
    vector<string> vec_string_sorted_unique;
    for(auto i : vec_string_sorted) {
        vec_string_sorted_unique.push_back(remove_duplicate(i));
    }

    // now have a map of string and vector<int>
    // this will record the indecies of similar words
    map<string, vector<int>> mymap;
    for(int ii=0; ii < vec_string_sorted_unique.size(); ii++) {
        mymap[vec_string_sorted_unique[ii]].push_back(ii);

    }

    cout << "similar words are: " << endl;

    // print out this map:
    for(auto i : mymap) {
        cout << "{ ";
        for(auto k : i.second) {
            cout << vec_string_orig[k] << " ";
        }
        cout << " }";
        cout << endl;
    }
    return 0;
}