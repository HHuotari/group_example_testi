#ifndef MYURL_H
#define MYURL_H


#include <QString>


class MyUrl
{
public:
    MyUrl();

    const QString getBase_url() const;

private:
    QString base_url;
};

#endif // MYURL_H
