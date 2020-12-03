// Copyright 2020
// Author: Daniel Rush

enum LoggerLevels {
  kLogDebug = 0,
  kLogInfo  = 1,
  kLogError = 2,
  kLogFatal = 3
};

class Logger {
 public:
  void Printf();
 private:
  void Write();
};
