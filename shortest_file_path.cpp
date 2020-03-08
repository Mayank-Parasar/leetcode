/*

Given a file path with folder names, '..' (Parent directory), and '.' (Current directory),
return the shortest possible file path (Eliminate all the '..' and '.').

Example
Input: '/Users/Mayank/Documents/../Desktop/./../'
Output: '/Users/Mayank/'
def shortest_path(file_path):
  # Fill this in.

print shortest_path('/Users/Mayank/Documents/../Desktop/./../')
# /Users/Mayank/
*/

#include<iostream>
#include<vector>
#include<string>


using namespace std;

vector<string> vectorify(string file_path, char delim) {

    vector<char> word;
    vector<string> path;

    for(auto i : file_path) {
        if(i == '/') {
            path.push_back(std::string(word.begin(), word.end()));
            word.clear();
        }
        else {
            word.push_back(i);
        }
    }
    return path;
}


vector<string> process_vector(vector<string> file_path) {
    // remove all the '.' from the vector
    for(auto it = file_path.begin(); it != file_path.end(); it++) {
        if(*it == ".") {
            file_path.erase(it);
        }
    }

//    for(auto i : file_path)
//        cout << i << " ";

    // now if there is any '..' delete this as well as the previous entry in that vector
    redo:
    for(auto it = file_path.begin(); it != file_path.end(); ++it) {
        if(*it == "..") {
            file_path.erase(it);
            --it;
            file_path.erase(it);
            goto redo;
        }
    }

//    cout  << endl;
//
//    for(auto i : file_path)
//        cout << i << " ";
    ////////////// now insert delim here again'
    vector<string> new_path;
    for(auto i : file_path) {
        new_path.push_back(i+"/");
    }

    return (new_path);
}


int main() {
    string file_path = "/Users/Mayank/Documents/../Desktop/./../";
    vector<string>path = vectorify(file_path, '/');

//    for(auto i : path)
//        cout << i << " ";
//
//    cout << endl;

    // process on this vector
    std::vector<string> vec = process_vector(path);
    std::string new_file_path;

    for(auto i : vec) {
        new_file_path += i;
    }

    cout << new_file_path << endl;


    return 0;
}