#include <iostream>
#include "Logger.h"

using namespace std;

int main()
{
    Logger go;
    go.SetLogLevel(DEBUG);
    go.Debug("please");
    go.Info("god");
    go.Event("end");
    go.Warning("my");
    go.Error("suffering");
    go.Fatal("already");
}
