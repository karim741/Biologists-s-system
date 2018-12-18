#ifndef PROTEIN_H
#define PROTEIN_H
#include <iostream>
#include <fstream>
#include "Sequence.h"

using namespace std;

class Sequence ;
class RNA ;
class DNA ;

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
public:
    struct Codon
    {
        char value[4];    	    // 4th location for null character
        char AminoAcid;  	    // corresponding AminoAcid according to Table
    };
    Protein();
    Protein(const Protein& other ) ;
    Protein(char* seq, int len, Protein_Type type );
    RNA convertProteintoRNA() ;
    void Print() ;
    void set_type (int i) ;

    bool operator== (const Protein& other) const ;
    bool operator!= (const Protein& other) const ;
    Protein operator+ (const Protein& other) const ;
    friend istream& operator>> (istream& in, Protein& d) ;
    friend ostream& operator<< (ostream& out, Protein& d) ;

    string LoadSequenceFromFile(string filename );
    void SaveSequenceToFile(char* data,string filename);
    string* GetDNAStrandsEncodingMe(const DNA & bigDNA);
private:
    Protein_Type type ;
};

#endif // PROTEIN_H
