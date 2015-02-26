#include <iostream>
#include <string.h>
#include "MovieTree.h"

int counter = 1;

MovieTree::MovieTree()
{
	root = NULL;
}

MovieTree::~MovieTree()
{

}


void MovieTree::addMovieNode(int rating,string title,int year,int quantity){

    MovieNode *temp = new MovieNode;
    temp->quantity = quantity;
    temp->ranking = rating;
    temp->title = title;
    temp->year = year;

    if(root == NULL)
    {
        root = temp;
        topRoot = temp;
        root->parent = NULL;
        root->rightChild = NULL;
        root->leftChild = NULL;
    } else {


     MovieNode *y = NULL;
     MovieNode *x = root;
     MovieNode *z = temp;


    counter ++;
   //assume we don't have an empty tree, which means that root isn't NULL

    const char * charTitle = title.c_str();

    while(x != NULL){
        y = x;
        string titleX = x->title;

        const char * charTitleX = titleX.c_str();

        if(strcmp(charTitleX,charTitle) > 0){
         // cout << title << endl;
         // cout << titleX << endl;
            x = x->leftChild;
        }if(strcmp(charTitleX,charTitle) < 0){
          //  cout << "Two" << endl;
            x = x->rightChild;
        }
    }

    z->parent = y;
    string titleY = y->title;
    const char * charTitleY = titleY.c_str();
    if(strcmp(charTitleY,charTitle) > 0){
   // cout << "3" << endl;
        y->leftChild = z;
        z->leftChild = NULL;
        z->rightChild = NULL;
    }else{
  //  cout << "4" << endl;
        y->rightChild = z;
        z->leftChild = NULL;
        z->rightChild = NULL;
    }

}

}

void  MovieTree::printMovieInventory(MovieNode *root){

   if(root->leftChild != NULL) {

      printMovieInventory(root->leftChild);

    }




    cout << "Movie: " << root->title <<  endl; // traverses through left tree to node. then through right tree

    if(root->rightChild != NULL) {

      printMovieInventory(root->rightChild);

    }



}

MovieNode* MovieTree::searchMovieTree(string title,MovieNode *root){



        if ( root!=NULL ) {  // (Otherwise, there's nothing to print.)

                if(root->title == title){

                    cout <<	"Movie Info:"	<<	endl;
                    cout <<	"==========="	<<	endl;
                    cout << "Ranking:" << root->ranking <<endl;
                    cout << "Title:" << root->title <<endl;
                    cout << "Year:" << root->year <<endl;
                    cout << "Quantity:" << root->quantity <<endl;
                    found = 1;



                    return root;


                } if(found!=1){

           searchMovieTree( title,root->leftChild );    // Print items in left subtree.
           searchMovieTree( title,root->rightChild );   // Print items in right subtree.
           }
        }




return root;

 }

void  MovieTree::rentMovie(string title,MovieNode *root){

    MovieNode *x = root;
    if (x!=NULL ) {  // (Otherwise, there's nothing to print.)



                if(x->title == title){

                      if(root->quantity == 0)
                    {

                        cout<<	"Movie out of stock."	<<	endl;


                    } else {

                    if(x->quantity > 0){
                    int quantity = x->quantity;

                    quantity= quantity-1;

                    x->quantity = quantity;

                    }



                        cout << "Movie has been rented." << endl;




                    cout	<<	"Movie Info:"	<<	endl;
                    cout	<<	"==========="	<<	endl;
                    cout << "Ranking:" << root->ranking <<endl;
                    cout << "Title:" << root->title <<endl;
                    cout << "Year:" << root->year <<endl;
                    cout << "Quantity:" << root->quantity <<endl;


                    }

                    found = 1;
                } if(found!=1){

           rentMovie( title,x->leftChild );    // Print items in left subtree.
           rentMovie( title,x->rightChild );   // Print items in right subtree.
           }

        }





}
