#include <iostream>
#include "Sequence.h"
#include <fstream>

using namespace std;



Sequence::Sequence()
{
        ifstream infile,infile2;
        infile.open("RNA_codon_table.txt");
        infile2.open("Protin_codon_table.txt");

        while(!infile.eof())
        {
            for(int i=0; i<64; i++)
            {
                infile>>codons[i].value;
                infile2>>codons[i].AminoAcid;
            }
        }
        infile.close();
        infile2.close();


}

Sequence::~Sequence(){}
