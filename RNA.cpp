#include <iostream>
#include <fstream>
#include "Sequence.h"
#include "RNA.h"
#include "Protein.h"



using namespace std;
RNA::RNA()
{
    this->type = mRNA ;
}
RNA::RNA(const RNA& other)  {
    this->len = other.len ;
    seq = new char [len];
    for (int i = 0 ; i < len ; i++) {
        seq[i] = other.seq[i] ;
    }
    this->type = other.type ;
}
RNA::~RNA()
{

}
RNA::RNA(char * seq, int len, RNA_Type atype)
{
    for (int i = 0 ; i < len ; i++) {
        if (seq[i] != 'A' && seq[i] != 'C' && seq[i] != 'G' && seq[i] != 'U' )  throw wrongSequence() ;
    }
    this->len = len ;
    this->seq = seq ;
    this->type = atype ;

}
void RNA::Print()
{
    string t ;
    if (type == 1)
        t = "mRNA" ;
    if (type == 2)
        t = "pre_mRNA" ;
    if (type == 3)
        t = "mRNA_exon" ;
    if (type == 4)
        t = "mRNA_intron" ;


    cout << "The sequence is  : " << seq << " - of type : " << t <<  endl;
}
DNA RNA:: ConvertToDNA()
{
    DNA d;
    d.seq = new char [len];
    d.seq = this->seq ;
    for (int i = 0 ; i < len ; i++)
        if(d.seq[i] == 'U')
            d.seq[i] = 'T' ;
    return d;
}

Protein RNA:: convertfromRNAtoProtin ( )
{
    Protein p;
    p.seq = new char [len/3];
    int copyoflen = p.len = this->len / 3  ;

    string rna;
    for (int i=0 ; i < len ; i+=3, copyoflen-- )
    {
        for ( int j=i; j<i+3 ; j++ )
        {
            rna += seq[j];
        }

        for (int j=0 ; j < 64 ; j++ )
        {
            if (rna == codons[j].value)
            {
                p.seq[p.len-copyoflen] = codons[j].AminoAcid ;
                break ;
            }
        }
        rna ="";
    }



    return p ;
}

bool RNA:: operator== (const RNA& other) const
{
    bool s = 1  ;
    if (this->len != other.len)
        return 0 ;
    else
    {

        for (int i = 0 ; i < len ; i++ )
        {
            if (seq[i] != other.seq[i])
            {
                s = 0 ;
                break;
            }
        }
    }
    return ( s && this->type == other.type) ;
}
bool RNA:: operator!= (const RNA& other) const
{
    return !(other == *this) ;
}
RNA RNA:: operator+ (const RNA& other) const
{
    RNA r ;
    r.type = this->type ;
    r.len = this-> len + other.len ;
    r.seq =new char [r.len];
    for (int i = 0 ; i < r.len ; i++)
    {
        if (i < this->len)
        {
            r.seq[i] = this->seq[i] ;
        }
        else
            r.seq[i] = other.seq[i-len] ;

    }
    return r ;
}

void RNA:: set_type (int i)
{
    type = static_cast<RNA_Type>(i);

}

string RNA::LoadSequenceFromFile(string filename )
{
    string loaded_data;
    ifstream in;

    filename +=".txt";
    in.open(filename);

    in >>  loaded_data ;
    in.close();

    return loaded_data;

};
void RNA::SaveSequenceToFile(char* data,string filename)
{
    filename += ".txt";
    ofstream out;
    out.open(filename.c_str());

    out << data;

    out.close();

}
