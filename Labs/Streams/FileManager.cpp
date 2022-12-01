//
// Created by Marco Galliani on 27/11/22.
//

#include "FileManager.h"

const FileManager::table_type& FileManager::parse_file(const std::string &filename, char d) {

    std::ifstream input{filename};

    /* getline(input,str,delim)
    input -	the stream to get data from
    str	- the string to put the data into
    delim -	the delimiter character

    getline reads characters from an input stream and places them into a string
    */

    if (input){
        std::string line;
        while(std::getline(input,line)){
            row_type row;
            //converting the string line into a stream, calling the constructor of the istringstream
            //class
            std::istringstream record(line);
            std::string el;
            while(std::getline(record,el,d))
                row.push_back(el);
            fields.push_back(row);
        }

    }
    else
        std::cout << "couldn't open: " + filename;

    return fields;
}
