// DataFrame.cpp source file

#include <iomanip>
#include "DataFrame.h"

std::string DataFrame::PREFIX1{"df1_"};
std::string DataFrame::PREFIX2{"df2_"};


// Helper functions Protos:
void tabbed(double value, bool showZeros = true);
void tabbed(std::string string);
void tab();
std::vector<std::string> addPrefix(const std::vector<std::string> & to, std::string prefix);




DataFrame::DataFrame(const std::string &columnNamesString) : DataFrame() {
    Keys columnsNames = split(columnNamesString, ' ');

    for (const Key &name: columnsNames)
        dataFrameData[name];
}

DataFrame::Keys DataFrame::split(const std::string &s, char delim) const {
    Key word;
    Keys v;
    std::istringstream columns(s);

    while (std::getline(columns, word, delim)) v.push_back(word);

    return v;
}

bool DataFrame::checkColumnName(const std::string &columnName) const {
    return dataFrameData.find(columnName) != dataFrameData.end();
}


Column DataFrame::getColumn(const std::string &columnName) const {
    if (checkColumnName(columnName))
        return dataFrameData.at(columnName);
    else {
        std::cerr << "Error, " << columnName << " is unknown" << std::endl;
        return Column();
    }
}


void DataFrame::setColumn(const std::string &columnName,
                           const Column &column) {
    if (checkColumnName(columnName))
        dataFrameData[columnName] = column;
    else
        std::cerr << "Error, " << columnName << " is unknown" << std::endl;
}



bool DataFrame::addColumn(const Key &columnName,
                           const Column &columnData) {
    if (!checkColumnName(columnName)) {
        dataFrameData[columnName] = columnData;
        return true;
    }
    else {
        return false;
    }
}

std::vector<DataFrame::Key> DataFrame::getColumnNames() const {

    Keys names = Keys();

    for (const valueType &element: dataFrameData) {
        std::string s = element.first;
        names.push_back(s);
    }

    return names;
}


// // we se are simulating arrays, number or rows will be the max value in keys
dimension DataFrame::getDimension() const {
    auto colNames = getColumnNames();
    if (colNames.empty()){
        return {0,0};
    }

    auto cols = colNames.size();

    // cannot be equal, se we have sparse columns:

    /* if dense, every column with same height, so:
    auto values0 = get_column(colNames[0]);
    auto rows = values0.height();
     */
    
    // but we must search for max key:
    size_t rows = 0;
    for(std::string name: colNames){
        auto values = getColumn(name);
        auto H = values.height();
        rows = std::max(rows, H);
    }
    
    return {rows, cols};
}



void DataFrame::print(void) const {

    // write all columns names:
    auto colNames = getColumnNames();
    for (auto t: colNames) {
        tabbed(t);
    }

    newLine();

    auto dimension = getDimension();
    
    if (dimension.rows == 0)
        return;

    for (int row = 0; row < dimension.rows; row++) {

        auto valuesArray = getValuesAtRow(row);
            for(auto v : valuesArray){
                tabbed(v);
            }
            newLine();
    }

    newLine();
}


// TO BE IMPLEMENTED:

DataFrame
DataFrame::hstack(DataFrame &otherDataFrame){
    // YOUR CODE HERE

    //get the names of the columns
    Keys mydf_names = getColumnNames(), otherdf_names = otherDataFrame.getColumnNames(), new_names(mydf_names), temp_names(otherdf_names);
    //prefix
    new_names = addPrefix(new_names,PREFIX1);
    temp_names = addPrefix(temp_names,PREFIX2);
    //final df names
    new_names.insert(new_names.end(),temp_names.begin(),temp_names.end());

    //declaring a new df
    DataFrame new_df(new_names);

    size_t i=0;
    //setting columns from mydf
    for (auto & name:mydf_names) {
        new_df.setColumn(new_names[i], getColumn(name));
        i++;
    }
    //setting columns from otherdf
    for (auto & name:otherdf_names) {
        new_df.setColumn(new_names[i], otherDataFrame.getColumn(name));
        i++;
    }
    return new_df;
}

DataFrame DataFrame::join(DataFrame &otherDataFrame, std::string onMyCol, std::string onColOfOther){
    // YOUR CODE HERE

    //IDEA: checking for elements in the first column that are also in the second column, add the lines that
    //satisfy the previous condition to a new dataframe
    //helper: implement an add_line method
    //Keep in mind that values in the column class are public

    //get the names of the columns
    Keys col_names = getColumnNames(), otherdf_names = otherDataFrame.getColumnNames();
    //adding prefixes
    col_names = addPrefix(col_names,PREFIX1);
    otherdf_names = addPrefix(otherdf_names,PREFIX2);
    //reserve memory for newdf_names
    size_t new_ncols = col_names.size()+otherdf_names.size();
    col_names.reserve(new_ncols);
    //create a vector of column names concatenating the names of the first df with the names of the second
    col_names.insert(col_names.end(),otherdf_names.begin(),otherdf_names.end());
    //initialising a new dataframe with the new names vector
    DataFrame new_df = DataFrame(col_names);
    //get the columns to be joined
    Column my_col = getColumn(onMyCol),other_col = otherDataFrame.getColumn(onColOfOther);

    //add the common rows to the new dataset
    for(auto my_it : my_col.values){
        for(auto other_it : other_col.values){
            if (my_it.second == other_it.second){
                //get the common rows
                ValuesArray val = getValuesAtRow(my_it.first);
                ValuesArray other_val = otherDataFrame.getValuesAtRow(other_it.first);
                //prepare the row to be insterted in the new dataframe
                val.insert(val.end(),other_val.begin(),other_val.end());
                //insert the row in the new dataset
                add_row(new_df, val);
            }
        }
    }

    return new_df;

}

void DataFrame::add_row(DataFrame & df, ValuesArray &row) {

    size_t nrows = df.getDimension().rows;
    size_t i=0;
    for (auto & it : df.dataFrameData) {
        //inserting each element of the row in the corresponding column
        it.second.insert(row[i],nrows);
        i++;
    }
}




// ancillary code

DataFrame::DataFrame(std::vector<std::string> columnsNames)
: DataFrame() {
    for (const Key &name: columnsNames)
        dataFrameData[name];
}


ValuesArray DataFrame::getValuesAtRow(size_t row) const{
    ValuesArray result = {};
    
    auto colNames = getColumnNames();
    for (auto name:colNames) {
        auto column = getColumn(name);
        auto value = column.values[row];
        result.push_back(value);
    }
    return result;
}


// MARK: Helper functions:



void tabbed(double value, bool showZeros){

    if (value == 0 && !showZeros){
        std::cout << "       " << "|";
    }else{
        std::cout << std::setw(7);
        std::cout << value << "|";
    }
}



void tabbed(std::string string){
    auto stdLen = 7;
    auto len = string.size();
    auto spaces = stdLen-len;
    std::cout << string;
    for (int i = 0; i < spaces; ++i) {
        std::cout << " ";
    }
    std::cout << "|";

}

void tab(){
    tabbed("");
}

void newLine(std::string s){
    std::cout << s << std::endl;
}



std::vector<std::string> addPrefix(const std::vector<std::string> & to, std::string prefix){
    std::vector<std::string> out;

    std::transform(to.begin(), to.end(),
                   std::back_inserter(out),
                   [&prefix](std::string v) { return prefix+v; }
    );
    return out;
}

