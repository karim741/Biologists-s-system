// Course:  CS213 - Programming II  - 2018
// Title:   Assignment IV
// Program: FCI-Biologist`s system
// Purpose: Store the Data for Biologists and make (DNA to RNA , RNA to DNA , DNA to Protein and RNA to Protein ) conversions
// Author 1:  Karim Mohamed Abdelfattah
// Author 2:  Abdelaziz Mohamed Abdelaziz
// Author 3:  karim mahmoud mosaed
// Last version Date: 14-12-2018

#include <iostream>
#include <fstream>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"


using namespace std;

void LCS( char *X, char *Y, int m, int n ) ;

int main()
{
    RNA r1;
    DNA d1;
    Protein p1;
    char* toFile ;
    string filename,loaded_file;
    int convertORlcs,length, insideLCS, insideConversion, zero ;

    cout << "\n----------------------- Welcome to Biologists`s system -------------------------\n\n";
    while (true)
    {
        cout << "Enter your sequence length :";
        cin >> length;

        char *str1 =new char[length], *str2 = new char[length] ;

        cout << "1) Load sequence from file \n2) Enter the sequence\nEnter your choice:";
        cin >> insideConversion;

///loading sequence from file

        if(insideConversion==1)
        {
            cout << "1) load DNA \n2) load RNA \n3) load Protein\nEnter your choice:";
            cin>>insideConversion;
            if(insideConversion==1)
            {
                cout << "Enter the name of the file :";
                cin >> filename;
                loaded_file = d1.LoadSequenceFromFile(filename);
            }
            else if(insideConversion==2)
            {
                cout << "Enter the name of the file :";
                cin >> filename;
                loaded_file = r1.LoadSequenceFromFile(filename);
            }
            else if(insideConversion==3)
            {
                cout << "Enter the name of the file :";  // load from file
                cin >> filename;
                loaded_file = p1.LoadSequenceFromFile(filename);
            }
        }
        else if(insideConversion==2)
        {
            cout << "Enter  your sequence :";
            cin >> str1;
        }
        cout << "1) conversion\n2) LCS \nEnter your choice:";
        cin >> convertORlcs;

        if(convertORlcs==1)
        {
            cout << "1) DNA to RNA  \n2) DNA to Protin \n3) RNA to DNA \n4) RNA to Protin \n5) Protin to RNA \nEnter your choice:" ;
            cin >> insideConversion;

            if(insideConversion==1)
            {
                RNA r2;
                try
                {
                    DNA d2(str1,length,tail);
                    r2 = d2.ConvertToRNA();
                    cout << r2;
                }
                catch (DNA::wrongSequence)
                {
                    cout << "OOPS wrong sequence !!" << endl;
                    cout<<"Sorry Wrong choice\n";
                }

                cout << "If you want save your sequence press 0 :";
                cin >> zero;
                if(zero == 0)
                {
                    cout << "Enter the name of the file :";  // load from file
                    cin >> filename;

                    toFile = r2.seq;
                    r2.SaveSequenceToFile(toFile,filename);
                }
                else
                    cout<<"Sorry Wrong choice\n";
            }
            else if(insideConversion==2)
            {
                string x;
                Protein p6 ;
                try
                {
                    DNA d7(str1,length,tail);
                    x = d7.convertToProtein();
                    cout << x << endl;

                }
                catch (DNA::wrongSequence)
                {
                    cout << "OOPS wrong sequence !!" << endl;
                    cout<<"Sorry Wrong choice\n";
                }
                for (int i=0 ; i< x.length();  i++)
                {
                    p6.seq[i] = x[i];
                }


                cout << "If you want save your sequence enter 0 :";
                cin >> zero;
                if(zero == 0)
                {
                    cout << "Enter the name of the file :";  // load from file
                    cin >> filename;


                    toFile = p6.seq;
                    p6.SaveSequenceToFile(toFile,filename);
                }
                else
                    cout<<"Sorry Wrong choice\n";
            }
            else if(insideConversion==3)
            {
                DNA d3;
                try
                {
                    RNA r3(str1, length,mRNA);
                    d3 = r3.ConvertToDNA();
                    cout << d3;
                }
                catch (RNA::wrongSequence)
                {
                    cout << "OOPS wrong sequence !!" << endl;
                    cout<<"Sorry Wrong choice\n";
                }
                cout << "If you want save your sequence enter 0 :";
                cin >> zero;
                if(zero == 0)
                {
                    cout << "Enter the name of the file :";  // load from file
                    cin >> filename;

                    toFile = d3.seq;
                    d3.SaveSequenceToFile(toFile,filename);
                }
                else
                    cout<<"Sorry Wrong choice\n";
            }
            else if(insideConversion==4)
            {
                Protein p2;
                try
                {
                    RNA r4(str1,length,mRNA) ;
                    p2 = r4.convertfromRNAtoProtin();
                    cout << p2;
                }
                catch (RNA::wrongSequence)
                {
                    cout << "OOPS wrong sequence !!" << endl;
                    cout<<"Sorry Wrong choice\n";
                }
                cout << "If you want save your sequence enter 0 :";
                cin >> zero;
                if(zero == 0)
                {
                    cout << "Enter the name of the file :";  // load from file
                    cin >> filename;

                    toFile = p2.seq;
                    p2.SaveSequenceToFile(toFile,filename);
                }
                else
                    cout<<"Sorry Wrong choice\n";
            }
            else if(insideConversion==5)
            {
                RNA r5;
                try
                {
                    Protein p3(str1,length,TF);
                    r5 = p3.convertProteintoRNA();
                    cout << r5;
                }
                catch (Protein::wrongSequence)
                {
                    cout << "OOPS wrong sequence !!" << endl;
                }
                cout << "If you want save your sequence enter 0 :";
                cin >> zero;
                if(zero == 0)
                {
                    cout << "Enter the name of the file :";  // load from file
                    cin >> filename;

                    toFile = r5.seq;
                    r5.SaveSequenceToFile(toFile,filename);
                }
                else
                    cout<<"Sorry Wrong choice\n";
            }

        }
        else if(convertORlcs==2)
        {
            cout << "Enter  your second  sequence :";
            cin >> str2;

            cout << "1) Normal \n2)Local \n3)Global\nEnter your choice:";
            cin >> insideLCS;

            if(insideLCS==1)
            {
                LCS(str1, str2, length, length) ;
            }
            else if(insideLCS==2)
            {

            }
            else if(insideLCS==3)
            {

            }
        }
    }
    return 0;
}

void LCS( char *X, char *Y, int m, int n )
{
    int L[m+1][n+1];
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
       that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    // Following code is used to print LCS
    int index = L[m][n];

    // Create a character array to store the LCS string
    char LCS[index+1];
    LCS[index] = '\0';

    // Start from the right-most-bottom-most corner and
    // one by one store characters in LCS[]
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        // If current character in X[] and Y are same, then
        // current character is part of LCS
        if (X[i-1] == Y[j-1])
        {
            LCS[--index] = X[--i]; // Put current character in result
            j--; // reduce values of i, j and index
        }

        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }

    // Print the LCS
    cout << "LCS of " << X << " and " << Y << " is " << LCS<<endl;
}

istream& operator>> (istream& in, DNA& d)
{
    int l,t ;
    cout << "enter sequence length :" ;
    in >> l;
    d.len = l ;
    d.seq =new char[d.len];
    cout << "enter the sequence :";
    in >> d.seq ;
    cout << "1)promoter\n2)motif\n3)tail\n4)noncoding\nEnter the type number :"   ;
    in >> t ;
    d.set_type(t)  ;
    return in ;

}
istream& operator>> (istream& in, RNA& d)
{
    int l,t ;
    cout << "enter sequence length :" ;
    in >> l;
    d.len = l ;
    d.seq = new char[d.len];
    cout << "enter the sequence :";
    in >> d.seq ;
    cout << "1)mRNA\n2)pre_mRNA\n3)mRNA_exon\n4)mRNA_intron\nEnter the type number :"   ;
    in >> t ;
    d.set_type(t)  ;
    return in ;

}
istream& operator>> (istream& in, Protein& d)
{
    int l,t ;
    cout << "enter sequence length :" ;
    in >> l;
    d.len = l ;
    d.seq =new char[d.len];
    cout << "enter the sequence :";
    in >> d.seq ;
    cout << "1)Hormon\n2)Enzyme\n3)TF\n4)Cellular_Function)\nEnter the type number :"   ;
    in >> t ;
    d.set_type(t)  ;
    return in ;

}
ostream& operator<< (ostream& out, DNA& d)
{
    string t ;
    if (d.type == 1)
        t = "promoter" ;
    else if (d.type == 2)
        t = "motif" ;
    else if (d.type == 3)
        t = "tail" ;
    else if (d.type == 4)
        t = "noncoding" ;
    out << d.seq << " - of type ( " << t << " )\n" ;
    return out ;
}
ostream& operator<< (ostream& out, RNA& d)
{
    string t ;
    if (d.type == 1)
        t = "mRNA" ;
    else if (d.type == 2)
        t = "pre_mRNA" ;
    else if (d.type == 3)
        t = "mRNA_exon" ;
    else if (d.type == 4)
        t = "mRNA_intron" ;
    out << d.seq << " - of type ( " << t << " )\n" ;
    return out ;
}
ostream& operator<< (ostream& out, Protein& d)
{
    string t ;
    if (d.type == 1)
        t = "Hormon" ;
    else if (d.type == 2)
        t = "Enzyme" ;
    else if (d.type == 3)
        t = "TF" ;
    else if (d.type == 4)
        t = "Cellular_Function" ;
    out << d.seq << " - of type ( " << t << " )\n" ;
    return out ;
}
