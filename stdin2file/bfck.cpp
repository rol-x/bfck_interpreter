#include <iostream>
#include <math.h>
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


int move(int a, int b, int d, int c, int temp, string &output)
{

    output = "";
    if((a*b+d) > 15 || (a*b+d) * -1 > 15)
    {
        if(b < 0)
        {
            b *= (-1);


            if((int)c-temp>15||((int)c-temp*(-1))>15) output += "<";





            for(int i=0; i<a; i++)
                output += "+";

            output += "[>";

            for(int i=0; i<b; i++)
                output += "-";

            output += "<-]>";

            if(d<0)
            {
                d*=(-1);

                for(int i=0; i<d; i++)
                    output += "-";
            }
            else if(d>0)
            {

                for(int i=0; i<d; i++)
                    output += "+";
            }
        }
        else
        {


        	if((int)c-temp>15) output += "<";




            for(int i=0; i<a; i++)
                output += "+";

            output += "[>";

            for(int i=0; i<b; i++)
                output += "+";

            output += "<-]>";

            if(d<0)
            {
                d*=(-1);

                for(int i=0; i<d; i++)
                    output += "-";
            }
            if(d>0)
            {

                for(int i=0; i<d; i++)
                    output += "+";
            }
        }
    }
    else if((a*b+d) < 0)
    {
        for(int i=((a*b+d) * -1); i > 0; i--)
            output += "-";
    }
    else
    {
        for(int i=(a*b+d); i > 0; i--)
            output += "+";
    }
    output += ".";
}

int main()
{
    int a,b,d, m;
    int temp = 0;
    char c;
    fstream output_file;
    output_file.open("bfck_out.txt", ios::out);

    std::string s, output = "";
	cout<<"Wprowadz tekst do przetlumaczenia na bfck: "<<endl;
    getline(cin,s);
    cout<<endl;

    for (int m = 0; m < s.size(); ++m) {
        c = s[m];
        rozklad(a, b, (int)c-temp, d);
        move(a, b, d, c, temp, output);
        output_file << output;
        temp=(int)c;
    }
    if(output_file.good()) cout << "Dane przetlumaczone i zapisane do pliku!\n";
    return 0;
}

//script made by Karol Latos & Jeremi Chabros 2015
