//
// Created by Mayank Parasar on 2019-12-09.
//

/*
Given a string with the initial condition of dominoes, where:

. represents that the domino is standing still
L represents that the domino is falling to the left side
R represents that the domino is falling to the right side

Figure out the final position of the dominoes. If there are dominoes that get pushed on both ends, the force cancels out and that domino remains upright.

Example:
Input:  ..R...L..R.
Output: ..RR.LL..RR
 * */

// string::operator[]
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//string initial = "..R...L..R.";
string initial = "..RR.LL..R.";

void update_wavefront(vector<int>& waveR, vector<int>& waveL) {
    // Reset both wavefronts
    waveR.clear();
    waveL.clear();
    // initialize the wavefronts:
    for(int ii=0; ii < initial.length(); ii++) { // start from idx-1
        // if 'R' is on the right edge then no point
        // of adding it to the wavefront
        // if 'L' is on the left edge then no point of
        // adding it to the wavefront
        if (ii+1 < initial.length()) {  // boundary check
            if (initial[ii] == 'R' &&
                initial[ii + 1] == '.') {
                // put 'ii' in the wavefrontR
                waveR.push_back(ii);
            }
        }
        if (ii > 0) {  // boundary check
            if (initial[ii] == 'L' &&
                initial[ii - 1] == '.') {
                // put 'ii' in the wavefrontL
                waveL.push_back(ii);
            }
        }
    }
    vector<int> delete_waveR_entries; // these contain the index
    vector<int> delete_waveL_entries; // these contain the index
    // delete the dublious entries from wavefronts
    for(int idxR=0; idxR < waveR.size(); ++idxR) {
        for(int idxL=0; idxL < waveL.size(); ++idxL) {
            if((waveR[idxR] + 1) == (waveL[idxL] - 1)) {
                // then log this entry to be deleted
                delete_waveR_entries.push_back(idxR);
                delete_waveL_entries.push_back(idxL);
            }
        }
    }
    // now delete the respective entries from respective wavefronts
    for(auto i : delete_waveR_entries) {
        waveR.erase(waveR.begin() + i);
    }
    for(auto i : delete_waveL_entries) {
        waveL.erase(waveL.begin() + i);
    }
}


int main() {
    bool makeR = false; // flags
    bool makeL = false; // flags
    // string initial = "..R...L..R.";
    // initial = "R....L....L";
    // string final = initial;
    cout << "initial state of the dominos is: " << initial << endl;
    cout << "length of string is: " << initial.length() << endl;

    vector<int> wavefrontR;
    vector<int> wavefrontL;
    int timestep = 0;
    // initialize the wavefronts:
/*    for(int ii=0; ii < initial.length(); ii++) {
        // perform actions based on flags:
        if(makeR == true) {
            initial[ii] = 'R';
        }
        // set flags:
        if (initial[ii] == 'L') {
            makeL = true;
        }
        else if (initial[ii] == 'R') {
            makeR = true;
        }

        cout << final[ii] << endl;
    }*/

    // initialize the wavefronts:
    for(int ii=0; ii < initial.length(); ii++) { // start from idx-1
        // if 'R' is on the right edge then no point
        // of adding it to the wavefront
        // if 'L' is on the left edge then no point of
        // adding it to the wavefront
        if (ii+1 < initial.length()) {  // boundary check
            if (initial[ii] == 'R' &&
                initial[ii + 1] == '.') {
                // put 'ii' in the wavefrontR
                wavefrontR.push_back(ii);
            }
        }
        if (ii > 0) {  // boundary check
            if (initial[ii] == 'L' &&
                initial[ii - 1] == '.') {
                // put 'ii' in the wavefrontL
                wavefrontL.push_back(ii);
            }
        }
    }
    vector<int> delete_waveR_entries; // these contain the index
    vector<int> delete_waveL_entries; // these contain the index
    // delete the dublious entries from wavefronts
    for(int idxR=0; idxR < wavefrontR.size(); ++idxR) {
        for(int idxL=0; idxL < wavefrontL.size(); ++idxL) {
            if((wavefrontR[idxR] + 1) == (wavefrontL[idxL] - 1)) {
                // then log this entry to be deleted
                delete_waveR_entries.push_back(idxR);
                delete_waveL_entries.push_back(idxL);
            }
        }
    }
    // now delete the respective entries from respective wavefronts
    for(auto i : delete_waveR_entries) {
        wavefrontR.erase(wavefrontR.begin() + i);
    }
    for(auto i : delete_waveL_entries) {
        wavefrontL.erase(wavefrontL.begin() + i);
    }

    cout << "wavefront-R: " << endl;
    for (auto i : wavefrontR)
        std::cout << i << ' ';
    cout << endl << "wavefront-L: " << endl;
    for (auto i : wavefrontL)
        std::cout << i << ' ';

    // each iteration mimics the timestep
    // time loop
    while(wavefrontL.size() > 0 ||
        wavefrontR.size() > 0) {
        // propagate the wave-R
        for (auto i : wavefrontR) {
            if(initial[i+1] == '.')
                initial[i+1] = 'R';
        }
        // propagate the wave-L
        for (auto i : wavefrontL) {
            if(initial[i-1] == '.')
                initial[i-1] = 'L';
        }
        // update wavefronts
        update_wavefront(wavefrontR, wavefrontL);
        cout << endl << "new string: " << initial << endl;
        cout << "wavefront-R: " << endl;
        for (auto i : wavefrontR)
            std::cout << i << ' ';
        cout << endl << "wavefront-L: " << endl;
        for (auto i : wavefrontL)
            std::cout << i << ' ';
    }
    cout << endl << "new string: " << initial << endl;
    return 0;
}