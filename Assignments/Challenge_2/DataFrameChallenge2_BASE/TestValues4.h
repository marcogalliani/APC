//
// Created by ing.conti on 13/12/22.
// TestValues_EVAL.h

#ifndef DATAFRAME_TESTVALUES_H
#define DATAFRAME_TESTVALUES_H


DataFrame df_1("a b c");
df_1.setColumn("a", Column("11,55,99999"));
df_1.setColumn("b", Column("2,3,"));
df_1.setColumn("c", Column("4,5"));
DataFrame df_2("d e");
df_2.setColumn("d", Column("6,1, 55"));
df_2.setColumn("e", Column("7,10"));


// columns where we ask for JOIN:
std::string ON_MY_COL{"a"};
std::string ON_OTHER_COLUMN{"d"};


#endif //DATAFRAME_TESTVALUES_H
