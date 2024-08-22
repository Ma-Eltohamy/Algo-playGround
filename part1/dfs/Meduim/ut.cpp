#include <fstream>
#include <iostream>
#include <string>

void change(std::string &str) {
  for (int i = 0; i < (int)str.size(); ++i) {
    if (str[i] == '"')
      str[i] = '\'';

    else if (str[i] == '[')
      str[i] = '{';

    else if (str[i] == ']')
      str[i] = '}';
  }
}

int main(int argc, char *argv[]) {
  std::string inputFileName = "input.txt";
  std::string outputFileName = "output.txt";

  // Open the input file for reading
  std::ifstream inputFile(inputFileName);
  if (!inputFile) {
    std::cerr << "Error opening input file: " << inputFileName << std::endl;
    return 1;
  }

  // Open the output file for writing
  std::ofstream outputFile(outputFileName);
  if (!outputFile) {
    std::cerr << "Error opening output file: " << outputFileName << std::endl;
    return 1;
  }

  std::string line;
  // Read from the input file line by line
  while (std::getline(inputFile, line)) {
    // Write each line to the output file
    change(line);
    outputFile << line << std::endl;
  }

  // Close the files
  inputFile.close();
  outputFile.close();
  return 0;
}
