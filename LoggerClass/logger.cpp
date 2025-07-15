#include<string>
#include<iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

class logReader{
    std::ifstream mfile;

    public:
        explicit logReader(const string& filepath): {
            mfile.open(filepath);
        }

        bool hasNextLine(){
            return mfile.peek() != EOF;
        }

        std::string getNextLine(){
            string line;
            getline(mfile, line);
            return line;
        }
};

class logParser{

    public:
        std::string parseError(const string& line){
            if(line.find("Error") != string::npos){
                return line;
            }
            return "";
        }
};

class errorAggregator{

    std::unordered_map<string, int> errorcount;

public:
    void addError(const string& errorMsg){
        errorcount[errorMsg]++;
    }

    void getTopErrors(){

    }

};

int main()
{
    logReader reader("log.txt");
    logParser parser;

    errorAggregator aggregator;

    while(reader.hasNextLine()){
        string line = reader.getNextLine();
        string error = parser.parseError(line);
        aggregator.addError(error);
    }

};