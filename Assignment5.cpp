#include <iostream>
#include <fstream>
#include <string>
//#include <sstream>
#include <cstring>
#include <cstdlib>
#include "MovieTree.h"

using namespace std;



int main(int argc, char* argv[])
{



MovieTree* MovieTreeInit;


string str;

//cout << argv[1] << endl;
std::ifstream in(argv[1]);
std::string text;

  // cout << "Build Network" << endl;
           string temp[4];
           string tempWord ="";
            int counter = 0;
            while (std::getline(in, text))
                {


                    for(int i=0;i<text.length();i++)
                    {

                        const char* strdata = text.c_str();

                        if(strdata[i]!=44)
                        {
                            tempWord += text[i];




                        }else
                        {


                           temp[counter] = tempWord;
                           tempWord ="";
                            counter++;


                        }  if(i == text.length()-1){


                            temp[3] = tempWord;
                            counter = 0;
                              tempWord ="";

                        }

                    }

                counter = 0;
                tempWord = "";


               string title = temp[1];
               int year =  atoi(temp[2].c_str() );
               int rating =  atoi(temp[0].c_str());
               int quantity = atoi(temp[3].c_str());





                MovieTreeInit->addMovieNode(rating,title,year,quantity);




                temp[0].clear();
                temp[1].clear();
                temp[2].clear();
                temp[3].clear();
                }



    int choice = 0;
    do
    {
        cout
             << "======Main Menu=====" << endl



             << "1. Find a movie" << endl
             << "2. Rent a movie" << endl
             << "3. Print the inventory" << endl
             << "4. Quit" << endl;
        cin >> choice;
      if(choice == 1){

           //  cout << "Print Network Path" << endl;
            cin.ignore();

            string mystr;
            cout << "Enter title:" << endl;
            getline (cin, mystr);

            MovieTreeInit->searchMovieTree(mystr,MovieTreeInit->topRoot);

            if(MovieTreeInit->found != 1){

                cout << "Movie not found." << endl;

             }

              MovieTreeInit->found = 0;
        }if(choice == 2){


            cin.ignore();

            string mystr;
            cout << "Enter title:" << endl;
            getline (cin, mystr);


             MovieTreeInit->rentMovie(mystr,MovieTreeInit->topRoot);

             if(MovieTreeInit->found != 1){

                cout << "Movie not found." << endl;

             }

              MovieTreeInit->found = 0;

           // cout << "Transmit Message Coast-To-Coast" << endl;

        }if(choice == 3){



            MovieTreeInit->printMovieInventory(MovieTreeInit->topRoot);



            // cout << "Add City" << endl;
        }if(choice == 4){

                cout << "Goodbye!" << endl;

                break;

        }


}while(choice != 4);



    return 0;
}
