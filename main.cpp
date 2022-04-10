

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Matrix.hpp"
using namespace zich;

int main()
{
    string ans;
    char countin;
    int r=10;
    int c=10;
    Matrix m(r, c);
    cout << "enter the value of the matrix\n";
    cin >> m;
    cout << "\nthe matrix:\n"
         << m;
    cout << "choose operator: +(mat)/++/+=/+()/-(mat)/--/-=/-() ";
    cin >> ans;
    if (ans == "+(mat)")
    {
        Matrix m1(r, c);
        cout << "enter the value of the second matrix(row=" << r << ",colum=" << c << ")\n";
        cin >> m1;
        cout << "the matrix:\n";
        cout << m << "+"
             << "\n"
             << m1 << "="
             << "\n"
             << m + m1 << endl;
        cout << "do you want to see more? Y/N ";
        cin >> countin;
    }
    if (ans == "++")
    {
        cout << m << "++"
             << "\n"
             << "="
             << "\n"
             << ++m << endl;
        cout << "do you want to see more? Y/N ";
        cin >> countin;
    }
    if (ans == "+=")
    {
        Matrix m1(r, c);
        cout << "enter the value of the second matrix(row=" << r << ",colum=" << c << ")\n";
        cin >> m1;
        cout << "the matrix:\n";
        cout << m << "+="
             << "\n"
             << m1 << "="
             << "\n"
             << endl;
        m += m1;
        cout << m << endl;
        cout << "do you want to see more? Y/N ";
        cin >> countin;
    }
    if (ans == "+()")
    {
        cout << "+" << m << "\n"
             << "="
             << "\n"
             << +m << endl;
        cout << "do you want to see more? Y/N ";
        cin >> countin;
    }
    if (ans == "-(mat)")
    {
        Matrix m1(r, c);
        cout << "enter the value of the second matrix(row=" << r << ",colum=" << c << ")\n";
        cin >> m1;
        cout << "the matrix:\n";
        cout << m << "-"
             << "\n"
             << m1 << "="
             << "\n"
             << m - m1 << endl;
        cout << "do you want to see more? Y/N ";
        cin >> countin;
    }
    if (ans == "--")
    {
        cout << m << "--"
             << "\n"
             << "="
             << "\n"
             << --m << endl;
        cout << "do you want to see more? Y/N ";
        cin >> countin;
    }
    if (ans == "-=")
    {
        Matrix m1(r, c);
        cout << "enter the value of the second matrix(row=" << r << ",colum=" << c << ")\n";
        cin >> m1;
        cout << "the matrix:\n";
        cout << m << "-="
             << "\n"
             << m1 << "="
             << "\n"
             << endl;
        m -= m1;
        cout << m << endl;
        cout << "do you want to see more? Y/N ";
        cin >> countin;
    }
    if (ans == "-()")
    {
        cout << "-" << m << "\n"
             << "="
             << "\n"
             << -m << endl;
        cout << "do you want to see more? Y/N ";
        cin >> countin;
    }
    if (countin == 'N')
    {
        cout << "bye bye\n";
        exit(1);
    }
    cout << "chosse operator: </>/>=/<=/==/!= ";
    cin>>ans;
    if (ans == "<")
    {
        Matrix m1(r, c);
        cout << "enter the value of the second matrix(row=" << r << ",colum=" << c << ")\n";
        cin >> m1;
        if (m < m1)
        {
            cout << m<<"<"<<m1 <<"is true!\n";
        }
        else
        {
            cout << m<<"<"<<m1 <<"is fasle!\n";
        }
        cout << "do you want to see more? Y/N ";
        cin >> countin;
    }
    if (ans == ">")
    {
        Matrix m1(r, c);
        cout << "enter the value of the second matrix(row=" << r << ",colum=" << c << ")\n";
        cin >> m1;
        if (m > m1)
        {
            cout << m<<">"<<m1 <<"is true!\n";
        }
        else
        {
            cout << m<<">"<<m1 <<"is false!\n";
        }
        cout << "do you want to see more? Y/N ";
        cin >> countin;
    }
    if(ans==">=")
    {
        Matrix m1(r, c);
        cout << "enter the value of the second matrix(row="<<r<<",colum="<<c<<")\n";
        cin >> m1;
        if(m>=m1)
        {
           cout << m<<">="<<m1 <<"is true!\n";
        }
        else
        {
            cout << m<<">="<<m1 <<"is false!\n";
        }
        cout << "do you want to see more? Y/N ";
        cin >> countin;
    }
    if(ans=="<=")
    {
        Matrix m1(r, c);
        cout << "enter the value of the second matrix(row="<<r<<",colum="<<c<<")\n";
        cin >> m1;
        if(m<=m1)
        {
            cout << m<<"<="<<m1 <<"is true!\n";
        }
        else
        {
            cout << m<<"<="<<m1 <<"is false!\n";
        }
        cout << "do you want to see more? Y/N ";
        cin >> countin;
    }
    if(ans=="==")
    {
        Matrix m1(r, c);
        cout << "enter the value of the second matrix(row="<<r<<",colum="<<c<<")\n";
        cin >> m1;
        if(m==m1)
        {
            cout << m<<"=="<<m1 <<"is true!\n";
        }
        else
        {
            cout << m<<"=="<<m1 <<"is false!\n";
        }
        cout << "do you want to see more? Y/N ";
        cin >> countin;
    }
    if(ans=="!=")
    {
        Matrix m1(r, c);
        cout << "enter the value of the second matrix(row="<<r<<",colum="<<c<<")\n";
        cin >> m1;
        if(m!=m1)
        {
            cout << m<<"!="<<m1 <<"is true!\n";
        }
        else
        {
            cout << m<<"!="<<m1 <<"is false!\n";
        }
        cout << "do you want to see more? Y/N ";
        cin >> countin;
    }
    if (countin == 'N')
    {
        cout << "bye bye\n";
        exit(1);
    }
    cout << "chosse operator: *(mat)/*=(mat)/*(sqalr)/*=(sqalr) ";
    cin>>ans;
    if (ans == "*(mat)")
    {
        int c1;
        cout<<"enter number of colum ";
        cin>>c1;
        Matrix m1(c, c1);
        cout << "enter the value of the second matrix(row=" << c << ")\n";
        cin >> m1;
        cout << "the matrix:\n";
        cout << m << "*"
             << "\n"
             << m1 << "="
             << "\n"
             << m * m1 << endl;
    }
    if (ans == "*=(mat)")
    {
        int c1;
        cout<<"enter number of colum ";
        cin>>c1;
        Matrix m1(c, c1);
        cout << "enter the value of the second matrix(row=" << c << ")\n";
        cin >> m1;
        cout << "the matrix:\n";
        cout << m << "*="
             << "\n"
             << m1 << "="
             << "\n"
             << endl;
        m *= m1;
        cout << m << endl;
    }
            if (ans == "*(sqalr)")
    {
        double s;
        cout << "enter sqalr\n";
        cin >> s;
        cout << "the matrix:\n";
        cout << m << "*"
             << "\n"
             << s << "="
             << "\n"
             << m * s << endl;
    }
    if (ans == "*=(sqalr)")
    {
        double s;
        cout << "enter sqalr\n";
        cin >> s;
        cout << "the matrix:\n";
        cout << m << "*="
             << "\n"
             << s << "="
             << "\n"
             << endl;
        m *= s;
        cout << m << endl;
    }
    cout << "End of main!\n";
    return 0;
}
