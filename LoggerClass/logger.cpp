#include<string>
#include<iostream>

using namespace std;

class logFile{
    string filepath;
    std::ifstream mfile;

    logFile(const string& path): filepath(path){
        mfile.open(path);
    };
};

class logReader{
    logFile* ofile;

    public:
        explicit logReader(logFile* pfile): ofile(pfile){};

        bool hasNextLine(){
            return ofile.peek() =! EOF;
        }

        std::string getNextLine(){
            string line;
            getline(file, line);
            return line;
        }
};