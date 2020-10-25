/**
  * @author: jahic
  * @details: generates a double array of random values and saves it into an array.
  *
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;


template <typename arrayDataType>
void generateDoubleArrayGeneric(vector<vector<arrayDataType>>& array, int arrayLength, int arrayWidth, int maxValue, string fileName);

template <typename arrayDataType>
void generateDoubleArrayGeneric(vector<vector<arrayDataType>>& array, int arrayLength, int arrayWidth, int maxValue, string fileName)

{
    srand (time(NULL));

    // Populate with random values.
    for (int i = 0; i < arrayLength; i++)
    {
        for (int j = 0; j < arrayWidth; j++)
             array[i][j] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/maxValue));
            //array[i][j] = (rand() % maxValue);
    }

    for (int i = 0; i < arrayLength; i++)
    {
        for (int j = 0; j < arrayWidth; j++)
            cout << array[i][j] << endl;
    }

    // Write to a file.
    // Open the File
    ofstream file;
    file.open(fileName.c_str());

    for (int i = 0; i < arrayLength; i++)
    {
        for (int j = 0; j < arrayWidth; j++)
        {
            file << array[i][j];
            if(j<arrayLength-1)
                file << " ";
        }
        if(i<arrayLength-1)
            file << "\n";
    }

    file.close();
}

// ./progName arrayLength arrayWidth elementsType maxValue fileName
int main(int argc, char* argv[])
{
    int arrayLength = 0;
    int arrayWidth = 0;
    char* elementsType;
    int maxValue = 0;
    string fileName;

    if(argc==6)
    {
        std::istringstream ss(argv[1]);
        if (!(ss >> arrayLength))
        {
          std::cerr << "Invalid number: " << argv[1] << '\n';
          return -1;
        }

        ss.clear(); ss.str(argv[2]);
        if (!(ss >> arrayWidth))
        {
          std::cerr << "Invalid number: " << argv[2] << '\n';
          return -1;
        }

        ss.clear(); ss.str(argv[4]);
        if (!(ss >> maxValue))
        {
          std::cerr << "Invalid number: " << argv[4] << '\n';
          return -1;
        }
        elementsType = argv[3];
        fileName = argv[5];
    }
    else
    {
        cout << "Wrong number of arguments...exiting."<< endl;
        cout << "Template: ./progName arrayLenght arrayWidth elementsType maxValue fileName"<< endl;
        cout << "Example: ./progName 1000 1000 i 5 doubleArray.txt"<< endl;
        cout << "----------------------------------------------------------"<< endl;
        cout << "Help:"<< endl;
        cout << "   elementsType:"<< endl;
        cout << "       i - integer"<< endl;
        cout << "       l - long"<< endl;
        cout << "       f - float"<< endl;
        cout << "       d - double"<< endl;
        cout << "   maxValue: maximum value of a number in the array - int."<< endl;
        cout << "----------------------------------------------------------"<< endl;
        return -1;
    }
    cout << endl;
    cout << "----------------------------------------------------------"<< endl;
    cout << "Inputs:"<< endl;
    cout << "   arrayLenght = "<< arrayLength << endl;
    cout << "   arrayWidth = "<< arrayWidth << endl;
    cout << "   elementsType = "<< elementsType << endl;
    cout << "   maxValue = "<< maxValue << endl;
    cout << "   fileName = "<< fileName << endl;
    cout << "----------------------------------------------------------"<< endl;

    if(*elementsType == 'i')
    {
        vector<vector<int>> array(arrayLength, vector<int> (arrayWidth));
        generateDoubleArrayGeneric(array, arrayLength, arrayWidth, maxValue, fileName);
    }
    else if(*elementsType == 'l')
    {
        vector<vector<long>> array(arrayLength, vector<long> (arrayWidth));
        generateDoubleArrayGeneric(array, arrayLength, arrayWidth, maxValue, fileName);
    }
    else if(*elementsType == 'f')
    {
        vector<vector<float>> array(arrayLength, vector<float> (arrayWidth));
        generateDoubleArrayGeneric(array, arrayLength, arrayWidth, maxValue, fileName);
    }
    else if(*elementsType == 'd')
    {
        vector<vector<double>> array(arrayLength, vector<double> (arrayWidth));
        generateDoubleArrayGeneric(array, arrayLength, arrayWidth, maxValue, fileName);
    }

    return 0;
}
