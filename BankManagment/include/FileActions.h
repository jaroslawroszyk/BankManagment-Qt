//#ifndef FILEACTIONS_H
//#define FILEACTIONS_H
#pragma once

class FileActions
{
public:
    virtual void on_actionExit_triggered() = 0;
    virtual void on_actionAbout_triggered() = 0;
};

//#endif // FILEACTIONS_H
