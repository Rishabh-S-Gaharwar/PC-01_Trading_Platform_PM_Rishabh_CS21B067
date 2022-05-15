#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;
typedef long double ld;

ld todouble(string& s){
    double r=0;
    int n = s.length(), temp;
    for(int i=0; i<5; i++){
        temp = s[i]-'0';
        r*=10;
        r+=temp;
    }
    int x = n - 6;
    for(int j=1; j<=x; j++){
        temp = s[j+5]-'0';
        r += 1.0*temp/pow(10,j);
    }
    return r;
}

int main(void){
    fstream inp;
    string path = "/home/rishabh/April 22 NIFTY.csv"; //FilePath name as on my system (Downloaded the dataset)
    inp.open(path, ios::in);

    ld n=3;
    cout<<"Enter the number of days (As per question: 3 or 5) \n";
    cin>>n;

    string date, open, high, low, close, traded, turnover;
    ld count, len;

    ld sum=0, avg=0, temp=0;

    vector<ld> v; //To store closing prices
    vector<string> dates; //To store the dates corresponding to closing prices

    //Read and move on from first line
    getline(inp, date, ',');
    getline(inp, open, ',');
    getline(inp, high, ',');
    getline(inp, low, ',');
    getline(inp, close, ',');
    getline(inp, traded, ',');
    getline(inp, turnover, '\n');

    //Read records of other rows
    while(inp.good()){

        date="", open="", high="", low="", close="", traded="", turnover="";

        getline(inp, date, ',');
        getline(inp, open, ',');
        getline(inp, high, ',');
        getline(inp, low, ',');
        getline(inp, close, ',');
        getline(inp, traded, ',');
        getline(inp, turnover, '\n');

        //Trim whitespaces and double quotes from date and closing value
        close.erase(remove(close.begin(), close.end(), ' '), close.end());  
        close.erase(remove(close.begin(), close.end(), '\"'), close.end());
        date.erase(remove(date.begin(), date.end(), '\"'), date.end());

        temp = todouble(close);
        v.push_back(temp);
        dates.push_back(date);
        temp=0;

        //break out of the loop after reading last row
        if(date=="29-Apr-2022"){
            break;
        }
    }
    inp.close();

    for(long i=n-1; i<v.size(); i++){ //To calculate moving average of n days, we're starting on nth day
        for(long j=i-(n-1); j<=i; j++){ //Summing up closing prices in previous n days
            sum+=v[j];
        }
        cout<<"Average on "<<dates[i]<<" is\t"<<1.0*sum/n<<"\n";
        sum=0;
    }

    return 0;
}

/*
Some Clarifications :
For some reason, stold(close) and stod(close) gives invalid input error. Thus, I had to define todouble() function to make the program work
Also, the precision isn't right, but it seems like the numbers have been rounded off by the compiler
*/