#ifndef MCX8316A_H
#define MCX8316A_H

#include <qstring.h>

class mcx8316a
{
public:
    mcx8316a();
    QString doTi();
    void AddTiConfigLine(QString &line,QString id, QString val);

};

#endif // MCX8316A_H
