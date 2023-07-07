
#ifndef _UVTT_CREATOR_H_
#define _UVTT_CREATOR_H_

#include <QObject>
#include <kio/thumbcreator.h>

class UvttCreator : public QObject, public ThumbCreator
{
    Q_OBJECT
public:
    UvttCreator();
    virtual ~UvttCreator();
    virtual bool create(const QString &path, int w, int h, QImage &thumb) override;
    virtual Flags flags() const override;
};

#endif // _UVTT_CREATOR_H_
