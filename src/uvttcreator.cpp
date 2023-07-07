#include "uvttcreator.h"

#include <QFile>
#include <QByteArray>
#include <QImage>
#include <QJsonDocument>
#include <QJsonObject>

extern "C"
{
    Q_DECL_EXPORT ThumbCreator *new_creator() {
        return new UvttCreator();
    }
}

UvttCreator::UvttCreator() { }

UvttCreator::~UvttCreator() { }

bool UvttCreator::create(const QString &path, int w, int h, QImage &img) {
    QFile uvttFile(path);
    uvttFile.open(QIODevice::ReadOnly);

    QByteArray uvttData = uvttFile.readAll();
    QJsonDocument uvttDoc = QJsonDocument::fromJson(uvttData);
    const QJsonValue image = uvttDoc.object()["image"];
    QByteArray imageData = QByteArray::fromBase64(image.toString().toUtf8());
    img.loadFromData(imageData);
    img = img.scaled(w,h);
    return true;
}

ThumbCreator::Flags UvttCreator::flags() const {
    return None;
}
