#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
#include<windows.h>

using namespace std;

int randomGen();
int randomGen1() ;
void questionGenerator();
void questionRand() ;
void report(int, int);
void assignAr();
int check();
void progressSave();
int table[21][11];
void reset();
void playsounds(int, int) ;

//main function
int main()
{
    int choice ;
    char res ;
    cout <<setfill('-')<<setw(80)<<"-"<<endl
         << "WELL, HELLO THERE!\nI AM A PROGRAM"<<endl
         << "I AM AN EXAMPLE OF MACHINE LEARNING! I WILL LEARN FROM YOU AND HOPEFULLY HELP YOU, THE USER LEARN MULTIPLICATION TABLES."
         <<"Do you want\n1:Practice Question(Will give you questions based on your past progress)\n2:Random Questions(Will give you random questions)\n";
         // Option 1 will generate only the questions the user has not been able to answer.
         // Option 2 will generate random questions regardless of he past progress.
         // NOTE: Using option 2 will save how many questions you've done wrong.

    assignAr(); //assign function used to import the file values to the array to be used
    srand((time(0)));
    cin>>choice ;
    if(choice == 1){
        questionGenerator(); //For option 1 practice question generator
    }
    else if (choice == 2){
        questionRand() ; //For option 2 random question generator
    }
    progressSave(); //Exports the array data to the save file
    cout<<"Do you want to reset your progress?\n" ;
    cin>>res ;
    if(res == 'y' || res == 'Y'){
        reset() ; //Resets all your progress
    }
    return 0 ;
}

//progressSaver

void progressSave()
{
    ofstream prog; //Output stream to file
    prog.open("wrongquestions.txt"); //Open desired file
    if(prog.is_open()){
        cout<<"File Opened Successfully!\n" ;
    }
    for(int a = 0; a < 21; a++){ //Saves progress ie. copies the array data to savefile so that it can be used later
        for(int b = 0; b < 11; b++){
            prog<<table[a][b]<<" " ;
        }
        prog<<endl;
    }
    prog.close(); //Close file
}

//question function

void questionGenerator()
{
    int q1, q2, ans, asdf, nq;
    int t1 , t2, tot1, tot2;
    cout<<"How many questions do you want?\n";
    cin>>nq;
    tot1 = time(0) ;
    for(int i = 0; i < nq; i++){
        q1 = randomGen();
        q2 = randomGen1();
        asdf = check(); //Checks whether the user has done all the questions correctly or not
        if(asdf == 0){
           cout<<"You seem to have done all the questions. Good going!\n";
           break;
        }
        for(; table[q1][q2] != 1; ){ //If a question set is found such that the user has already asnwered it before, then this loop will generate questions until the next unsolved set is found
            q1 = randomGen();
            q2 = randomGen1();
        }
        cout<<q1<<" x "<<q2<<" "<<endl;
        t1 = time(0) ;
        cin>>ans;
        t2 = time(0);
        if(q1 * q2 == ans && t2 - t1 < 3){   //Calculates how long it took for the user to answer the question.
            table[q1][q2] = 0;
            cout<<"Time taken: "<<t2 - t1<<endl;
            playsounds(200, 500) ;
        }
        else if (q1 * q2 != ans || t2 - t1 > 3){ //If it is more than 3 seconds, the question will be marked as unsolved
           table[q1][q2] = 1;
           playsounds(500, 500) ;
        }
    }
    tot2 = time(0) ;
    cout<<"\n\n\nThe total time for exercice is: "<<tot2 - tot1<<endl ; //Displays total time taken to answer the worksheet
}

//randomequestion

void questionRand()
{
    int nq, tot1, tot2;
    int q1, q2, t1, t2, ans ;
    cout<<"How many questions do you want?\n" ;
    cin>>nq;
    tot1 = time(0) ;
    for(int i = 0; i < nq; i++){
        q1 = randomGen() ;
        q2 = randomGen1() ;
        cout<<q1<<" x "<<q2<<endl ;
        t1 = time(0);
        cin>>ans ;
        t2 = time(0);
        if(q1 * q2 == ans && t2 - t1 < 5){
            table[q1][q2] = 0 ;
            cout<<"Time taken: "<< t2 - t1<< endl;
        }
        else if(q1 * q2 != ans || t2 - t1 > 5){
            table[q1][q2] = 1;
        }
    }
    tot2 = time(0) ;
    cout<<"\n\n\nThe total time for the exercise is: "<<tot2 - tot1<<endl ;
}
//report m8

void assignAr()
{
    ifstream chewie ; //Input stream for file ie. the file will input into the variables
    chewie.open("wrongquestions.txt"); //Open the savefile
       for(int i = 0; i < 21; i++){   //Save
        for(int j = 0; j < 11; j++){
            chewie >> table[i][j];
        }
    }
    chewie.close();
}

//check questions
int check()
{
    int r = 0;
    for(int a = 0; a < 21 ; a++){
        for(int b = 0; b < 11; b++){
            r = r + table[a][b];
        }
    }
    return r ;
}

//random generator
int randomGen()
{
    int x;
    x = rand() % 20 + 1;
    return x;
}

int randomGen1()
{
    int y;
    y = rand() % 10 + 1;
    return y ;
}

//reset function
void  reset()
{
    ofstream awgeez;
    awgeez.open("wrongquestions.txt");
    if(awgeez.is_open()){
        cout<<"File Opened Successfully\n" ;
    }
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 11; j++){
            awgeez<<1<<" ";
        }
        awgeez<<endl ;
    }
    awgeez.close() ;
}
 void playsounds(int x, int y)
{
    Beep(x, y) ;
}




