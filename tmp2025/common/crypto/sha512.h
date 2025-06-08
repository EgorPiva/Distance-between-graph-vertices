#ifndef SHA512_H
#define SHA512_H

#include <QByteArray>
#include <QString>

class SHA512 {
public:
    SHA512();

    // Вычисляет хеш SHA-512 для данных
    static QByteArray hash(const QByteArray &data);

    // Вычисляет хеш SHA-512 для строки и возвращает его в виде hex-строки
    static QString hashString(const QString &text);

    // Проверяет, соответствует ли строка заданному хешу
    static bool verify(const QString &text, const QString &hashHex);
};

#endif // SHA512_H
