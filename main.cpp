#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
using namespace std;

map<string, string> tokens = {{"while", "keyword"},
                              {"(", "separator"},
                              {"s", "identifier"},
                              {"<", "operator"},
                              {"upper", "identifier"},
                              {")", "separator"},
                              {"t", "identifier"},
                              {"=", "operator"},
                              {"33.00", "real"},
                              {";", "separator"}};

string lexer(string lexeme) {
  if (tokens.count(lexeme) > 0) {
    return tokens[lexeme];
  }
  return "";
}

int main() {
  string lexeme;
  char c;
  ifstream fin("input_scode.txt");
  ofstream fout("output");
  if (fin.fail() || fout.fail()){
    printf("Unable to open file");
  }
  fout << "token" << setw(13) << "lexeme" << setw(10) << endl;
  while (fin >> c) {
    lexeme += c;
    if (lexer(lexeme) != ""){
      fout << left << lexer(lexeme) << "\t" << lexeme << setw(10) << endl;
      lexeme = "";
    }
  }
  fin.close();
  fout.close();
}