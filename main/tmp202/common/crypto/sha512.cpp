#include "sha512.h"
#include <QCryptographicHash>

SHA512::SHA512() {
    // Пустой конструктор
}

QByteArray SHA512::hash(const QByteArray &data) {
    // Используем встроенную реализацию SHA-512 из Qt
    return QCryptographicHash::hash(data, QCryptographicHash::Sha512);
}

QString SHA512::hashString(const QString &text) {
    QByteArray data = text.toUtf8();
    QByteArray hashResult = hash(data);
    return hashResult.toHex();
}

bool SHA512::verify(const QString &text, const QString &hashHex) {
    QString calculatedHash = hashString(text);
    return (calculatedHash.compare(hashHex, Qt::CaseInsensitive) == 0);
}
