#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <fstream>

using namespace std;

void rozklad(int &a, int &b, int c, int &d)
{
    if(c == 0)
    {
        a=0;
        b=0;
        d=0;
    }
    else if(c < 0)               //22 do tylu c=-22
    {
        c *= -1;                 //c=22
        a = c/sqrt(c);           //a=22/5      -> a=4
        b = (c/a) * -1;          //b=22/4 *-1  -> b=-5
        d = ( c + a*b ) * -1;    //d=22-20 *-1 -> d=-2
    }
    else if(c > 0)
    {
        a = c/sqrt(c);
        b = c/a;
        d = c-(a*b);
    }
}


int movec(int a, int b, int d, string &output)
{
    bool czy_wrocic = false;
    output = "";

    if((a*b+d) > 15 || (a*b+d) * -1 > 15)
    {
        if(b < 0)
        {
            b *= (-1);

            for(int i=0; i<a; i++)
                output += "+";

            output += "[>";

            for(int i=0; i<b; i++)
                output += "-";

            output += "<-]";

            if(d<0)
            {
                d*=(-1);
                output += ">";
                czy_wrocic = true;
                for(int i=0; i<d; i++)
                    output += "-";
            }
            else if(d>0)
            {
                output += ">";
                czy_wrocic = true;
                for(int i=0; i<d; i++)
                    output += "+";
            }
            else if(d==0)
            {
                output+=">";
                czy_wrocic = true;
            }
        }
        else
        {
            for(int i=0; i<a; i++)
                output += "+";

            output += "[>";

            for(int i=0; i<b; i++)
                output += "+";

            output += "<-]";

            if(d<0)
            {
                d*=(-1);
                output += ">";
                czy_wrocic = true;
                for(int i=0; i<d; i++)
                    output += "-";
            }
            else if(d>0)
            {
                output += ">";
                czy_wrocic = true;
                for(int i=0; i<d; i++)
                    output += "+";
            }
            else if(d==0)
            {
                output+=">";
                czy_wrocic = true;
            }
        }
    }
    else if((a*b+d) < 0)
    {
        output += ">";
        czy_wrocic = true;
        for(int i=((a*b+d) * -1); i > 0; i--)
            output += "-";
    }
    else
    {
        output += ">";
        czy_wrocic = true;
        for(int i=(a*b+d); i > 0; i--)
            output += "+";
    }
    output += ".";
    if(czy_wrocic) output += "<";
    //cout << output << endl;
}

int main()
{
    int a,b,d,i=0;
    int temp = 0;
    char c;
    char bufor[4096];
    string output = "";
    fstream output_file, input_file;

    input_file.open("bfck_input.txt", ios::in);
        input_file.read(bufor, 4096);
    output_file.open("bfck_output.txt", ios::out);

    for(int i = 0; i < input_file.gcount(); i++)
    {
        c = bufor[i];
        cout << i << " -> " << c << endl;
        rozklad(a, b, (int)c-temp, d);
        movec(a, b, d, output);
        output_file << output;
        temp=(int)c;
    }
    if(output_file.good())
        cout << "\nPomyslnie przetlumaczono i zapisano dane do pliku!" << endl << endl;
        getch();
    return 0;
}



///dynamic translation (without files)
/*while((int)c != 27)
    {
        c = getch();
        cout << "ASCII: " << (int)c << endl;
        cout << "Poprzednia: " << temp << endl;
        cout << "Do przesuniecia: " << (int)c-temp << endl;
        rozklad(a, b, (int)c-temp, d);
        cout << "Rozklad roznicy: " << a << "*" << b << " + " << d << endl;
        movec(a, b, d, output);
        output_file << output;
        temp=(int)c;
        i++;
    }
        */
