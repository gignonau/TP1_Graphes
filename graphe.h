#ifndef GRAPHE_H
#define GRAPHE_H

#include <iostream>
#include <vector>
using namespace std;

class GRAPHE{
public :
    GRAPHE(int length){
        vector<vector<int>> matrix1(length, vector<int>(length));
        matrix = matrix1;
    }
    GRAPHE(){lenght = 0;}

    void ajouterArc(int s1, int s2, int weight){matrix[s1][s2]=weight;}
    int getLenght() const;
    void setLenght(int value);
    void addReloadPoint(int a){reloadPoints.push_back(a);}
    int getWeightAt(int s1, int s2){
        return matrix[s1][s2];
    }

    vector<string> getNamesSommets() const;
    void setNamesSommets(const vector<string> &value);

    void setNameAt(int a, string b);
    string getNameAt(int a);

    vector<vector<int> > getMatrix() const;
    void setMatrix(const vector<vector<int> > &value);

private :
    vector<int> reloadPoints;
    vector<vector<int>> matrix;
    int lenght;
    vector<string> namesSommets;

};

#endif // GRAPHE_H
