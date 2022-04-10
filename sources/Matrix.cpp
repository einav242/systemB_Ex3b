#include "Matrix.hpp"
#include <iostream>
#include <stdexcept>
#include  <bits/stdc++.h>
#include <stdlib.h>
#include<string.h>
#include <cmath>
using namespace std;

double sum(zich::Matrix m) //Calculates the sum of the matrix
{
    const unsigned int r = m.row;
    const unsigned int c = m.colum;
    double sum = 0;
    for (unsigned int i = 0; i < r; i++)
    {
        for (unsigned int j = 0; j < c; j++)
        {
            sum += m.v[i][j];
        }
    }
    return sum;
}

namespace zich
{
    Matrix Matrix::operator+(const Matrix &a)
    {
        if (a.row != this->row || a.colum != this->colum) //only two matrices of the same size can be add
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        vector<double> ans(r * c); //build a new vector
        unsigned int k = 0;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                ans[k] = this->v[i][j] + a.v[i][j]; //insert the sum into the vector
                k++;
            }
        }
        Matrix sum{ans, int(r), int(c)}; //build a new matrix
        return sum;
    }

    Matrix Matrix::operator+() //this function returns a copy of the same matrix
    {
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        vector<double> ans(r * c);
        unsigned int k = 0;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                ans[k] = this->v[i][j];
                k++;
            }
        }
        Matrix result{ans, int(r), int(c)};
        return result;
    }

    Matrix Matrix::operator-(const Matrix &a) 
    {
        if (a.row != this->row || a.colum != this->colum) //only two matrices of the same size can be sub
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        vector<double> ans(r * c); //build a new vector
        unsigned int k = 0;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                ans[k] = this->v[i][j] - a.v[i][j]; // //inaert the sub into the vector
                k++;
            }
        }
        Matrix sub{ans, int(r), int(c)}; //build a new matrix
        return sub;
    }

    Matrix Matrix::operator-() //this function returns the same matrix with opposite values
    {
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        vector<double> ans(r * c);
        unsigned int k = 0;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                if (this->v[i][j] != 0)
                {
                    ans[k] = this->v[i][j] * (-1);
                }
                else
                {
                    ans[k] = 0;
                }
                k++;
            }
        }
        Matrix result{ans, int(r), int(c)};
        return result;
    }

    Matrix& Matrix::operator+=(const Matrix &a) //this function adds a new value to the matrix(the sum)
    {
        if (a.row != this->row || a.colum != this->colum)
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                this->v[i][j] += a.v[i][j];
            }
        }
        return *this;
    }

    Matrix& Matrix::operator-=(const Matrix &a) ///this function adds a new value to the matrix(the sub)
    {
        if (a.row != this->row || a.colum != this->colum)
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                this->v[i][j] -= a.v[i][j];
            }
        }
        return *this;
    }


    bool operator==(const Matrix &a, const Matrix &b)
    {
        if (a.row != b.row || a.colum != b.colum) //only two matrices of the same size can be compared
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        const unsigned int r = b.row;
        const unsigned int c = b.colum;
        for (unsigned int i = 0; i < r; i++) //we will go over all the values in the two matrices
        {
            for (unsigned int j = 0; j < c; j++)
            {
                if (a.v[i][j] != b.v[i][j]) //if there is a different value in the two matrices we return false
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool Matrix::operator>(const Matrix &a)
    {
        if (a.row != this->row || a.colum != this->colum) //only two matrices of the same size can be compared
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        //we will examine the sum of the value of each of the matrices
        double sum1 = sum(*this);
        double sum2 = sum(a);
        return (sum1 > sum2);
    }

    bool Matrix::operator>=(const Matrix &a)
    {
        if (a.row != this->row || a.colum != this->colum) //only two matrices of the same size can be compared
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        return (this->operator>(a) || operator==(a,*this)); //we will check if the matrix is large or equal
    }

    bool Matrix::operator<(const Matrix &a)
    {
        if (a.row != this->row || a.colum != this->colum) //Only two matrices of the same size can be compared
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        //we will examine the sum of the value of each of the matrices
        double sum1 = sum(*this);
        double sum2 = sum(a);
        return sum1 < sum2;
    }

    bool Matrix::operator<=(const Matrix &a)
    {
        if (a.row != this->row || a.colum != this->colum) //only two matrices of the same size can be compared
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        return (this->operator<(a) || operator==(a,*this)); //we will check if the matrix is small or equal
    }

    bool Matrix:: operator!=(const Matrix &a) const
    {
        if (a.row != this->row || a.colum != this->colum) //only two matrices of the same size can be compared
        {
            throw std::invalid_argument("the size of the two matrices should be the same");
        }
        return !(*this == a); //if the opertor '==' return false we will return true
    }

    Matrix& Matrix::operator++() //we will advance all the value of the matrix in one and then return the new matrix
    {
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                this->v[i][j] = this->v[i][j] + 1;
            }
        }
        return *this;
    }

    Matrix Matrix::operator++(int) //We will return the matrix and then advance all the value of the matrix in one
    {
        Matrix ans = +(*this);
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                this->v[i][j] = this->v[i][j] + 1;
            }
        }
        return ans;
    }

    Matrix& Matrix::operator--() //we will subtract all the value of the matrix in one and then return the new matrix
    {
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                this->v[i][j]--;
            }
        }
        return *this;
    }

    Matrix Matrix::operator--(int) //We will return the matrix and then subtract all the value of the matrix in one
    {
        Matrix ans = +(*this);
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                this->v[i][j]--;
            }
        }
        return ans;
    }

    Matrix operator*(const Matrix &a, const int other)
    {
        const unsigned int r = a.row;
        const unsigned int c = a.colum;
        vector<double> ans(r * c); // build a new vector
        unsigned int k = 0;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                ans[k] = a.v[i][j] * other; //insert the result into the vector
                k++;
            }
        }
        Matrix mult{ans, int(r), int(c)}; //build a new matrix
        return mult;
    }

    Matrix operator*(const int other, const Matrix &a) //the same operator only that the scalar position is to the left of the matrix
    {
        const unsigned int r = a.row;
        const unsigned int c = a.colum;
        vector<double> ans(r * c);
        unsigned int k = 0;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                ans[k] = a.v[i][j] * other;
                k++;
            }
        }
        Matrix mult{ans, int(r), int(c)};
        return mult;
    }

    Matrix& Matrix::operator*=(const int other) //this function insert a new value to the matrix(scalar multiplication)
    {
        const unsigned int r = this->row;
        const unsigned int c = this->colum;
        for (unsigned int i = 0; i < r; i++)
        {
            for (unsigned int j = 0; j < c; j++)
            {
                this->v[i][j] *= other;
            }
        }
        return *this;
    }

    Matrix Matrix::operator*(const Matrix &a) //multiply matrices
    {
        if (a.row != this->colum)
        {
            throw std::invalid_argument("The number of columns in the left matrix should be equal to the number of rows in the right matrix");
        }
        const unsigned int r = this->row;
        const unsigned int c = a.colum;
        vector<double> ans(r * c); //build a new vector and intilize 
        Matrix mult{ans, int(r), int(c)};//build a new matrix
        for (unsigned int i = 0; i < this->row; i++)
        {
            for (unsigned int j = 0; j < a.colum; j++)
            {
                for (unsigned int k = 0; k < this->colum; k++)
                {
                    mult.v[i][j] += this->v[i][k] * a.v[k][j];
                }
            }
        }
        return mult;
    }

    Matrix& Matrix::operator*=(const Matrix &a) //this function inaert a new value to the matrix(multiply matrices)
    {
        if (a.row != this->colum)
        {
            throw std::invalid_argument("The number of columns in the left matrix should be equal to the number of rows in the right matrix");
        }
        Matrix c = *this * a;
        this->v.assign(c.row, vector<double>(c.colum));
        this->row = c.row;
        this->colum = c.colum;
        for (unsigned int i = 0; i < this->row; i++)
        {
            for (unsigned int j = 0; j < this->colum; j++)
            {
                this->v[i][j] = c.v[i][j];
            }
        }
        return *this;
    }

    ostream &operator<<(ostream &out, const Matrix &a) //to print the matrix
    {
        for (unsigned int i = 0; i < a.row; i++)
        {
            out<<"[";
           for (unsigned int j = 0; j < a.colum; j++)
            {
                out<<a.v[i][j];
                if(j!=a.colum-1)
                {
                    out<<" ";
                }
            }
            out<<"]";
            if(i==a.row-1)
            {
                continue;
            }
            out<<"\n";
        }
        return out;
    }

    istream &operator>>(istream &in, Matrix &a) //get values for the function from the user
    {
        vector<double> v;
        unsigned int number_of_c=1;
        unsigned int number_of_r=0;
        unsigned int k=0;
        bool p=false;
        bool p1=false;
        bool p2=false;
        bool stop=false;
        unsigned int i=0;
        char mat=' ';
        string temp;
        while (mat!=EOF)
        {
            in.get(mat);
            if(mat=='\n')
            {
                if(stop)
                {
                    break;
                }
                stop=false;
            }
            if(mat=='[')
            {   
                if(p1)
                {
                    throw std::invalid_argument("The character does not fit here");
                }
                if(stop)
                {
                    throw std::invalid_argument("The character does not fit here");
                }
                if(p)
                {
                    throw std::invalid_argument("The character does not fit here");
                }
                p1=true;
                number_of_c=1;
                continue;
            }
            if(mat==']')
            {
                if(p1)
                {
                    throw std::invalid_argument("The character does not fit here");
                }
                if(stop)
                {
                    throw std::invalid_argument("The character does not fit here");
                }
                if(p)
                {
                    throw std::invalid_argument("The character does not fit here");
                }
                stop=true;
                temp[k]='\0';
                double num=stod(temp);
                v.push_back(num);
                temp="";
                k=0;
                i++;
                number_of_r++;
                continue;
            }
            if(mat==',')
            {
                if(!stop)
                {
                    throw std::invalid_argument("The character does not fit here");
                }
                if(p1)
                {
                    throw std::invalid_argument("The character does not fit here");
                }
                if(p)
                {
                    throw std::invalid_argument("The character does not fit here");
                }
                stop=false;
                p=true;
                continue;
            }
            if(mat==' ')
            {
                if(p1)
                {
                    throw std::invalid_argument("The character does not fit here");
                }
                if(stop)
                {
                    throw std::invalid_argument("The character does not fit here");
                }
                temp[k]='\0';
                if(p)
                {
                    p=false;
                    continue;
                }
                number_of_c++;
                double num=stod(temp);
                v.push_back(num);
                temp="";
                k=0;
                i++;
                continue;
            }
             if(stop)
            {
                throw std::invalid_argument("The character does not fit here");
            }
            if(p)
            {
                throw std::invalid_argument("The character does not fit here");
            }
            p1=false;
            temp[k]=mat;
            k++;
        }
        a.row=number_of_r;
        a.colum=number_of_c;
        a.v.assign(number_of_r,vector<double>(number_of_c));
        unsigned int index=0;
        for(unsigned int i=0;i<a.row;i++)
        {
            for(unsigned int j=0;j<a.colum;j++)
            {
                a.v[i][j]=v[index];
                index++;
            }
        }
        return in;
    }
}