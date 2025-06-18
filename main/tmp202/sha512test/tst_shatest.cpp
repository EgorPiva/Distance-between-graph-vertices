#include <QTest>
#include <QDebug>
#include "../common/crypto/sha512.h"
#include "../common/crypto/sha512.cpp"

class shatest : public QObject
{
    Q_OBJECT

private slots:
    void testEmptyString();
    void testSimpleString();
    void testBinaryData();
    void testVerifyCorrect();
    void testVerifyIncorrect();
    void testHashConsistency();
};

void shatest::testEmptyString()
{
    QByteArray result = SHA512::hash("");
    QString hexResult = SHA512::hashString("");

    // SHA-512 hash of empty string
    const QString expected = "cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce"
                             "47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e";

    QCOMPARE(hexResult.toLower(), expected);
    QCOMPARE(result.toHex().toLower(), expected);
}

void shatest::testSimpleString()
{
    QString input = "hello world";
    QString hexResult = SHA512::hashString(input);

    const QString expected = "309ecc489c12d6eb4cc40f50c902f2b4d0ed77ee511a7c7a9bcd3ca86d4cd86f"
                             "989dd35bc5ff499670da34255b45b0cfd830e81f605dcf7dc5542e93ae9cd76f";

    QCOMPARE(hexResult.toLower(), expected);
}

void shatest::testBinaryData()
{
    QByteArray data;
    data.append(0x01);
    data.append(0x02);

    QByteArray result = SHA512::hash(data);
    QString hexResult = result.toHex();

    const QString expected = "27864cc5219a951a7a6e52b8c8dddf6981d098da1658d96258c870b2c88dfbcb"
                             "51841aea172a28bafa6a79731165584677066045c959ed0f9929688d04defc29";

    QCOMPARE(hexResult.toLower(), expected);
}

void shatest::testVerifyCorrect()
{
    QString text = "password123";
    QString hash = SHA512::hashString(text);

    QVERIFY(SHA512::verify(text, hash));
}

void shatest::testVerifyIncorrect()
{
    QString text = "password123";
    QString wrongText = "password124";
    QString hash = SHA512::hashString(text);

    QVERIFY(!SHA512::verify(wrongText, hash));
}

void shatest::testHashConsistency()
{
    QString text = "test consistency";
    QString hash1 = SHA512::hashString(text);
    QString hash2 = SHA512::hashString(text);

    QCOMPARE(hash1, hash2);
}

QTEST_APPLESS_MAIN(shatest)

#include "tst_shatest.moc"
