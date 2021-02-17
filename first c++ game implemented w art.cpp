#include <iostream>
#include<dos.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
    int  qnum = 0;       //declare the question´s number
    int  scr = 0;        //declare score
    int  counter;        //declare counter
    int  mode;           //declare mode
    bool isinf;          //declares is infinite mode

    cout <<"  GGGGG     TTTTTTTTT   NNN    NN            "<< endl;
    cout <<"GG     GG       T       NNNN   NN            "<< endl;
    cout <<"GG              T       NN NN  NN            "<< endl;
    cout <<"GG   GGGG       T       NN  NN NN            "<< endl;
    cout <<"GG     GG       T       NN   NNNN            "<< endl;
    cout <<"  GG GG   @     T    @  NN    NNN  @         "<< "\n"<< endl;
    cout <<"      Guess The Number GAME \n               "<< endl;

    cout << "select mode : (1 : infinite) (any number : number of plays) :";
    cin >> mode;
    cout << "\n" << endl;

    if(mode == 1){                  //if mode is 1
        counter = 100000;           //it will happen a pseudo-infinite amount of times
        isinf   = true;             //it is infinite
    }else{                          //if mode is different from 1
        counter = mode;             //it will happen mode amount of times
        isinf   = false;            //it is false
    }

    int n;                          //define n (dificulty)
    int dif;                        //declare dif (input)

    cout << "selct dificulty : (1 = 10) (2 = 100) (3 = 1000) or custom(max number):";
    cin  >> dif;
    cout << "\n" << endl;

    if(dif == 1){
        n = 10;
    }else if(dif == 2){
        n = 100;
    }else if(dif == 3){
        n = 1000;
    }else{
        n = dif;
    }

    int i;                                   //declare i

    for(int i = 1; i <= counter; i++){
        srand (time(NULL));                 //pseudo randomizes the rand function
        int num1 = rand() % n + 1;
        int num2 = rand() % n + 1;
        int sum  = num1 + num2;
        int answr;                          //declares the answer int
        int marg;

        qnum = qnum + 1;                    //question number + 1

        if(qnum < 10){
            cout << "0" << qnum << ".How much is " << num1 << "+" << num2 << "? :";     //this part mounts the question line
            cin  >> answr;
        } else if(qnum >= 10){
            cout << qnum << ".How much is " << num1 << "+" << num2 << "? :";            //this part mounts the question line
            cin  >> answr;                                                              //this is the answer input
        }

        if(answr == sum){                                       //if answer was right
            scr = scr + 100;                                    //add 100 score
            cout << "your answer was correct!" << endl;
            cout << "your score is " << scr << "\n"<< endl;

        }else if(answr >= sum){                                 //if answer was wrong

            if (scr <= 0){scr = 0;                              //if score equals 0,  so be it, else minus 50
            }else{scr = scr - 50;}                              //

            marg = answr - sum;                                 //margin is wrong answer minus the right answer
            cout << "you were " << marg << " numbers away" << endl;

            if(isinf == true){                                  //if its infinite and wrong, then end
                cout << "YOUR FINAL SCORE IS " << scr << endl;  //print the final score
                return 0;
            }
            cout << "your score is " << scr << "\n"<< endl;     //prints the score

        } else if(answr <= sum){

            if (scr <= 0){scr = 0;                              //if score equals 0,  so be it, else minus 50
            }else{scr = scr - 50;}                              //

            marg = sum - answr;                                 //margin is wrong answer minus the right answer or right answer minus right answer on thi case
            cout << "you were " << marg <<" numbers away" << endl;

            if(isinf == true ){                                 //if its infinite and wrong, then end

                cout << "YOUR FINAL SCORE IS " << scr << endl;
                return 0;
                }
            cout << "your score is " << scr << "\n" << endl;
        }
    }
    cout << "YOUR FINAL SCORE IS " << scr << endl;
    return 0;
}
