//
// Created by Archibald Chain on 2020/4/25.
//
#include "Assignment4.h"

#include <sstream>

/**
 *  question 4 function, reading data from csv, and computing average score from each lab
 */
void question4(){
    vector<int *> Lab_score;
    vector<string> SID;
    ifstream fin(file_name);
    if(!fin.is_open()){
        cout << "File not open"<< endl;
        cout << "Program terminating\n";
        exit(EXIT_FAILURE);
    } else{
        cout << "File opened" << endl;
    }
    vector<string> v;
    string temp,line;
    int count = 0, total_score = 0;
    while(fin.good()){
        v.clear();
        getline(fin, line);
        stringstream s(line);
        // split the line by delimiter
        while(getline(s, temp, ',')){
            v.push_back(temp) ;
        }
        SID.push_back(v[0]); // put the SID;
        int itemp[num_lab];// temporary storage
        for (int i = 1; i < num_lab+1; ++i) {
            itemp[i] = stoi(v[i]);
            Lab_score.push_back(itemp);
            total_score += Lab_score[count][i];
        }
        count ++;
    }

    if(fin.eof()){
        cout << "EOF reached\n";
    } else if(fin.bad()){
        cout << "File mismatched\n";
    } else {
        cout << "File reading terminating for unknown reasons\n";
    }
    fin.close();
    // average of score of the course
    double ave_course = (double)total_score/(count * num_lab);
    int sum_lab = 0;

    // computing the average score from each Lab
    for (int j = 0; j < num_lab; ++j) {
        sum_lab = 0;
        for (int i = 0; i < count; ++i) {
            sum_lab += Lab_score[i][j];
        }

        double ave_lab = (double)sum_lab/count;
        if (ave_lab < ave_course){
            cout << "The average score of Lab" << j+1
            << " is less than the average score of the course\n";
        }
    }

}

int main(){
    question4();
}
