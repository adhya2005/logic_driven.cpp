#include <igloo/igloo.h>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace igloo;

std::string exec(std::string command) {
   char buffer[128];
   std::string result = "";

   // Open pipe to file
   FILE* pipe = popen((command + " 2>&1").c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   pclose(pipe);
   result.erase(result.find_last_not_of(" \t\n\r\f\v") + 1);
   return result;
}

Context(TextProgram){
    static void SetUpContext() {
        exec("g++ main.cpp -o temp");
    }

    static void TearDownContext() {
        system("rm -rf temp");
    }

    Spec(TestTeacher1){
        std::string result = exec("./temp < teacher1.txt");
        float avg = stof(result);
        Assert::That(avg, EqualsWithDelta(68.2593, 0.01));
    }
    Spec(TestTeacher2){
        std::string result = exec("./temp < teacher2.txt");
        float avg = stof(result);
        Assert::That(avg, EqualsWithDelta(72.9048, 0.01));
    }
    Spec(TestTeacher3){
        std::string result = exec("./temp < teacher3.txt");
        float avg = stof(result);
        Assert::That(avg, EqualsWithDelta(69.8824, 0.01));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}