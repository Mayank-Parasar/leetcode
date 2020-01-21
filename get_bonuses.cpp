//
// Created by Mayank Parasar on 2020-01-21.
//

/*
 * You are the manager of a number of employees who all sit in a row.
 * The CEO would like to give bonuses to all of your employees, but since the company did not perform so well
 * this year the CEO would like to keep the bonuses to a minimum.

The rules of giving bonuses is that:
- Each employee begins with a bonus factor of 1x.
- For each employee, if they perform better than the person sitting next to them,
 the employee is given +1 higher bonus (and up to +2 if they perform better than both people to their sides).

Given a list of employee's performance, find the bonuses each employee should get.

Example:
Input: [1, 2, 3, 2, 3, 5, 1]
Output: [1, 2, 3, 1, 2, 3, 1]

 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> get_bonuses(const vector<int>& inp) {

    vector<int> bonuses(inp.size(), 1); // everyone gets '1' as the bonus

    /*for(auto i : bonuses)
        cout << i << " ";*/

    for(int ii=0; ii < bonuses.size(); ii++) {

        if(ii == 0) { // then check only the next neighbor
            if(inp[ii] > inp[ii+1])
                bonuses[ii] += 1;
        }
        else if(ii == (bonuses.size() - 1)) {
            if(inp[ii] > inp[ii-1])
                bonuses[ii] += 1;
        }
        else {
            if(inp[ii] > inp[ii-1])
                bonuses[ii] += 1;

            if(inp[ii]> inp[ii+1])
                bonuses[ii] += 1;
        }

    }

    return(bonuses);
}

int main() {

    vector<int> inp = {1, 2, 3, 2, 3, 5, 1};

    for (auto i : inp)
        cout << i << " ";

    vector<int> bonus = get_bonuses(inp);
    cout << endl;
    for (auto i : bonus)
        cout << i << " ";

    return 0;
}