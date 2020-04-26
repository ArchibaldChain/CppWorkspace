#include "Assignment4.h"


random_device rd;  //Will be used to obtain a seed for the random number engine
mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

int ID_generator(const int *id_array, int i);

/**
 *  The function is for the purpose of quesiont1
 * @param num
 * @param ID
 * @param Lab_score
 */
void question1(int num, int *ID, int Lab_score[][num_lab])
{
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    for (int i = 0; i < num; ++i)
    {
        ID[i] = ID_generator(ID, i);
        cout << ID[i] << ": ";
        for (int j = 0; j < num_lab; ++j)
        {
            std::uniform_int_distribution<> dis(0, 5);
            Lab_score[i][j] = dis(gen);
            // random the score of each Lab
            cout << Lab_score[i][j];
            if (num_lab - 1 != j)
                cout << ",";
        }
        cout << endl;
    }
}

/**
 * The function is for the purpose of Question2
 * it find those who need to be emailed.
 * @param num
 * @param ID
 * @param Lab_score
 */
void question2(int num, int *ID, int Lab_score[][num_lab])
{
    int count = 0;
    for (int i = 0; i < num; ++i)
    {
        for (int j = 0; j < num_lab; ++j)
        {
            if (Lab_score[i][j] == 0)
            {
                count++;
            }
            if (count == 2)
            {
                cout << "the " << ID[i]
                     << " of the students whose absent time equal or exceed 2"
                     << endl;
                break;
            }
        }
    }
}

/**
 * Question 3, write file in to a csv document
 * @param num
 * @param ID
 * @param Lab_score
 * @return
 */
int question3(int num, int *ID, int Lab_score[][num_lab])
{
    ofstream Fout;
    Fout.open(file_name);
    if (!Fout.is_open())
    {
        cout << "Not succeed to open the file\n";
        cout << "Program terminating" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num && Fout.good(); ++i)
    {
        Fout << ID[i] << ",";
        for (int j = 0; j < num_lab; ++j)
        {
            Fout << Lab_score[i][j];
            if (j != num_lab - 1)
            {
                Fout << ",";
            }
        }
        Fout << endl;
    }
    if(Fout.good()){
        cout << "File writing succeed.\n";
    }
    Fout.close();
    return 0;
}

/**
 * the function is to generate a new Student ID, and makesure it would not
 * repeat from the previous SID.
 * @param id_array
 * @param i
 * @return
 */
int ID_generator(const int *id_array, int i)
{
    int temp;
    bool flag;
    do{
        flag = false;
        std::uniform_int_distribution<> dis1(0, 20);
        std::uniform_int_distribution<> dis2(0, 9999);
        temp = (2000 + dis1(gen))  * 10000 + dis2(gen);
        for (int j = 0; j < i; ++j)
        {
            if (temp == id_array[j])
            {
                flag = true;
                break;
            }
        }
    } while (flag);
    return temp;
}

int main()
{
    int num;
    cin >> num;
    int ID[num];
    auto Lab_score = new int[num][num_lab];
    memset(ID, 0, num);
    memset(Lab_score, 0, sizeof(Lab_score[0][0]) * num * num_lab);
    question1(num, ID, Lab_score);
    question2(num, ID, Lab_score);
    question3(num, ID, Lab_score);


    delete[] Lab_score;
    return 0;
}
