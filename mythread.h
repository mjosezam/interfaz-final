#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>

class MyThread: public QThread
{
  Q_OBJECT
protected:
  void run(int argc, char *argv[]);
  int a;
  char *b;
public:
  MyThread(int a,char *b[]);
  int hello(int argc,char *argv[]);
};

#endif // MYTHREAD_H
