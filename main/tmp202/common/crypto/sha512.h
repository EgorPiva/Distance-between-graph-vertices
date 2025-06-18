/**
 * @file sha512.h
 * @brief SHA-512 cryptographic hash function implementation
 * @author Your Name
 * @date 2023
 */

#ifndef SHA512_H
#define SHA512_H

#include <QByteArray>
#include <QString>

/**
 * @class SHA512
 * @brief Implements the SHA-512 cryptographic hash function
 * 
 * This class provides methods to compute SHA-512 hashes of strings or raw data.
 * SHA-512 produces a 512-bit (64-byte) hash value, typically rendered as a 
 * hexadecimal number, 128 digits long.
 */
class SHA512 {
public:
    /**
     * @brief Default constructor
     */
    SHA512();

    // Вычисляет хеш SHA-512 для данных
    static QByteArray hash(const QByteArray &data);

    // Вычисляет хеш SHA-512 для строки и возвращает его в виде hex-строки
    static QString hashString(const QString &text);

    // Проверяет, соответствует ли строка заданному хешу
    static bool verify(const QString &text, const QString &hashHex);
};

#endif // SHA512_H
