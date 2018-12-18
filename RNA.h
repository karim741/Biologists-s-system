#ifndef RNA_H
#define RNA_H
#include <iostream>
#include <fstream>
#include "DNA.h"
#include "Protein.h"

using namespace std;

enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA :  public Sequence
{

  	private:
        RNA_Type type;
  	public:
 	 	// constructors and destructor
        RNA();
        RNA(char * seq,int endIndex , RNA_Type atype);
        RNA(const RNA& other);
        ~RNA();
        void set_type (int i) ;
        bool operator== (const RNA& other) const ;
        bool operator!= (const RNA& other) const ;
        RNA operator+ (const RNA& other) const ;
         friend istream& operator>> (istream& in , RNA& d) ;
        friend ostream& operator<< (ostream& out  , RNA& d) ;

 	 	// function to be overridden to print all the RNA information
        void Print();
 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
//        Protein ConvertToProtein(const CodonsTable & table);
 	 	// function to convert the RNA sequence back to DNA
        DNA ConvertToDNA();
        Protein convertfromRNAtoProtin ( ) ;

       string LoadSequenceFromFile(string filename);
       void SaveSequenceToFile(char* data,string filename);

};

#endif // RNA_H
