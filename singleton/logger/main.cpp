#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Logger
{
public:
  static Logger& getInstance()
  {
    static Logger theInstance;
    return theInstance;
  }

  void logMsg(const char* fileName,const char* msg){
      string fn = fileName;
      string ms = msg;
      string out = fn+"::"+ms;
      msgs_.push_back(out);

  }
 // void logMsg(const char* fileName, const char* msg);
  void printAll(){
      for(auto e:msgs_){
          cout<<e<<endl;
      }
      cout<<endl;
  }

  Logger(const Logger &) = delete;
  Logger& operator=(const Logger &) = delete;

private:
  vector<string> msgs_;
  Logger() {} // private constructor
};

int main(){

    Logger &logger = Logger::getInstance();
    logger.logMsg(__FILE__, "File does not exist");
    //...
    logger.logMsg(__FILE__, "Load balancer is not responding");
    //...
    logger.printAll();

}
