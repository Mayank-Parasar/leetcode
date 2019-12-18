//
// Created by Mayank Parasar on 2019-12-18.
//

/*
 * You are given a hash table where the key is a course code, and the value is a list of all the course codes
 * that are prerequisites for the key. Return a valid ordering in which we can complete the courses.
 * If no such ordering exists, return NULL.

Example:
{
  'CSC300': ['CSC100', 'CSC200'],
  'CSC200': ['CSC100'],
  'CSC100': []
}

This input should return the order that we need to take these courses:
 ['CSC100', 'CSC200', 'CSCS300']
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// elementals are the courses that do not have any pre-requisite.

void course_order(map<string, vector<string>>& database,
                vector<string>& course_order) {
    // populate the vector with elementals
    for(auto entry: database) {
        if(entry.second.size() == 0) {
            course_order.push_back(entry.first);
        }
    }
    // if there are no elementals present then it will not possible

    map<string, vector<string>>::iterator itr;
    repeat:
    for(itr=database.begin(); itr != database.end(); itr++) {
        if(find(course_order.begin(), course_order.end(), itr->first) == course_order.end()) {
            // the course is not present in the course order.. check if its pre-requisite are met
            // if yes, add it to the course order and goto repeat
            vector<string> requirements = itr->second;
            int ii = 0;
            for(ii=0; ii < requirements.size(); ii++) {
                int kk =0;
                for(kk = 0; kk < course_order.size(); kk++) {
                    if (course_order[kk] == requirements[ii]) {
                        break;
                    }
                    else {

                    }
                }
                if(kk < course_order.size()) {
                    // this course prerequisite is present
                    continue;
                }
                else if( kk == course_order.size()) {
                    // this course is not present therefore pre-requisite have not meet
                    break;
                } else {
                    assert(0);
                }
                // if(ii == -1)
                    // break; // this makes
            }
            if(ii == requirements.size()) {
                // all the pre-requiste for this course has meet
                // add this course to the course order
                // only if not already present and repeat
                course_order.push_back(itr->first);
                goto repeat;
            }

        }
        else {
            continue; // found the course in the course_order
        }
    }
    return;
}

int main() {

    vector<string> course_order_;
    map<string, vector<string>> database;

    // initialize the database
    database["CSC300"] = {"CSC100", "CSC200"};
    database["CSC200"] = {"CSC100"};
    database["CSC100"] = {};

    course_order(database, course_order_);

    for(auto ii : course_order_ ) {
        cout << ii << " ";
    }

    return 0;
}