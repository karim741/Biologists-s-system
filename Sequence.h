#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <fstream>

using namespace std;

struct Codon
{
    string value ;    	    // 4th location for null character
    char AminoAcid;         // corresponding AminoAcid according to Table
};

class Sequence
{
public:
    class wrongSequence {};
    Codon codons[64];
    char* seq;
    int len ;
    string RNAtable[64];
    char ProtinTable[64];
    Sequence();
    Sequence(int length);
    Sequence(Sequence& rhs);
    virtual ~Sequence();
    virtual void Print()= 0;
    virtual string LoadSequenceFromFile(string filename )=0;
    virtual void SaveSequenceToFile(char* data,string filename)=0;
    friend char* Align(Sequence * s1, Sequence * s2);
};

#endif // SEQUENCE_H
