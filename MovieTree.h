#include <iostream>
#ifndef MOVIETREE_H
#define MOVIETREE_H
using namespace std;
struct MovieNode{
    int ranking;
    string title;
    int year;
    int quantity;
    MovieNode *leftChild;
    MovieNode *rightChild;
	MovieNode *parent;
};

class MovieTree
{
    public:
       virtual ~MovieTree();
       MovieTree();


        void rentMovie(string,MovieNode*);
        void printMovieInventory(MovieNode*);
        void addMovieNode(int,string,int,int);
        MovieNode* searchMovieTree(string,MovieNode*);
        MovieNode *topRoot;
           int found;
    protected:
    private:
        MovieNode *root;


};



#endif // MOVIETREE_H
