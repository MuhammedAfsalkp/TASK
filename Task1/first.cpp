#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

// Function to check an input is number or not
bool isNumber(string str)
{
    bool flag = false;
    for (int i = 0; i < str.length(); i++)
    {

        if (isdigit(str[i]))
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return (flag == true) ? true : false;
}


int main()
{
    fstream file;
    float oddAverage, evenAverage;
    float oddSum = 0, evenSum = 0, oddCount = 0, evenCount = 0;
    file.open("numbers.txt", ios::in);

     if( file.fail( ) ) {
            cout << "Error - Failed to open " ;
            exit( 0); 
        }
    
    else
    {
        string str;
        while (!file.eof())
        {
            getline(file, str);
            if (isNumber(str))
            {
                int num = stoi(str);
                if (num % 2 == 0)
                {
                    if (num == 0)
                        continue;
                    oddCount++;
                    oddSum += num;
                }
                else
                {
                    evenCount++;
                    evenSum += num;
                }
            }
        }
        oddAverage = oddSum / oddCount;
        evenAverage = evenSum / evenCount;
        file.close();
    }

    // To write the output into a file output.txt
    file.open("output.txt", ios::out);
     if (file.fail())
    {
        cout << "Failed to open file for writing" << endl;
        exit(0);
    }
    string data = "Average of odd numbers  = ";
    data += to_string(oddAverage);
    data += "\n";
    data += "Average of even numbers  = ";
    data += to_string(evenAverage);

    file << data << endl;

   

    file.close();

    return 0;
}


//we can also use buffer to speed up