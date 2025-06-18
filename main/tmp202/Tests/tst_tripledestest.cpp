#include <QTest>
#include <QDebug>
#include "../common/crypto/tripledes.h"
#include "../common/crypto/tripledes.cpp"

class TripleDESTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase(); // Инициализация перед всеми тестами
    void cleanupTestCase(); // Очистка после всех тестов

    void testKeySetting(); // Тест установки ключей
    void testEncryptDecrypt(); // Тест шифрования и дешифрования
    void testBase64Functions(); // Тест функций с Base64
    void testRandomKeyGeneration(); // Тест генерации случайных ключей
    void testEmptyData(); // Тест с пустыми данными
    void testLargeData(); // Тест с большими данными

private:
    TripleDES *des;
    QByteArray key1;
    QByteArray key2;
    QByteArray key3;
};

void TripleDESTest::initTestCase()
{
    des = new TripleDES();

    // Фиксированные ключи для тестирования
    key1 = QByteArray::fromHex("0123456789ABCDEF");
    key2 = QByteArray::fromHex("FEDCBA9876543210");
    key3 = QByteArray::fromHex("89ABCDEF01234567");

    des->setKeys(key1, key2, key3);
}

void TripleDESTest::cleanupTestCase()
{
    delete des;
}

void TripleDESTest::testKeySetting()
{
    // Проверяем, что ключи установлены правильно
    QCOMPARE(des->generateRandomKey().size(), 8); // Проверка размера случайного ключа

    // Проверяем обработку коротких ключей
    TripleDES shortKeyDes;
    shortKeyDes.setKeys("short1", "short2", "short3");
    // Должны быть дополнены нулями до 8 байт
    QByteArray encrypted = shortKeyDes.encrypt("test");
    QVERIFY(!encrypted.isEmpty());
}

void TripleDESTest::testEncryptDecrypt()
{
    // Простая строка для тестирования
    QByteArray original = "Test message for TripleDES encryption";

    // Шифруем
    QByteArray encrypted = des->encrypt(original);
    QVERIFY(!encrypted.isEmpty());
    QVERIFY(encrypted != original);

    // Дешифруем
    QByteArray decrypted = des->decrypt(encrypted);
    QCOMPARE(decrypted.left(original.size()), original); // Обрезаем возможные нули дополнения

    // Проверяем, что шифрование детерминировано (с одинаковыми ключами дает одинаковый результат)
    QByteArray encrypted2 = des->encrypt(original);
    QCOMPARE(encrypted, encrypted2);
}

void TripleDESTest::testBase64Functions()
{
    QString originalText = "Тестовая строка с русскими символами и цифрами 12345!";

    // Шифруем в Base64
    QString encrypted = des->encryptToBase64(originalText);
    QVERIFY(!encrypted.isEmpty());
    QVERIFY(encrypted != originalText);

    // Дешифруем из Base64
    QString decrypted = des->decryptFromBase64(encrypted);
    QCOMPARE(decrypted, originalText);

    // Тест с пустой строкой
    QString emptyEncrypted = des->encryptToBase64("");
    QString emptyDecrypted = des->decryptFromBase64(emptyEncrypted);
    QVERIFY(emptyDecrypted.isEmpty());
}

void TripleDESTest::testRandomKeyGeneration()
{
    QByteArray key1 = TripleDES::generateRandomKey();
    QByteArray key2 = TripleDES::generateRandomKey();

    QCOMPARE(key1.size(), 8);
    QCOMPARE(key2.size(), 8);
    QVERIFY(key1 != key2); // С высокой вероятностью ключи должны быть разными
}

void TripleDESTest::testEmptyData()
{
    // Тест с пустыми данными
    QByteArray empty;
    QByteArray encryptedEmpty = des->encrypt(empty);
    QByteArray decryptedEmpty = des->decrypt(encryptedEmpty);
    QVERIFY(decryptedEmpty.isEmpty());
}

void TripleDESTest::testLargeData()
{
    // Тест с большими данными (больше одного блока)
    QByteArray largeData;
    for (int i = 0; i < 1000; ++i) {
        largeData.append(static_cast<char>(i % 256));
    }

    QByteArray encryptedLarge = des->encrypt(largeData);
    QByteArray decryptedLarge = des->decrypt(encryptedLarge);
    QCOMPARE(decryptedLarge.left(largeData.size()), largeData); // Обрезаем возможные нули дополнения
}

QTEST_APPLESS_MAIN(TripleDESTest)
#include "tst_tripledestest.moc"
